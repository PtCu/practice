#include "BinTree.hpp"
#include "PQ.hpp"
template <typename T>
class PQ_LeftHeap : public PQ<T>, public BinTree<T>
{
private:
    /* data */
public:
    PQ_LeftHeap() {}
    PQ_LeftHeap(T *E, int n)
    {
        for (int i = 0; i < n; ++i)
            insert(E[n]);
    }
    ~PQ_LeftHeap();
    T getMax() { return _root->data; }
    void insert(T);
    T delMax();
};

template <typename T>
static BinNodePosi(T) merge(BinNodePosi(T) a, BinNodePosi(T) b)
{
    if (!a)
        return b;
    if (!b)
        return a;             //递归基
    if (lt(a->data, b->data)) //确保b作为a的子树
        swap(a, b);
    (a->rc = merge(a->rc, b))->parent = a; //将a的右子堆，与b合并
    if (!a->lc || a->lc->npl < a->rc->npl) //若有必要
        swap(a->lc, a->rc);                //交换a的左、右子堆，以确保右子堆的npl不大
    a->npl = a->rc ? a->rc->npl + 1 : 1;   //更新a的npl
    return a;                              //返回合并后的堆顶

} //本算法只实现结构上的合并，堆的规模须由上层调用者负责更新

template<typename T>
T PQ_LeftHeap<T>::delMax(){
    BinNodePosi(T) lHeap = _root->lc;
    lHeap->parent = NULL;
    BinNodePosi(T) rHeap = _root->rc;
    rHeap->parent = NULL;
    T e = _root - data;
    delete _root;
    _size--;
    _root=merge(lHeap, rHeap);
    return e;
}
template<typename T>
void PQ_LeftHeap<T>::insert(T e){
    _root = merge(_root, new BinNode<T>(e,NULL)); //将e封装为左式堆，与当前左式堆合并
    ++_size;//更新规模
}