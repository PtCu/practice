#include <stdlib.h>
#include "Fib.hpp"

typedef int Rank;          //typedef给数据类型起别名
#define DEFAULT_CAPACITY 3 //define可给常量起别名
template <typename T>

class Vector
{
protected:
    Rank _size;                                  //规模
    int _capacity;                               //容量
    T *_elem;                                    //数据区
    void copyFrom(T const *A, Rank lo, Rank hi); //复制数组区间A[lo,hi)]
    void expand();                               //空间不够时扩充
    void shrink();                               //填装因子过小时压缩
    bool bubble(Rank lo, Rank hi);               //扫描交换
    void bubbleSort_A(Rank lo, Rank hi);         //起泡排序低效版
    void bubbleSort_B(Rank lo, Rank hi);         //起泡排序改进 （提前终止版）
    void bubbleSort_C(Rank lo, Rank hi);         //起泡排序再改进 (跳跃版)
    Rank max(Rank lo, Rank hi);                  //选取最大元素
    void selectionSort(Rank lo, Rank hi);        //选择排序法
    void merge(Rank lo, Rank mi, Rank hi);       //归并算法
    void mergeSort(Rank lo, Rank hi);            //归并排序
    Rank partition(Rank lo, Rank hi);            //轴点构造算法
    void quickSort(Rank lo, Rank hi);            //快排
    void heapSort(Rank lo, Rank hi);             //堆排序
public:
    //构造函数
    Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0) //容量为c，规模为s，所有元素初始化为v
    {
        _elem = new T[_capacity = c]; //cpp a=b 返回a的引用
        for (_size = 0; _size < s; _elem[_size++] = v)
            ;
    }
    Vector(T const *A, Rank lo, Rank hi)
    { //数组区间复制
        copyFrom(A, lo, hi);
    }
    Vector(T const *A, Rank n)
    { //数组整体复制
        copyFrom(A, 0, n);
    }
    Vector(Vector<T> const &V, Rank lo, Rank hi)
    {
        copyFrom(V._elem, lo, hi);
    }
    Vector(Vector<T> const &V)
    {
        copyFrom(V._elem, 0, V._size);
    }

    //析构函数
    ~Vector()
    {
        delete[] _elem; //释放内部空间 方括号的存在会使编译器获取数组大小（size）然后析构函数再被依次应用在每个元素上，一共size次。否则，只有一个元素被析构。
    }

    //只读访问接口 加const
    Rank size() const { return _size; }   //规模
    bool empty() const { return !_size; } //判空
    int disordered() const;               //判断向量是否已经排序
    Rank find(T const &e) const           //无序向量整体查找
    {
        return find(e, 0, _size);
    }
    Rank find(T const &e, Rank lo, Rank hi) const; //无序向量区间查找
    Rank search(T const &e) const                  //有序向量整体查找
    {
        return (0 >= _size) ? -1 : search(e, 0, _size);
    }
    Rank search(T const &e, Rank lo, Rank hi) const; //有序向量区间查找
    //可写访问接口
    T &operator[](Rank r) const;             //重载下标操作符，可以类似于数组形式引用各元素
    Vector<T> &operator=(Vector<T> const &); //重载赋值操作符，以便直接克隆向量
    T remove(Rank r);                        //删除rank为r的元素
    int remove(Rank lo, Rank hi);            //删除rank在区间[lo,hi)之内的元素
    Rank insert(Rank r, T const &e);         //插入元素
    Rank insert(T const &e)                  //默认作为末元素插入
    {
        return insert(_size, e);
    }
    void sort(Rank lo, Rank hi); //对[lo,hi)排序
    void sort()                  //整体排序
    {
        sort(0, _size);
    }
    void unsort(Rank lo, Rank hi); //置乱
    void unsort()                  //整体置乱
    {
        unsort(0, _size);
    }
    int deduplicate(); //无序去重
    int uniquify();    //有序去重

    //遍历
    void traverse(void (*)(T &)); //遍历（使用函数指针，只读或局部性修改
    template <typename VST>
    void traverse(VST &); //遍历（使用函数对象，可全局性修改
};
//函数对象
template<typename T>
struct Increase{
    virtual void operator()(T &e) { e++; }
};

