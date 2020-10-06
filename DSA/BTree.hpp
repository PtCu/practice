#include "BTNode.hpp"
template <typename T>
class BTree
{ //B-树模板类
protected:
    int _size;                          //存放的关键码总数
    int _order;                         //B-树的阶次，至少为3——创建时指定，一般不能修改  m阶-m路
    BTNodePosi(T) _root;                //根节点
    BTNodePosi(T) _hot;                 //BTree::search()最后访问的非空（除非树空）的节点位置
    void solveOverflow(BTNodePosi(T));  //因插入而上溢之后的分裂处理
    void solveUnderflow(BTNodePosi(T)); //因删除而下溢之后的合并处理
public:
    BTree(int order = 3) : _order(order), _size(0) //构造函数：默认为最低的3阶
    {
        _root = new BTNode<T>();
    }
    ~BTree()
    {
        if (_root)
            release(_root);
    }                                        //析构函数：释放所有节点
    int const order() { return _order; }     //阶次
    int const size() { return _size; }       //规模
    BTNodePosi(T) & root() { return _root; } //树根
    bool empty() const { return !_root; }    //判空
    BTNodePosi(T) search(const T &e);        //查找
    bool insert(const T &e);                 //插入
    bool remove(const T &e);                 //删除
};                                           //BTree

template <typename T>
BTNodePosi(T) BTree<T>::search(const T &e)
{
    BTNodePosi(T) v = _root;
    _hot = NULL; //从根节点出发
    while (v)    //逐层查找
    {
        Rank r = v->key.search(e); //在当前节点中，找到不大于e的最大关键码
        if ((0 <= r) && (e == v->key[r]))
            return v; //成功：在当前节点中命中目标关键码
        _hot = v;
        v = v->child[r + 1]; //否则，转入对应的子树(_hot指向其父)——需做I/O，最费时间
    }
    return NULL; //失败，最终抵达外部节点
}

template <typename T>
bool BTree<T>::insert(const T &e)
{
    BTNodePosi(T) v = search(e);
    if (v)                           //确认目标节点不存在
        return false;                //禁止重复插入
    Rank r = _hot->key.search(e);    //在节点_hot的有序关键码向量中查找合适的插入位置
    _hot->key.insert(r + 1, e);      //将新关键码插至对应的位置（注意是插入到_hot节点中，可能会造成上溢）
    _hot->child.insert(r + 2, NULL); //创建一个空子树指针（相当于插入到右子树的位置）比关键码多一
    _size++;
    solveOverflow(_hot); //如有必要，需做分裂
    return true;         //插入成功
}

template <typename T>
void BTree<T>::solveOverflow(BTNodePosi(T) v)
{
    if (_order >= v->child.size()) //递归基：当前节点并未上溢
        return;
    Rank s = _order / 2; //轴点(此时应有_order=key.size()=child.size()-1)

    //创建右子树
    BTNodePosi(T) u = new BTNode<T>();        //注意：新节点已有一个空孩子，位于最左侧
    for (Rank j = 0; j < _order - s - 1; j++) //右侧的_order-s-1个孩子及关键码分裂为右侧节点u
    {
        u->child.insert(j, v->child.remove(s + 1)); //逐个移动（逐个删除）效率低。刚开始的空孩子（最左侧）被顶替
        u->key.insert(j, v->key.remove(s + 1));     //此策略可改进
    }
    u->child[_order - s - 1] = v->child.remove(s + 1); //移动v最靠右的孩子成为u的最右孩子

    if (u->child[0])                          //若u的孩子们非空，则
        for (Rank j = 0; j < _order - s; j++) //将他们的父结点统一
            u->child[j]->parent = u;          //指向u

    //确定父结点
    BTNodePosi(T) p = v->parent; //v当前的父结点p
    if (!p)                      //若p为空则创建之
    {
        _root = p = new BTNode<T>();
        p->child[0] = v;
        v->parent = p;
    }

    //与父结点连接
    Rank r = 1 + p->key.search(v->key[0]); //p中指向u的指针的秩
    p->key.insert(r, v->key.remove(s));    //轴点关键码上升
    p->child.insert(r + 1, u);             //新节点u于父结点p互联
    solveOverflow(p);                      //上升一层，如有必要继续分裂——至多递归O(logn)层
}

template <typename T>
bool BTree<T>::remove(const T &e)
{
    BTNodePosi(T) v = search(e);
    if (!v)
        return false;          //确认目标关键码存在
    Rank r = v->key.search(e); //确定目标关键码在节点v中的秩（肯定合法）
    if (v->child[0])           //若非叶子，则e的后继必属于某叶节点
    {
        BTNodePosi(T) u = v->child[r + 1]; //在右子树中一直向左，即可
        while (u->child[0])                //找出e的后继
            u = u->child[0];
        v->key[r] = u->key[0]; //并与之交换位置
        v = u;
        r = 0;
    }
    v->key.remove(r); //删除e，以及其下两个外部节点之一
    v->child.remove(r + 1);
    _size--;
    solveUnderflow(v); //如有必要需要旋转或合并
    return true;
}

