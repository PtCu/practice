#include "Stack.hpp"
#include "Queue.hpp"
#include "release.h"
/******************************************************************************************
 * BinNode状态与性质的判断
 ******************************************************************************************/
#define IsRoot(x) (!((x).parent))
#define IsLChild(x) (!IsRoot(x) && (&(x) == (x).parent->lc)) //判断x是不是父结点的左孩子
#define IsRChild(x) (!IsRoot(x) && (&(x) == (x).parent->rc)) //判断x是不是父结点的右孩子
#define HasParent(x) (!IsRoot(x))
#define HasLChild(x) ((x).lc)
#define HasRChild(x) ((x).rc)
#define HasChild(x) (HasLChild(x) || HasRChild(x))     //至少拥有一个孩子
#define HasBothChild(x) (HasLChild(x) && HasRChild(x)) //同时拥有两个孩子
#define IsLeaf(x) (!HasChild(x))

/******************************************************************************************
 * 与BinNode具有特定关系的节点及指针
 ******************************************************************************************/
#define sibling(p) /*兄弟*/ \
    (IsLChild(*(p)) ? (p)->parent->rc : (p)->parent->lc)

#define uncle(x) /*叔叔*/ \
    (IsLChild(*((x)->parent)) ? (x)->parent->parent->rc : (x)->parent->parent->lc)

#define FromParentTo(x) /*来自父亲的引用*/ \
    (IsRoot(x) ? _root : (IsLChild(x) ? (x).parent->lc : (x).parent->rc))

#define BinNodePosi(T) BinNode<T> *
#define stature(p) ((p) ? (p)->height : -1) //节点高度（与“空树高度为-1”的约定相统一）
typedef enum                                //节点颜色
{
    RB_RED,
    RB_BLACK
} RBColor;
template <typename T>
struct BinNode
{
    // 成员（为简化描述起见统一开放，读者可根据需要进一步封装）
    T data; //数值
    BinNodePosi(T) parent;
    BinNodePosi(T) lc;
    BinNodePosi(T) rc; //父节点及左、右孩子
    int height;        //高度（通用）
    int npl;           //Null Path Length（左式堆，也可直接用height代替）
    RBColor color;     //颜色（红黑树）
                       // 构造函数
    BinNode() : parent(NULL), lc(NULL), rc(NULL), height(0), npl(1), color(RB_RED) {}
    BinNode(T e, BinNodePosi(T) p = NULL, BinNodePosi(T) lc = NULL, BinNodePosi(T) rc = NULL,
            int h = 0, int l = 1, RBColor c = RB_RED) : data(e), parent(p), lc(lc), rc(rc), height(h), npl(l), color(c) {}
    // 操作接口
    int size();                           //统计当前节点后代总数，亦即以其为根的子树的规模
    BinNodePosi(T) insertAsLC(T const &); //作为当前节点的左孩子插入新节点
    BinNodePosi(T) insertAsRC(T const &); //作为当前节点的右孩子插入新节点
    BinNodePosi(T) succ();                //取当前节点的直接后继
    template <typename VST>
    void travLevel(VST &); //子树层次遍历
    template <typename VST>
    void travPre(VST &); //子树先序遍历
    template <typename VST>
    void travIn(VST &); //子树中序遍历
    template <typename VST>
    void travPost(VST &);                                          //子树后序遍历
                                                                   // 比较器、判等器（各列其一，其余自行补充）
    bool operator<(BinNode const &bn) { return data < bn.data; }   //小于
    bool operator==(BinNode const &bn) { return data == bn.data; } //等于
                                                                   /*DSA*/
    /*DSA*/ BinNodePosi(T) zig();                                  //顺时针旋转
    /*DSA*/ BinNodePosi(T) zag();                                  //逆时针旋转
};

template <typename T>
BinNodePosi(T) BinNode<T>::insertAsLC(T const &e)
{
    return this->lc = new BinNode(e, this);
}

template <typename T>
BinNodePosi(T) BinNode<T>::insertAsRC(T const &e)
{
    return this->rc = new BinNode(e, this);
}

