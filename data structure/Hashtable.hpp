#include "primeNLT.h"
#include "Dictionary/Dictionary.h" //引入词典ADT
#include "Bitmap/Bitmap.h"         //引入位图

static size_t hashCode(char c) { return (size_t)c; } //字符
static size_t hashCode(int k) { return (size_t)k; }  //整数以及长长整数
static size_t hashCode(long long i) { return (size_t)((i >> 32) + (int)i); }
static size_t hashCode(char s[])
{                                                 //生成字符串的循环移位散列码（cyclic shift hash code）
    unsigned int h = 0;                           //散列码
    for (size_t n = strlen(s), i = 0; i < n; i++) //自左向右，逐个处理每一字符
    {
        h = (h << 5) | (h >> 27);
        h += (int)s[i];
    }                 //散列码循环左移5位，再累加当前字符
    return (size_t)h; //如此所得的散列码，实际上可理解为近似的“多项式散列码”
} //对于英语单词，"循环左移5位"是实验统计得出的最佳值

template <typename K, typename V> //key、value
class Hashtable : public Dictionary<K, V>
{ //符合Dictionary接口的Hashtable模板类
    /*DSA*/ friend class UniPrint;

private:
    Entry<K, V> **ht;    //桶数组，存放词条指针
    int M;               //桶数组容量
    int N;               //词条数量
    Bitmap *lazyRemoval; //懒惰删除标记
#define lazilyRemoved(x) (lazyRemoval->test(x))
#define markAsRemoved(x) (lazyRemoval->set(x))
protected:
    int probe4Hit(const K &k);  //沿关键码k对应的查找链，找到词条匹配的桶
    int probe4Free(const K &k); //沿关键码k对应的查找链，找到首个可用空桶
    void rehash();              //重散列算法：扩充桶数组，保证装填因子在警戒线以下
public:
    Hashtable(int c = 5);          //创建一个容量不小于c的散列表（为测试暂时选用较小的默认值）
    ~Hashtable();                  //释放桶数组及其中各（非空）元素所指向的词条
    int size() const { return N; } // 当前的词条数目
    bool put(K, V);                //插入（禁止雷同词条，故可能失败）
    V *get(K k);                   //读取
    bool remove(K k);              //删除
};

template <typename K, typename V>
Hashtable<K, V>::Hashtable(int c)
{                                                                      //创建散列表，容量为
    M = primeNLT(c, 1048576, "../../_input/prime-1048576-bitmap.txt"); //不小于c的素数M
    N = 0;
    ht = new Entry<K, V> *[M];                //开辟桶数组（还需核对申请成功），初始装填因子为N/M = 0%
    memset(ht, 0, sizeof(Entry<K, V> *) * M); //初始化各桶
    lazyRemoval = new Bitmap(M);              //懒惰删除标记比特图
                                              //*DSA*/printf("A bucket array has been created with capacity = %d\n\n", M);
}

template <typename K, typename V>
Hashtable<K, V>::~Hashtable()
{                               //析构前释放桶数组及非空词条
    for (int i = 0; i < M; i++) //逐一检查各桶
        if (ht[i])
            release(ht[i]); //释放非空的桶
    release(ht);            //释放桶数组
    release(lazyRemoval);   //释放懒惰删除标记
} //release()负责释放复杂结构，与算法无直接关系，具体实现详见代码包

 //读取key. 返回对应的value的指针
template <typename K, typename V>
V *Hashtable<K, V>::get(K k) //散列表词条查找算法
{
    int r = probe4Hit(k);
    return ht[r] ? &(ht[r]->value) : NULL; //禁止词条的key值雷同
}

/******************************************************************************************
 * 沿关键码k对应的查找链，找到与之匹配的桶（供查找和删除词条时调用）
 * 试探策略多种多样，可灵活选取；这里仅以线性试探策略为例
 ******************************************************************************************/
template <typename K, typename V> int Hashtable<K, V>::probe4Hit ( const K& k ) {
   int r = hashCode ( k ) % M; //从起始桶（按除余法确定）出发
   //*DSA*/printf(" ->%d", r);
   while ( ( ht[r] && ( k != ht[r]->key ) ) || ( !ht[r] && lazilyRemoved ( r ) ) )
      r = ( r + 1 ) % M; //沿查找链线性试探：跳过所有冲突的桶，以及带懒惰删除标记的桶
   //*DSA*/printf(" ->%d", r);
   //*DSA*/printf("\n");
   return r; //调用者根据ht[r]是否为空，即可判断查找是否成功
}