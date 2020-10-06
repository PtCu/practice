#include "ListNode.hpp"
#include <stdlib.h>
template <typename T>
class List
{
private:
    int _size;               //规模
    ListNodePosi(T) header;  //头哨兵
    ListNodePosi(T) trailer; //尾哨兵

protected:                                                               //内部函数                                                               //内部函数
    void init();                                                         //列表创建时的初始化
    int clear();                                                         //清除所有节点
    void copyNodes(ListNodePosi(T), int);                                //复制列表中自位置p起的n项
    void merge(ListNodePosi(T) &, int, List<T> &, ListNodePosi(T), int); //有序列表区间归并；修改指针的值，（即修改指向关系而非修改指向的值）需要传入指针的指针或指针的引用。修改变量的值，需要传入该变量的地址或引用
    void mergeSort(ListNodePosi(T) &, int);                              //对从p开始连续的n个节点选择排序
    void selectionSort(ListNodePosi(T), int);                            //对从p开始连续的n个节点选择排序
    void insertSort(ListNodePosi(T), int);                               //对从p开始连续的n个节点插入排序

public: //构造函数、析构函数、只读接口、可写接口、遍历接口
    //构造函数
    List() { init(); }                     //默认
    List(List<T> const &L);                //整体复制列表L
    List(List<T> const &L, Rank r, int n); //复制列表L中自第r项起的n项
    List(ListNodePosi(T) p, int n);        //复制列表中自位置p起的n项
    //析构函数
    ~List();
    //只读访问接口
    Rank size() const { return _size; }                    //规模
    bool empty() const { return _size <= 0; }              //判空
    T &operator[](Rank r) const;                           //重载，支持循秩访问（效率低）
    ListNodePosi(T) first() const { return header->succ; } //首节点位置
    ListNodePosi(T) last() const { return trailer->pred; } //末节点位置
    bool valid(ListNodePosi(T) p)                          //判断位置p是否对外合法
    {
        return p && (trailer != p) && (header != p);
    }                                      //将头、尾节点等同于NULL
    ListNodePosi(T) find(T const &e) const //无序列表查找
    {
        return find(e, _size, trailer);
    }
    ListNodePosi(T) find(T const &e, int n, ListNodePosi(T) p) const; //无序区间查找
    ListNodePosi(T) search(T const &e) const                          //有序列表查找
    {
        return search(e, _size, trailer);
    }
    ListNodePosi(T) search(T const &e, int n, ListNodePosi(T) p) const;    //有序区间查找
    ListNodePosi(T) selectMax(ListNodePosi(T) p, int n);                   //在p及其n-1个后继中选出最大者
    ListNodePosi(T) selectMax() { return selectMax(header->succ, _size); } //整体最大者

    // 可写访问接口
    ListNodePosi(T) insertAsFirst(T const &e);                              //将e当作首节点插入
    ListNodePosi(T) insertAsLast(T const &e);                               //将e当作末节点插入
    ListNodePosi(T) insertAfter(ListNodePosi(T) p, T const &e);             //将e当作p的后继插入（After）
    ListNodePosi(T) insertBefore(ListNodePosi(T) p, T const &e);            //将e当作p的前驱插入（Before）
    T remove(ListNodePosi(T) p);                                            //删除合法位置p处的节点,返回被删除节点
    void merge(List<T> &L) { merge(first(), size, L, L.first(), L._size); } //全列表归并
    void sort(ListNodePosi(T) p, int n);                                    //列表区间排序
    void sort() { sort(first(), _size); }                                   //列表整体排序
    int deduplicate();                                                      //无序去重
    int uniquify();                                                         //有序去重
    void reverse();                                                         //前后倒置（习题）
                                                                            // 遍历
    void traverse(void (*)(T &));                                           //遍历，依次实施visit操作（函数指针，只读或局部性修改）
    template <typename VST>                                                 //操作器
    void traverse(VST &);                                                   //遍历，依次实施visit操作（函数对象，可全局性修改）
};

template <typename T>
void List<T>::init()
{
    header = new ListNode<T>;
    trailer = new ListNode<T>;
    header->succ = trailer;
    header->pred = nullptr;
    trailer->succ = nullptr;
    _size = 0;
}

template <typename T>
T &List<T>::operator[](Rank r) const
{
    ListNodePosi(T) p = first();
    while (r--)
    {
        p = p->succ;
    }
    return p->data;
}

//在无序列表内节点p(可能是trailer)的n个(真)前驱中，找到等于e的最后者
template <typename T>
ListNodePosi(T) List<T>::find(T const &e, int n, ListNodePosi(T) p) const
{
    while (0 < n--)
    {
        if (e == (p = p->pred)->data)
            return p;
    }
    return nullptr; //查找失败
}

template <typename T>
ListNodePosi(T) List<T>::insertAsFirst(T const &e)
{
    _size++;
    return header->insertAsSucc(e);
}

template <typename T>
ListNodePosi(T) List<T>::insertAsLast(T const &e)
{
    _size++;
    return trailer->insertAsPred(e);
}

template <typename T>
ListNodePosi(T) List<T>::insertAfter(ListNodePosi(T) p, T const &e)
{
    _size++;
    return p->insertAsSucc(e);
}

template <typename T>
ListNodePosi(T) List<T>::insertBefore(ListNodePosi(T) p, T const &e)
{
    _size++;
    return p->insertAsPred(e);
}

//复制列表中自位置p起的n项
template <typename T>
void List<T>::copyNodes(ListNodePosi(T) p, int n)
{
    init();
    while (n--)
    {
        insertAsLast(p->data);
        p = p->succ;
    }
}

template <typename T>
List<T>::List(ListNodePosi(T) p, int n)
{
    copyNodes(p, n);
}