template <typename T>
int BinNode<T>::size()
{
    int s = 1;
    if (lc)
        s += lc->size();
    if (rc)
        s += rc->size();
    return s;
}

template <typename T>
BinNodePosi(T) BinNode<T>::succ()
{                            //定位节点v的中序遍历直接后继
    BinNodePosi(T) s = this; //记录后继的临时变量
    if (rc)
    {
        //若有右孩子，则直接后继必在右子树中
        s = rc;
        while (HasLChild(*s))
            s = s->lc;
    }
    //当v没有右子树时它的后继为某个祖先，具体地说是在沿着parent指针向上的过程中第一次向右的祖先。
    else //否则，直接后继就是当前节点包含于其左子树中的最低祖先
    {
        while (IsRChild(*s)) //逆向地沿右向分支，不断朝左上方移动
        {
            s = s->parent;
        }
        s = s->parent; //最后再朝右上方移动一步，即抵达直接后继
    }
    return s;
}

template <typename T>
template <typename VST> //元素类型、操作器
void BinNode<T>::travPre(VST &visit)
{ //二叉树先序遍历算法统一入口
    switch (rand() % 3)
    { //此处暂随机选择以做测试，共三种选择
    case 1:
        travPre_I1(this, visit);
        break; //迭代版#1
    case 2:
        travPre_I2(this, visit);
        break; //迭代版#2
    default:
        travPre_R(this, visit);
        break; //递归版
    }
}

template <typename T, typename VST>           //元素类型、操作器
void travPre_I1(BinNodePosi(T) x, VST &visit) //二叉树中序遍历算法（迭代版#2）
{
    Stack<BinNodePosi(T)> S;
    if (x)
        S.push(x);
    while (!S.empty())
    {
        BinNodePosi(T) p = S.pop();
        visit(p->data);
        if (HasRChild(*p))
        {
            S.push(p->rc);
        }
        if (HasLChild(*p))
        {
            S.push(p->rc);
        }
    }
}

template <typename T, typename VST>
void travPre_R(BinNodePosi(T) x, VST &visit)
{
    if (x)
        visit(x->data);
    travPre_R(x->lc, visit);
    travPre_R(x->rc, visit);
}

template <typename T, typename VST>
static void visitAlongLeftBranch(BinNodePosi(T) x, VST &visit, Stack<BinNodePosi(T)> &S)
{
    while (x) //反复的
    {
        visit(x->data); //访问当前节点
        S.push(x->rc);  //右孩子入栈（将来逆序出栈）不用判空，下次循环如果判断为空就跳过。否则得不偿失
        x = x->lc;      //沿左侧链下行
    }
}

template <typename T, typename VST>
void travPre_I2(BinNodePosi(T) x, VST &visit)
{ //二叉树先序遍历算法（迭代版#2）
    Stack<BinNodePosi(T)> S;
    while (true)
    {
        visitAlongLeftBranch(x, visit, S); //从当前节点出发，逐批访问
        if (S.empty())                     //栈空则退出
            break;
        x = S.pop();
    }
}

template <typename T>
static void goAlongVine(BinNodePosi(T) x, Stack<BinNodePosi(T)> &S)
{
    while (x)
    {
        S.push(x);
        x = x->lc;
    }
}

template <typename T, typename VST>
void travIn_I1(BinNodePosi(T) x, VST &visit) //二叉树中序遍历算法（迭代版1）
{
    Stack<BinNodePosi(T)> S; //辅助栈
    while (true)
    {
        goAlongVine(x, S); //从当前节点出发，逐批入栈
        if (S.empty())     //直至所有节点处理完毕
            break;
        x = S.pop();    //x无左子树
        visit(x->data); //弹出栈顶节点并访问之
        x = x->rc;      //转向右子树
    }
}
//在以S栈顶节点为根的子树中，找到最深左侧可见叶节点
template <typename T>
static void gotoHLVFL(Stack<BinNodePosi(T)> &S)
{
    while (BinNodePosi(T) x = S.top()) //自顶而下，反复检查当前节点(即栈顶)
    {
        if (HasLChild(*x)) //尽可能的向左
        {
            if (HasRChild(*x))
            {
                S.push(x->rc); //若有右孩子，优先入栈
            }
            S.push(x->lc); //然后才转至左孩子
        }
        else
            S.push(x->rc); //实不得已才向右
    }
    S.pop(); //返回之前，弹出栈顶的空节点(while退出时的空节点栈顶)
}

