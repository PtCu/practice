#include "QuadlistNode.hpp"
template <typename T>
class Quadlist
{
private:
    int _size;
    QlistNodePosi(T) header;
    QlistNodePosi(T) trailer;
protected:
    void init();
    int clear();

public:
    Quadlist() { init(); }
    ~Quadlist() { clear();
        delete header;
        delete trailer;
    }
    //只读
    Rank size() const { return _size; }
    bool empty() const { return _size <= 0; }
    QlistNodePosi(T) first() const { return header->succ; }
    QlistNodePosi(T) last() const { return trailer->pred; }
    bool valid(QlistNodePosi(T) p) {
        return p && (trailer != p) && (header != p);
    }
    //可写
    T remove(QlistNodePosi(T) p); //删除
    QlistNodePosi(T) insertAfterAbove(T const &e, QlistNodePosi(T) p, QlistNodePosi(T) b = nullptr);

    //遍历
    void traverse(void (*)(T &));//函数指针，只读或局部修改 返回void,参数为T& (*)括号不能少
    template <typename VST>
    void traverse(VST &);//操作器

};

template <typename T>
void Quadlist<T>::init() {
    header = new QuadlistNode<T>;
    trailer = new QuadlistNode<T>;
    header->succ = trailer; //沿横向联接哨兵
    header->pred = nullptr;
    trailer->pred = header; //沿横向联接哨兵
    trailer->succ = nullptr;
    header->above = trailer->above = nullptr;//纵向的后继置空
    header->below = trailer->below = nullptr; //纵向的前驱置空
    _size = 0;
}

template <typename T> //删除Quadlist内位置p处的节点，返回其中存放的词条
T Quadlist<T>::remove(QlistNodePosi(T) p)
{ //assert: p为Quadlist中的合法位置
    p->pred->succ = p->succ;
    p->succ->pred = p->pred;
    _size--; //摘除节点
    T e = p->entry;
    delete p; //备份词条，释放节点
    return e; //返回词条
}

template <typename T>
int Quadlist<T>::clear()
{ //清空Quadlist
    int oldSize = _size;
    while (0 < _size)
        remove(header->succ); //逐个删除所有节点
    return oldSize;
}
template <typename T>
QlistNodePosi(T) Quadlist<T>::insertAfterAbove(T const &e, QlistNodePosi(T) p, QlistNodePosi(T) b = NULL)
{
    _size++;
    return p->insertAsSuccAbove(e, b);
}

template <typename T> //遍历Quadlist，对各节点依次实施visit操作
void Quadlist<T>::traverse(void (*visit)(T &))
{ //利用函数指针机制，只读或局部性修改
    QlistNodePosi(T) p = header;
    while ((p = p->succ) != trailer)
        visit(p->data);
}

template <typename T>
template <typename VST> //遍历Quadlist，对各节点依次实施visit操作
void Quadlist<T>::traverse(VST &visit)
{ //利用函数对象机制，可全局性修改
    QlistNodePosi(T) p = header;
    while ((p = p->succ) != trailer)
        visit(p->data);
}