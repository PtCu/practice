#include "BinNode.hpp"
template <typename T>
class BinTree
{
protected:
    int _size;
    BinNodePosi(T) _root;
    virtual int updateHeight(BinNodePosi(T) x);
    void updateHeightAbove(BinNodePosi(T) x); //更新x及其历代祖先的高度

public:
    BinTree() : _size(0), _root(NULL) {} //构造函数
    ~BinTree()
    {
        if (0 < _size)
            remove(_root);
    } //析构函数
    int size() const { return _size; }
    bool empty() const { return !_root; }
    BinNodePosi(T) root() const { return _root; }
    BinNodePosi(T) insertAsLC(BinNodePosi(T) x, T const &e);     //e作为x的左孩子（原无）插入
    BinNodePosi(T) insertAsRC(BinNodePosi(T) x, T const &e);     //e作为x的右孩子（原无）插入
    BinNodePosi(T) attachAsLC(BinNodePosi(T) x, BinTree<T> *&); //T作为x左子树接入
    BinNodePosi(T) attachAsRC(BinNodePosi(T) x, BinTree<T> *&); //T作为x右子树接入
    int remove(BinNodePosi(T) x);                                //删除以位置x处节点为根的子树，返回该子树原先的规模
    BinTree<T> *secede(BinNodePosi(T) x);                        //将子树x从当前树中摘除，并将其转换为一棵独立子树
    template <typename VST>                                      //操作器
    void travLevel(VST &visit)
    {
        if (_root)
            _root->travLevel(visit);
    }                       //层次遍历
    template <typename VST> //操作器
    void travPre(VST &visit)
    {
        if (_root)
            _root->travPre(visit);
    }                       //先序遍历
    template <typename VST> //操作器
    void travIn(VST &visit)
    {
        if (_root)
            _root->travIn(visit);
    }                       //中序遍历
    template <typename VST> //操作器
    void travPost(VST &visit)
    {
        if (_root)
            _root->travPost(visit);
    }                                   //后序遍历
    bool operator<(BinTree<T> const &t) //比较器（其余自行补充）
    {
        return _root && t._root && lt(_root, t._root);
    }
    bool operator==(BinTree<T> const &t) //判等器
    {
        return _root && t._root && (_root == t._root);
    }
};

//更新节点x高度，具体规则因树不同而异
//此处采用常规二叉树规则，O(1)
template <typename T>
int BinTree<T>::updateHeight(BinNodePosi(T) x)
{
    return x->height = 1 + max(stature(x->lc), stature(x->rc));
}

//更新x及其历代祖先的高度
template <typename T>
void BinTree<T>::updateHeightAbove(BinNodePosi(T) x)
{
    while (x) //可优化，一旦高度未变，即可终止
    {
        updateHeight(x);
        x = x->parent;
    } //O(n=depth(x))
}

template <typename T>
BinNodePosi(T) BinTree<T>::insertAsLC(BinNodePosi(T) x, T const &e)
{
    _size++;
    x->insertAsLC(e); //祖先高度可能增加，其余节点必然不变
    updateHeightAbove(x);
    return x->lc;
}
template <typename T>
BinNodePosi(T) BinTree<T>::insertAsRC(BinNodePosi(T) x, T const &e)
{
    _size++;
    x->insertAsRC(e);
    updateHeightAbove(x);
    return x->rc;
}

//将S当作节点x的左子树接入，S本身置空
template <typename T>
BinNodePosi(T) BinTree<T>::attachAsLC(BinNodePosi(T) x, BinTree<T> *&S)
{
    if (x->lc == S->root)
        x->lc->parent = x; //接入
    _size += S->_size;
    updateHeightAbove(x);
    S->root = nullptr; //释放原树
    S->_size = 0;
    release(S);
    S = nullptr;
    return x; //返回接入位置
}
template <typename T>
BinNodePosi(T) BinTree<T>::attachAsRC(BinNodePosi(T) x, BinTree<T> *&S)
{
    if (x->rc == S->root)
        x->rc->parent = x; //接入
    _size += S->_size;
    updateHeightAbove(x);
    S->root = nullptr; //释放原树
    S->_size = 0;
    release(S);
    S = nullptr;
    return x; //返回接入位置
}

template <typename T>
int BinTree<T>::remove(BinNodePosi(T) x)
{
    FromParentTo(*x) = nullptr;
    updateHeightAbove(x->parent);
    int n = removeAt(x);
    _size -= n;
    return n; //删除子树x，更新规模，返回删除节点总数
}

template <typename T>
static int removeAt(BinNodePosi(T) x)
{
    if (!x)
        return 0;
    int n = 1 + removeAt(x->lc) + removeAt(x->rc);
    release(x->data);
    release(x);
    return n;
}

template <typename T>
BinTree<T> *BinTree<T>::secede(BinNodePosi(T) x)
{
    FromParentTo(*x) = nullptr; //切断来自父亲节点的指针
    updateHeightAbove(x->parent);
    BinTree<T> *S = new BinTree<T>;
    S->_root = x;
    x->parent = nullptr;
    S->size() = x->size();
    _size -= S->_size;
    return S;
}
