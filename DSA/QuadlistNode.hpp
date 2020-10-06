#include "Entry.hpp"
#define QlistNodePosi(T) QuadlistNode<T> * //跳转表节点位置

template <typename T>
struct QuadlistNode
{
    T entry;                //所存词条
    QlistNodePosi(T) pred;  //前驱
    QlistNodePosi(T) succ;  //后继
    QlistNodePosi(T) above; //上邻
    QlistNodePosi(T) below; //下邻
    QlistNode(T e = T(), QlistNodePosi(T) p = nullptr, QlistNodePosi(T) b = nullptr, QlistNodePosi(T) s = nullptr, QlistNodePosi(T) a = nullptr) : entry(e), above(a), pred(p), below(b), succ(s) {}
    QlistNodePosi(T) insertAsSuccAbove(T const &e, QlistNodePosi(T) b = nullptr)
    {
        QlistNodePosi(T) x = new QuadlistNode<T>(e, this, succ, nullptr, b); //创建新节点，前驱为当前节点p,后继为p->succ,上邻和下邻分别为null和b
        succ->pred = x; 
        succ = x;   //设置水平逆向链接
        if (b)  
            b->above = x;//设置垂直逆向链接
        return x;   //返回新节点的位置
    }
};


