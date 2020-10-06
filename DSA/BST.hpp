#include "BinTree.hpp"

template <typename T>
class BST : public BinTree<T>
{ //由BinTree派生BST模板类
protected:
    BinNodePosi(T) _hot;      //“命中”节点的父亲
    BinNodePosi(T) connect34( //按照“3 + 4”结构，联接3个节点及四棵子树
        BinNodePosi(T), BinNodePosi(T), BinNodePosi(T),
        BinNodePosi(T), BinNodePosi(T), BinNodePosi(T), BinNodePosi(T));
    BinNodePosi(T) rotateAt(BinNodePosi(T) x);             //对x及其父亲、祖父做统一旋转调整
public:                                                    //基本接口：以virtual修饰，强制要求所有派生类（BST变种）根据各自的规则对其重写
    virtual BinNodePosi(T) & search(const T &e);           //查找
    virtual BinNodePosi(T) insert(const T &e);             //插入
    virtual bool remove(const T &e);                       //删除
                                                           /*DSA*/
    /*DSA*/ void stretchToLPath() { stretchByZag(_root); } //借助zag旋转，转化为左向单链
    /*DSA*/ void stretchToRPath() { stretchByZig(_root); } //借助zig旋转，转化为右向单链
    /*DSA*/ void stretch();
    /*DSA*/ void imitate(const BST<T> &); //临摹
};

//在以v为根的BST子树中查找关键码e
template <typename T>
    static BinNodePosi(T) & searchIn(BinNodePosi(T) & v, const T &e, BinNodePosi(T) & hot)
{
    if (!v || (e == v->data)) //返回时，返回值指向命中节点（或假想的哨兵）
        return v;
    hot = v; //一般情况下，先记下当前节点
    return searchIn(((e < v->data) ? v->lc : v->rc), e, hot);
} //返回时，返回值指向命中节点（或假想的哨兵），hot指向其父亲（退化时为初始值null）
template <typename T>
    BinNodePosi(T) & BST<T>::search(const T &e)
{
    return searchIn(_root, e, _hot = NULL);
}

template <typename T>
BinNodePosi(T) BST<T>::insert(const T &e)
{
    BinNodePosi(T) x = search(e);
    if (x)
        return x; //如果待插入位置有节点了就返回
    x = new BinNode<T>(e);
    updateHeightAbove(x); //更新x及其祖先的高度
    return x;
} //无论e是否存在于原树中，返回时总有x->data==e

/******************************************************************************************
 * BST节点删除算法：删除位置x所指的节点（全局静态模板函数，适用于AVL、Splay、RedBlack等各种BST）
 * 目标x在此前经查找定位，并确认非NULL，故必删除成功；与searchIn不同，调用之前不必将hot置空
 * 返回值指向实际被删除节点的接替者，hot指向实际被删除节点的父亲——二者均有可能是NULL
 ******************************************************************************************/
//返回实际被删除节点的替代者
template <typename T>
static BinNodePosi(T) removeAt(BinNodePosi(T) & x, BinNodePosi(T) & hot)
{   
    //w作为实际被删除的节点，必有一个孩子为null
    BinNodePosi(T) w = x;       //实际被删除的节点
    BinNodePosi(T) succ = NULL; //实际被删除的节点的后继
    if(!HasLChild(x))
        succ = x = x->rc;
    else if(!HasRChild(x))
        succ = x = x->lc;
    else
    {
        w = w->succ(); //找到直接后继
        swap(x->data, w->data); //交换数据
        BinNodePosi(T) u = w->parent;   //w的父结点
        //将w隔离   按w的父结点是不是x来分类
        ((u == x) ? u->rc : u->lc) = succ = w->rc;  //实际被删除的节点的后继
    }
    hot = w->parent;
    if(succ)
        succ->parent = hot; //将删除节点的后继和删除节点的父亲接上
    release(w->data);   //删除w及其数据
    release(w);
    return succ;
}
template <typename T>
bool BST<T>::remove(const T &e)
{
    BinNodePosi(T) &x = search(e);
    if(!x)  //如果不存在就返回失败
        return false;
    removeAt(x, _hot);
    _size--;
    updateHeightAbove(_hot);    //更新_hot及其历代祖先的高度。高度是从最底层向上计算的，深度相反
    return true;
}