template <typename T>
//复制数组区间A[lo,hi)]
void Vector<T>::copyFrom(T const *A, Rank lo, Rank hi)
{
    this->_elem = new T[_capacity = 2 * (hi - lo)]; //分配空间，规模清零
    _size = 0;
    while (lo < hi)
    {
        this->_elem[_size++] = A[lo++]; //复制
    }
}

template <typename T>
//重载赋值操作符，以便直接克隆向量
Vector<T> &Vector<T>::operator=(Vector<T> const &V)
{
    if (this->_elem)
        delete[] _elem;
    copyFrom(V, 0, V.size());
    return *this; //返回当前对象的引用，以便链式赋值
}

template <typename T>
//重载下标操作符，可以类似于数组形式引用各元素
T &Vector<T>::operator[](Rank r) const
{
    return this->_elem[r];
} //assert 0<=r<=_size

template <typename T>
Rank Vector<T>::max(Rank lo, Rank hi)
{
    Rank max = lo;
    T max_tmp = _elem[lo];
    for (int i = lo; i < hi;i++){
        if(_elem[i]>max_tmp){
            max = i;
            max_tmp = _elem[i];
        }
    }
    return max;
}
template <typename T>
//扩容。不能直接在原来的物理空间的基础上追加，因为数组必须地址连续. 所以需要开辟新的
void Vector<T>::expand() //向量不足时扩容
{
    if (_size < _capacity) //未满时不扩容
        return;
    if (_capacity < DEFAULT_CAPACITY) //不低于最小容量
        _capacity = DEFAULT_CAPACITY;
    T *oldelem = this->_elem;
    this->_elem = new T[_capacity << 1]; //容量加倍
    for (int i = 0; i < _size; i++)      //复制原向量内容
    {
        _elem[i] = oldelem[i];
    }
    delete[] oldelem; //释放原空间
}

template <typename T>
void Vector<T>::shrink() //装填因子过小时压缩向量所占空间
{
    if (_capacity < DEFAULT_CAPACITY << 1) //不致收缩到DEFAULT_CAPACITY以下
        return;
    if (_size << 2 > _capacity) //以25%为界
        return;
    T *oldElem = this->_elem;
    this->_elem = new T[_capacity >>= 1]; //容量减半
    for (int i = 0; i < _size; i++)       //复制原向量内容
    {
        this->_elem[i] = oldElem[i];
    }
    delete[] oldElem; //释放原空间
}

template <typename T>
//在位置r插入元素
Rank Vector<T>::insert(Rank r, T const &e)
{
    this->expand(); //如有必要,先扩容（扩容内部有判断逻辑）
    for (int i = _size; i > r; i--)
    {
        this->_elem[i] = this->_elem[i - 1];
    }
    this->_elem[r] = e;
    this->_size++;
    return r; //返回秩
}

template <typename T>
//删除区间[lo,hi)的元素
int Vector<T>::remove(Rank lo, Rank hi)
{
    if (lo == hi)
        return 0; //出于效率，单独处理退化情况
    while (hi < this->_size)
    {
        this->_elem[lo++] = this->_elem[hi++]; //[hi,size)顺次前移hi-lo位
    }
    _size = lo;
    shrink();       //更新规模
    return hi - lo; //返回被删除元素的数目
}

template <typename T>
//删除单个元素. 调用区间删除。 比区间删除调用单元素删除要高效O(n^2)
T Vector<T>::remove(Rank r)
{
    T e = this->_elem[r]; //备份被删除元素
    remove(r, r + 1);
    return e;
}

