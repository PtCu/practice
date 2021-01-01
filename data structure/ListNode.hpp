#pragma once
#define ListNodePosi(T) ListNode<T> * //列表节点位置
typedef int Rank;
template <typename T>
//与类有一个区别在于，struct中定义的函数和变量都是默认为public的，但class中的则是默认为private。
struct ListNode
{
    //成员
    T data;               //数值
    ListNodePosi(T) pred; //前驱
    ListNodePosi(T) succ; //后继
    //构造函数
    ListNode() {}         //针对header和tailer的构造
    ListNode(T e, ListNodePosi(T) p = nullptr, ListNodePosi(T) s = nullptr) : data(e), pred(p), succ(s) {}
    //操作接口
    ListNodePosi(T) insertAsPred(T const &e); //前插入
    ListNodePosi(T) insertAsSucc(T const &e); //后插入
};

template <typename T>
ListNodePosi(T) ListNode<T>::insertAsPred(T const &e)
{
    ListNodePosi(T) p = new ListNode(e, this->pred, this);
    this->pred->succ = p;
    this->pred = p;
    return p;
}

template <typename T>
ListNodePosi(T) ListNode<T>::insertAsSucc(T const&e){
    ListNodePosi(T) p = new ListNode(e, this, this->succ);
    this->succ->pred = p;
    this->succ = p;
    return p;
}