template <typename T>
List<T>::List(List<T> const &L)
{
    copyNodes(L.first(), L.size());
}

//复制L中自第r项起的n项
template <typename T>
List<T>::List(List<T> const &L, int r, int n)
{
    copyNodes(L[r], n);
}

//删除p节点
template <typename T>
T List<T>::remove(ListNodePosi(T) p)
{
    T e = p->data;
    p->pred->succ = p->succ;
    p->succ->pred = p->pred;
    delete p;
    _size--;
    return e;
}

template <typename T>
List<T>::~List()
{
    clear();
    delete header;
    delete trailer;
}

//清空list，返回oldsize
template <typename T>
int List<T>::clear()
{
    int oldsize = _size;
    while (0 < this->_size)
    {
        remove(header->succ);
    }
    return oldsize;
}

//删除无序列表中的重复节点
template <typename T>
int List<T>::deduplicate()
{
    int oldsize = _size;
    if (_size < 2)
        return 0;
    ListNodePosi(T) p = header;
    Rank r = 0; //游标p的rank
    while (trailer != (p = p->succ))
    {
        ListNodePosi(T) q = find(p->data, r, p);
        q ? remove(q) : r++; //若的确存在，则删除，否则秩加1
    }                        //assert:循环过程中的任意时刻，p的所有前驱互不相同
    return oldsize - _size;
}

template <typename T>
void List<T>::traverse(void (*visit)(T &))
{
    for (ListNodePosi(T) p = header; p != trailer; p = p->succ)
        visit(p->data);
}

//函数对象
template <typename T>
template <typename VST>
void List<T>::traverse(VST &visit)
{
    for (ListNodePosi(T) p = header; p != trailer; p = p->succ)
        visit(p->data);
}

//删除有序列表重复节点
template <typename T>
int List<T>::uniquify()
{
    if (_size < 2)
        return 0;
    int oldsize = _size;
    ListNodePosi(T) p = first();
    ListNodePosi(T) q;
    while (trailer != (q = p->succ))
    {
        q->data == p->data ? remove(q) : p = q;
    }

    return oldsize - _size;
}

//在有序列表内节点p的n个真前驱中，找到不大于e的最后者（从后向前比较）。在有序前缀中寻找一分界点，使前面的都不大于e，后面的都严格大于e
template <typename T>
ListNodePosi(T) List<T>::search(T const &e, int n, ListNodePosi(T) p) const
{
    while (0 <= n--) //注意等号
    {
        p = p->pred;
        if (p->data <= e)
            break;
    }
    return p;
} //失败时，返回区间左边界的前驱（可能是header）——调用者可通过valid() 判断成功与否

//排序器
template <typename T>
void List<T>::sort(ListNodePosi(T) p, int n)
{
    switch (rand() % 3)
    {
    case 1:
        insertSort(p, n);
        break;
    case 2:
        selectionSort(p, n);
        break;

    default:
        mergeSort(p, n);
        break;
    }
}

//对起始于位置p的n个元素排序
//插入排序：前面有序，后面无序
//从前到后，每到一个元素就找合适的插入位置
template <typename T>
void List<T>::insertSort(ListNodePosi(T) p, int n)
{
    for (int r = 0; r < n; r++)
    {
        ListNodePosi(T) q = search(p->data, r, p); //在有序列表内节点p的n个真前驱中，找到不大于e的最后者
        insertAfter(q, p->data);
        p = p->succ;
        remove(p->pred);
    }
}

//对起始于位置p的n个元素排序
//选择排序：前面无序，后面有序
//从前到后，选择最大的插入到tail前面
template <typename T>
void List<T>::selectionSort(ListNodePosi(T) p, int n)
{
    ListNodePosi(T) head = p->pred;
    ListNodePosi(T) tail = p;
    for (int i = 0; i < n; i++)
        tail = tail->succ; //待排序区间为(head, tail)

    while (1 < n) //在至少还剩两个节点之前，在待排序区间内
    {
        ListNodePosi(T) max = selectMax(head->succ, n);
        insertBefore(tail, remove(max));
        tail = tail->pred;
        n--;
    }
}

//从起始于位置p的n个元素中选出最大者
template <typename T>
ListNodePosi(T) List<T>::selectMax(ListNodePosi(T) p, int n)
{
    ListNodePosi(T) max = p;
    for (ListNodePosi(T) cur = p; 1 < n; n--)
    {
        if (!lt((cur = cur->succ)->data, max->data)) //不小于就交换
            max = cur;
    }
    return max;
}

//当前列表中自p起的n个元素，与列表L中自q起的m个元素归并
template <typename T>
void List<T>::merge(ListNodePosi(T) & p, int n, List<T> &L, ListNodePosi(T) q, int m)
{
    ListNodePosi(T) pp = p->pred;
    while (0 < m)
    {
        if ((0 < n) && (p->data <= q->data)) //如果p的数据小于q，就直接将p后移一位
        { 
            p = p->succ;
            if (q == p)     //看前半段是否消耗完，消耗完了就结束
                break;
            n--;
        }
        else
        {
            insertBefore(p, q->data);
            L.remove((q = q->succ)->pre);
            m--;
        }
    }
}

template <typename T>
void List<T>::mergeSort(ListNodePosi(T) & p, int n)
{
    if (n < 2)
        return;
    int m = n >> 1; //以中点为界
    ListNodePosi(T) q = p;
    for (int i = 0; i < m; i++)
        q = q->succ;
    mergeSort(p, m); //对前后子列表分别排序
    mergeSort(q, n - m);
    merge(p, m, *this, q, n - m); //归并
}//排序后，p依然指向归并后区间的新起点