template <typename T, typename VST>
void travPost_I(BinNodePosi(T) x, VST &visit)
{
    Stack<BinNodePosi(T)> S;
    if (x)
        S.push(x);
    while (!S.empty())
    {
        if (S.top() != x->parent) //若栈顶非当前节点之父（则必为其右兄）
            gotoHLVFL(S);
        x = S.pop();
        visit(x->data); //弹出栈顶（即前一节点之后继），并访问之
    }
}


template <typename T,typename VST>
void travPost_R(BinNodePosi(T) x,VST&visit){
    if(!x)
        return;
    travPost_R(x->lc, visit);
    travPost_R(x->rc, visit);
}

template <typename T>
template <typename VST>
void BinNode<T>::travPost(VST& visit){
    switch (rand()%2)
    {
    case 1:
        travPost_I(this, visit);
        break;
    case 2:
        travPost_R(this, visit);
    default:
        travPost_I(this, visit);
        break;
    }
}

template <typename T, typename VST>
void traIn_I2(BinNodePosi(T) x, VST &visit) //二叉树中序遍历算法（迭代版2）
{
    Stack<BinNodePosi(T)> S; //辅助栈
    while (true)
    {
        if (x)
        {
            S.push(x); //根节点入栈
            x = x->lc; //深入遍历左子树
        }
        else if (!S.empty())
        {                //x为null
            x = S.pop(); //尚未访问的最低祖先节点退栈
            visit(x->data);
            x = x->rc;
        }
        else
            break;
    }
}

template <typename T, typename VST>
void travIn_I3(BinNodePosi(T) x, VST &visit)
{                           //迭代版3，无需辅助栈
    bool backtrack = false; //前一步是否刚从右子树回溯——省去栈，仅O(1)辅助空间
    while (true)
    {
        if (!backtrack && HasLChild(*x)) //若有左子树且不是刚刚回溯
            x = x->lc;                   //深入遍历左子树
        else
        {                   //否则——无左子树或刚刚回溯（相当于无左子树）
            visit(x->data); //访问该结点
            if (HasRChild(*x))
            {                      //若其右子树非空，则
                x = x->rc;         //深入右子树继续遍历
                backtrack = false; //关闭回溯标志
            }
            else //若右子树空
            {
                if (!(x = x->succ())) //回溯（含抵达末节点时的退出返回）
                    break;
                backtrack = true; //设置回溯标志
            }
        }
    }
}
template <typename T, typename VST>
void travIn_R(BinNodePosi(T) x, VST &visit)
{
    if (!x)
        return;
    travIn_R(x, visit);
    visit(x->data);
    travIn_R(x, visit);
}

template <typename T>
template <typename VST>
void BinNode<T>::travIn(VST &visit)
{
    switch (rand() % 3)
    {
    case 1:
        travIn_I1(this, visit);
        break;
    case 2:
        traIn_I2(this, visit);
        break;
    case 3:
        travIn_I3(this, visit);
        break;
    default:
        travIn_R(this, visit);
        break;
    }
}

template <typename T>
template <typename VST>
void BinNode<T>::travLevel(VST &visit)
{
    Queue<BinNodePosi(T)> Q;
    Q.enqueue(this);
    while (!Q.empty())
    {
        BinNodePosi(T) x = Q.dequeue();
        visit(x->data);
        if (HasLChild(*x))
            Q.enqueue(x->lc);
        if (HasRChild(*x))
            Q.enqueue(x->rc);
    }
}

