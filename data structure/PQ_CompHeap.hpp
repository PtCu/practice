#pragma once
#include "Vector.hpp"
#include "PQ.hpp"

#define Parent(i) (((i)-1) >> 1)                                                                                               //PQ[i]的父节点（floor((i-1)/2)，i无论正负）
#define LChild(i) (1 + ((i) << 1))                                                                                             //PQ[i]的左孩子
#define RChild(i) ((1 + (i)) << 1)                                                                                             //PQ[i]的右孩子
#define InHeap(n, i) (((-1) < (i)) && ((i) < (n)))                                                                             //判断PQ[i]是否合法
#define LChildValid(n, i) InHeap(n, LChild(i))                                                                                 //判断PQ[i]是否有一个（左）孩子
#define RChildValid(n, i) InHeap(n, RChild(i))                                                                                 //判断PQ[i]是否有两个孩子
#define Bigger(PQ, i, j) (lt(PQ[i], PQ[j]) ? j : i)                                                                            //取大者（等时前者优先）
#define ProperParent(PQ, n, i)                                                                                                 /*父子（至多）三者中的大者*/ \
    (RChildValid(n, i) ? Bigger(PQ, Bigger(PQ, i, LChild(i)), RChild(i)) : (LChildValid(n, i) ? Bigger(PQ, i, LChild(i)) : i)) //相等时父节点优先，如此可避免不必要的交换

template <typename T>
class PQ_ComplHeap : public PQ<T>, public Vector<T>
{
protected:
    template <typename T>
    Rank percolateDown(Rank n, Rank i); //下滤

    template <typename T>
    Rank percolateUp(Rank i); //上滤

    template <typename T>
    void heapify(Rank n); //Floyd建堆算法

public:
    PQ_ComplHeap(T *A, Rank n) //批量构造
    {
        copyFrom(A, 0, n);
        heapify(_elem, n);
    }
    void insert(T);
    T getMax() { return _elem[0]; } //读取优先级最高的词条
    T delMax();                     //删除优先级最高的词条
};

template <typename T>
void PQ_ComplHeap<T>::insert(T e)
{
    Vector<T>::insert(e);
    percolateUp(e);
}
template <typename T>
Rank PQ_ComplHeap<T>::percolateUp(Rank i)
{
    //3logn版本
    // while (0 < i)
    // {
    //     Rank j = Parent(i);
    //     if (_elem[i] < _elem[j])
    //         break; //一旦父子不再逆序，上滤即完成
    //     swap(_elem[i], _elem[j]);
    //     i = j; //否则交换父子位置并上升一层
    // }
    // return i;

    //logn+1版本
    T tmp = _elem[i];
    while (0 < i)
    {
        Rank j = Parent(i);
        if (tmp < _elem[j])
            break;
        _elem[i] = _elem[j];
        i = j;
    }
    _elem[i] = tmp;
}