template <typename T>
//区间置乱
void Vector<T>::unsort(Rank lo, Rank hi)
{
    T *V = this->_elem + lo; //将子向量_elem[lo,hi)视作V[0,hi-lo)
    for (Rank i = hi - lo; i > 0; i--)
    {
        swap(V[i - 1], V[rand() % i]); //将V[i-1]于V[0,i)中某一元素交换
    }
}

template <typename T>
Rank Vector<T>::find(T const &e, Rank lo, Rank hi) const
{
    while ((lo < hi--) && (e != this->_elem[hi])) //无序向量逆向查找
        ;
    return hi;
} //查找失败返回lo-1

template <typename T>
int Vector<T>::deduplicate()
{                                    //删除无序向量中重复元素（高效版）
    int oldSize = _size;             //记录原规模
    Rank i = 1;                      //从_elem[1]开始
    while (i < _size)                //自前向后逐一考查各元素_elem[i]
        (find(_elem[i], 0, i) < 0) ? //在其前缀中寻找与之雷同者（至多一个）
            i++
                                   : remove(i); //若无雷同则继续考查其后继，否则删除雷同者
    return oldSize - _size;                     //向量规模变化量，即被删除元素总数
}

template <typename T>
void Vector<T>::traverse(void (*visit)(T &))
{
    for (int i = 0; i < _size; i++)
    {
        visit(this->_elem[i]);
    }
}

template <typename T>
template <typename VST>
void Vector<T>::traverse(VST &visit)
{
    for (int i = 0; i < _size; i++)
    {
        visit(this->_elem[i]);
    }
}

template <typename T>
int Vector<T>::disordered() const //返回向量中逆序相邻元素对的总数
{
    int n;
    for (int i = 1; i < _size; i++)
    {
        if (_elem[i - 1] > _elem[i])
            n++;
    }
    return n;
}

template <typename T>
int Vector<T>::uniquify()
{
    Rank i = 0, j = 0;
    while (++j < _size)
    {
        if (_elem[i] != _elem[j])
        {
            _elem[++i] = _elem[j];
        }
    }
    _size = ++i;
    shrink();     //删除尾部多余元素
    return j - i; //返回被删除元素总数
}

// //二分查找版本A
// template <typename T>
// static Rank binSearch(T *S, T const &e, Rank lo, Rank hi)
// {

//     while (lo < hi)
//     {
//         Rank mi = (lo + hi) >> 1;
//         if (e < S[mi])
//             hi = mi;
//         else if (S[mi] < e)
//             lo = mi + 1;
//         else
//             return mi;
//     }
//     return -1;
// }
// // 二分查找算法（版本B）：在有序向量的区间[lo, hi)内查找元素e，0 <= lo < hi <= _size
// template <typename T>
// static Rank binSearch(T *S, T const &e, Rank lo, Rank hi)
// {
//     while (1 < hi - lo)
//     {                                    //每步迭代仅需做一次比较判断，有两个分支；成功查找不能提前终止
//         /*DSA*/                          //for ( int i = 0; i < lo; i++ ) printf ( "     " ); if ( lo >= 0 ) for ( int i = lo; i < hi; i++ ) printf ( "....^" ); printf ( "\n" );
//         Rank mi = (lo + hi) >> 1;        //以中点为轴点（区间宽度的折半，等效于宽度之数值表示的右移）
//         (e < S[mi]) ? hi = mi : lo = mi; //经比较后确定深入[lo, mi)或[mi, hi)
//     }                                    //出口时hi = lo + 1，查找区间仅含一个元素A[lo]
//     /*DSA*/                              //for ( int i = 0; i < lo; i++ ) printf ( "     " ); if ( lo >= 0 ) printf ( "....|\n" ); else printf ( "<<<<|\n" );
//     return e < S[lo] ? lo - 1 : lo;      //返回位置，总是不超过e的最大者
// } //有多个命中元素时，不能保证返回秩最大者；查找失败时，简单地返回-1，而不能指示失败的位置

