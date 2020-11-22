#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+10;
int source[maxn];
typedef long long  ll;
//[lo,hi)
ll merge(size_t lo, size_t mi, size_t hi)
{
    //逆序对数目
    ll invNum = 0;
    //A为source[lo,hi)
    int *A = source + lo;
    size_t lb = mi - lo;
    //B为source[lo,mi)
    int *B = new int[lb];
    for (size_t i = 0; i < lb; ++i)
        B[i] = A[i];
    size_t lc = hi - mi;
    //C为source[mi,hi)。这里就地使用了A的空间以减少空间复杂度
    int *C = source + mi;

    //将B和C归并，归并的时候统计逆序对。同时将结果放入A中
    //i为A的下标，k为C的下标，j为B的下标
    for (size_t i = 0, k = 0, j = 0; j < lb;)
    {
        //出现逆序就统计下来。同时将小的放在前面取
        if ((k < lc) && C[k] < B[j])
        {
            A[i++] = C[k++];
            invNum += lb - j;
        }
        else
        {
            A[i++] = B[j++];
        }
    }
    delete[] B;
    return invNum;
}
//在[lo,hi)区间利用归并排序统计逆序对
ll mergeSort(size_t lo, size_t hi)
{
    //hi=lo+1
    if (hi - lo < 2)
        return 0;
    else
    {
        size_t mi = (lo + hi) >> 1;
        ll invLo = mergeSort(lo, mi);  //T(n/2)
        ll invHi = mergeSort(mi, hi);  //T(n/2)
        ll invBtw = merge(lo, mi, hi); //O(n)
        return invBtw + invHi + invLo;
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> source[i];
    }
    cout << mergeSort(0, n);
}