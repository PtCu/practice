#include "BST.hpp"
#define Balanced(x) (stature((x).lc)==stature((x).rc) //理想平衡条件
#define BalFac(x) (stature((x).lc) - stature((x).rc)) //平衡因子
#define AvlBalanced(x) ((-2 < BalFac(x)) && (BalFac(x) < 2)) //AVL平衡条件

//在左右孩子中取更高者，若等高，则与父亲p同侧者优先
#define tallerChild(x) ( \
    stature((x)->lc) > stature((x)->rc) ? (x)->lc : (stature((x)->rc) > stature((x)->lc) ? (x)->rc : (IsLChild(*(x)) ? (x)->lc : (x)->rc)))
template <typename T>
class AVL : public BST<T>
{

public:
    BinNodePosi(T) insert(const T &e);
    bool remove(const T &e);
};

template <typename T> //O(logn)
BinNodePosi(T) AVL<T>::insert(const T &e)
{                                  //将关键码e插入avl树中
    BinNodePosi(T) &x = search(e); //search后_hot指向待插入节点的父亲
    if (x)
        return x;
    x = new BinNode<T>(e, _hot); //创建节点x，此后，其父_hot可能增高（父亲不会失衡），祖父可能失衡
    _size++;
    for (BinNodePosi(T) g = _hot; g; g = g->parent) //从x之父出发向上，逐层检查各代祖先g
    {
        if (!AvlBalanced(*g)) //一旦发现g失衡，则采用3+4算法使之平衡
        {
            FromParentTo(*g) = rotateAt(tallerChild(tallerChild(g))); //找到g的最高孙子，在孙子处旋转。将该子树联志原父亲
            break;                                                    //insert复衡后，局部子树高度必然复原，其祖先也是。可以提前结束                                           //复衡后，局部子树高度必然复原，其祖先亦必如此
        }
        else //否则，g依然平衡
            updateHeight(g);
    }
    return x;
} //无论e是否存在于原树中，返回时总有x->data==e

template <typename T>
bool AVL<T>::remove(const T &e)
{
    BinNodePosi(T) &x = search(e); //search后_hot指向待删除节点的父亲
    if (!x)
        return false;
    removeAt(x, _hot); //先按BST规则删除，此后原节点之父_hot及其祖先均可能失衡
    _size--;
    for (BinNodePosi(T) g = _hot; g; g->parent)
    {
        if (!AvlBalanced(*g))
            g = FromParentTo(*g) = rotateAt(tallerChild(tallerChild(g)));
        updateHeight(g); //更新其高度。即便g未平衡，高度亦可能降低。不能提前结束
    }                    //可能需做Omega(logn)次调整——无论是否做过调整，全树高度均可能降低
    return true;
}
//返回局部的最高节点（中间的那个节点）
template <typename T>
BinNodePosi(T) BST<T>::connect34(
    BinNodePosi(T) a, BinNodePosi(T) b, BinNodePosi(T) c, BinNodePosi(T) T0, BinNodePosi(T) T1, BinNodePosi(T) T2, BinNodePosi(T) T3)
{
    a->lc = T0;
    if (T0)
        T0->parent = a;
    a->rc = T1;
    if (T1)
        T1->parent = a;
    updateHeight(a);
    c->lc = T2;
    if (T2)
        T2->parent = c;
    c->rc = T3;
    if (T3)
        T3->parent = c;
    updateHeight(c);
    b->rc = c;
    c->parent = b;
    b->lc = a;
    a->parent = b;
    updateHeight(b);
    return b;
}
template <typename T>
BinNodePosi(T) BST<T>::rotateAt(BinNodePosi(T) v)
{ //v为非空的孙辈节点
    BinNodePosi(T) p = v->parent;
    BinNodePosi(T) g = p->parent; //视v,p和g相对位置分四种情况
    if (IsLChild(*p))             //zig
    {
        if (IsLChild(*v)) //zig-zig
        {
            p->parent = g->parent;
            return connect34(v, p, g, v->lc, v->rc, p->rc, g->rc);
        }
        else //zig-zag
        {
            v->parent = g->parent;
            return connect34(p, v, g, p->lc, v->lc, v->rc, g->rc);
        }
    }
    else //zag
    {
        if (IsLChild(*v)) //zag-zig
        {
            v->parent = g->parent;
            return connect34(g, v, p, g->lc, v->lc, v->rc, p->rc);
        }
        else //zag-zag
        {
            p->parent = g->parent;
            return connect34(g, p, v, g->lc, p->lc, v->lc, v->rc);
        }
    }
}