//二分查找版本C
template <typename T>
static Rank binSearch(T *S, T const &e, Rank lo, Rank hi)
{
    while (lo < hi) //每步迭代仅需做一次比较
    {
        Rank mi = (lo + hi) >> 1; //以中点为轴点
        (e < S[mi]) ? hi = mi : lo = mi + 1;
    }
    return --lo; //循环结束时，lo为大于e的元素的最小秩，故lo-1为不大于e的元素的最大秩
} //有多个命中元素时，总能保证返回秩的最大者;查找失败时，能够返回失败的位置

template <typename T>
static Rank fibSearch(T *S, T const &e, Rank lo, Rank hi)
{
    Fib fib(hi - lo); //总长度初始为fib(k)
    while (lo < hi)
    {
        while (hi - lo < fib.get()) //自后向前顺序查找前一项fib(k-1)（分摊O(1)）
        {
            fib.prev();
        }
        Rank mi = lo + fib.get() - 1; //确定形如Fib(k)-1的轴点
        if (e < S[mi])
            hi = mi;
        else if (S[mi] < e)
            lo = mi + 1;
        else
            return mi;
    }
    return -1;
}

template <typename T>
Rank Vector<T>::search(T const &e, Rank lo, Rank hi) const
{
    return (rand() % 2) ? fibSearch(_elem, e, lo, hi) : binSearch(_elem, e, lo, hi);
}

template <typename T>
void Vector<T>::bubbleSort_A(Rank lo, Rank hi)
{
    while (lo < hi--)
    {
        for (Rank i = lo; i < hi; i++)
            if (_elem[i] > _elem[i + 1])
                swap(_elem[i], _elem[i + 1]);
    }
}

template <typename T>
void Vector<T>::bubbleSort_B(Rank lo, Rank hi) //完成的扫描交换趟数 = 实际发生元素交换的扫描交换趟数 + 1
{
    bool swaped = false;
    while (lo < hi--)
    {
        swaped = false;
        for (Rank i = lo; i < hi; i++)
        {
            if (_elem[i] > _elem[i + 1])
            {
                swaped = true;
                swap(_elem[i], _elem[i + 1]);
            }
        }
        if (!swaped)
            break;
    }
}

template <typename T>
void Vector<T>::bubbleSort_C(Rank lo, Rank hi)
{
    while (lo < hi) //跳跃式改变扫描区间
    {
        Rank last = lo;
        while (lo++ < hi - 1)
        {
            if (_elem[lo] > _elem[lo + 1])
            {
                last = lo + 1;
                swap(_elem[lo], _elem[lo + 1]);
            }
        }
        hi = last;
    }
}

template <typename T>
void Vector<T>::sort(Rank lo, Rank hi)
{
    switch (rand() % 5)
    {
    case 1:
        bubbleSort_C(lo, hi);
        break;
    case 2:
        selectionSort(lo, hi);
        break;
    case 3:
        mergeSort(lo, hi);
        break;
    case 4:
        heapSort(lo, hi);
        break;
    default:
        quickSort(lo, hi);
        break;
    }
}
template <typename T>
void Vector<T>::merge(Rank lo, Rank mi, Rank hi)
{
    T *A = _elem + lo; // A[0,hi-lo)=_elem[lo,hi)
    int lb = mi - lo;
    T *B = new T[lb]; //B[0,lb)=_elem[lo,mi)
    for (Rank i = 0; i < lb; i++)
        B[i] = A[i];
    int lc = hi - mi;
    T *C = _elem + mi;
    for (int i = 0, k = 0, j = 0; j < lb;)
    {
        if ((k < lc) && C[k] < B[j])
            A[i++] = C[k++];
        else
            A[i++] = B[j++];
    }
    delete[] B;
}

template <typename T>
void Vector<T>::mergeSort(Rank lo, Rank hi) //左闭右开 [lo,hi)
{
    if (hi - lo < 2) //hi-lo=1 递归基
        return;
    int mi = (lo + hi) >> 1;
    mergeSort(lo, mi); //T(n/2)
    mergeSort(mi, hi); //T(n/2)
    merge(lo, mi, hi); //O(n)
}