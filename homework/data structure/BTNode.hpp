#include "Vector.hpp"
#define BTNodePosi(T) BTNode<T>*
template <typename T>
struct BTNode
{
    BTNodePosi(T) parent;   //父结点
    Vector<T> key;          //n个内部节点  关键码向量 
    Vector<BTNodePosi(T)> child;    //孩子向量
    BTNode() { parent = NULL;
        child.insert(0, NULL);  //n+1个外部节点  child数量[[m/2],m]上取整
    }
    BTNode(T e, BTNodePosi(T) lc = NULL, BTNodePosi(T) rc = NULL) {
        parent = NULL;
        key.insert(0, e);
        child.insert(0, lc);
        child.insert(1, rc);
        if(lc)
            lc->parent = this;
        if(rc)
            rc->parent = this;
    }
};