template <typename T>
void BTree<T>::solveUnderflow(BTNodePosi(T) v)
{       //(order+1)/2相当于m/2的上取整
    if ((_order + 1) / 2 <= v->child.size()) //递归基：当前节点并未下溢
        return;
    BTNodePosi(T) p = v->parent;
    if (!p)
    {
        if (!v->key.size() && v->child[0])  //倘若作为树根的v已不含关键码，却有（唯一的）非空孩子
        {
            _root = v->child[0];     //拷贝非空孩子
            _root->parent = NULL;   //这个节点可被跳过
            v->child[0] = NULL;
            release(v); //并因不再有用而被销毁
        } //整树高度降低一层
        return;
    }
    Rank r = 0;
    while (p->child[r] != v) //确定v是p的第r个孩子——此时v可能不含关键码，故不能通过关键码查找
        r++;                 //另外，在实现了孩子指针的判等器之后，也可直接调用Vector::find()定位

    // 情况1：向左兄弟借关键码
    if (0 < r)
    {                                       //若v不是p的第一个孩子，则
        BTNodePosi(T) ls = p->child[r - 1]; //左兄弟必存在
        if ((_order + 1) / 2 < ls->child.size())
        { //若该兄弟足够“胖”，则
            v->key.insert(0, p->key[r - 1]);   //将父结点中v和左兄弟之间的关键码取出              //p借出一个关键码给v（作为最小关键码）
            p->key[r - 1] = ls->key.remove(ls->key.size() - 1); //ls的最大关键码转入p
            v->child.insert(0, ls->child.remove(ls->child.size() - 1)); //同时ls的最右侧孩子过继给v
            if (v->child[0])
                v->child[0]->parent = v; //作为v的最左侧孩子
            return;                      //至此，通过右旋已完成当前层（以及所有层）的下溢处理
        }
    } //至此，左兄弟要么为空，要么太“瘦”

      // 情况2：向右兄弟借关键码
    if (p->child.size() - 1 > r)
    {                                       //若v不是p的最后一个孩子，则
        BTNodePosi(T) rs = p->child[r + 1]; //右兄弟必存在
        if ((_order + 1) / 2 < rs->child.size())
        { //若该兄弟足够“胖”，则
            v->key.insert(v->key.size(), p->key[r]); //p借出一个关键码给v（作为最大关键码）
            p->key[r] = rs->key.remove(0);           //ls的最小关键码转入p
            v->child.insert(v->child.size(), rs->child.remove(0));
            //同时rs的最左侧孩子过继给v
            if (v->child[v->child.size() - 1]) //作为v的最右侧孩子
                v->child[v->child.size() - 1]->parent = v;
            return; //至此，通过左旋已完成当前层（以及所有层）的下溢处理
        }
    } //至此，右兄弟要么为空，要么太“瘦”
    
      // 情况3：左、右兄弟要么为空（但不可能同时），要么都太“瘦”——合并
    if (0 < r)
    { //与左兄弟合并
        BTNodePosi(T) ls = p->child[r - 1]; //左兄弟必存在
        ls->key.insert(ls->key.size(), p->key.remove(r - 1)); //将父亲节点p的第r - 1个关键码（左兄弟和v之间的关键码）转入ls
        p->child.remove(r);                                   //取消对v的引用,v不再是p的第r个孩子
        ls->child.insert(ls->child.size(), v->child.remove(0));
        if (ls->child[ls->child.size() - 1]) //v的最左侧孩子过继给ls做最右侧孩子
            ls->child[ls->child.size() - 1]->parent = ls;
        while (!v->key.empty())
        { //v剩余的关键码和孩子，依次转入ls
            ls->key.insert(ls->key.size(), v->key.remove(0));
            ls->child.insert(ls->child.size(), v->child.remove(0));
            if (ls->child[ls->child.size() - 1])    //insert后向量长度加一，所以取ls->child.siez()-1，即为刚插入的元素
                ls->child[ls->child.size() - 1]->parent = ls;
        }
        release(v); //释放v
    }
    else
    { //与右兄弟合并
        BTNodePosi(T) rs = p->child[r + 1]; //右兄弟必存在
        rs->key.insert(0, p->key.remove(r));
        p->child.remove(r);
        //p的第r个关键码转入rs，v不再是p的第r个孩子
        rs->child.insert(0, v->child.remove(v->child.size() - 1));
        if (rs->child[0])
            rs->child[0]->parent = rs; //v的最左侧孩子过继给ls做最右侧孩子
        while (!v->key.empty())
        { //v剩余的关键码和孩子，依次转入rs
            rs->key.insert(0, v->key.remove(v->key.size() - 1));
            rs->child.insert(0, v->child.remove(v->child.size() - 1));
            if (rs->child[0])
                rs->child[0]->parent = rs;
        }
        release(v); //释放v
    }
    solveUnderflow(p); //上升一层，如有必要则继续分裂——至多递归O(logn)层
    return;
}
