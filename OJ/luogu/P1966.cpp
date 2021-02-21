// 由排序不等式知正序和最大，故只需求将a,b序列变成正序的最小步数。
// 首先对a操作或对b操作是没有区别的，因为我们只关系a,b中元素
// 的对应关系。
// 所以我们不妨只对b操作。
// 因只关心大小，不妨将a,b分别离散化。
// 然后将a一一映射成1-n，只需求将b序列变成1,2,3...n的最小步数。
// 首先任意一次操作可以将b序列的逆序对数-1，或者+1。
// 设b序列的逆序对对数为s，则将b序列变成a序列至少需要s步。
// 又因每次操作都可以将b序列逆序对数量--(否则b序列已经变成a序列)。
// 故可以用s步将b序列变为a序列。
// 综上将b序列变为a序列的最小步数即为b序列的逆序对对数。
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int P = 1e8 - 3;
struct node
{
    int idx, v;
} a[maxn], b[maxn];
int c[maxn];
bool cmp(node a, node b)
{
    return a.v < b.v;
}
int ans;
int invBetween(int lo, int mi, int hi) //归并[lo,hi)
{
    int seq_num = 0;
    int *A = c + lo;
    int lb = mi - lo;
    int *B = new int[lb];        //B[0,lb)=_elem[lo,mi)
    for (int i = 0; i < lb; i++) //复制B段
        B[i] = A[i];
    int *C = c + mi;
    int lc = hi - mi;
    for (int i = 0, j = 0, k = 0; j < lb;)
    {                               //i,j,k分别为A,B,C的指针
        if (C[k] <= B[j] && k < lc) //如果后半部分的元素比前面的小，就插入到前面去。相等的话不交换（保证稳定性）
        {
            A[i++] = C[k++];
            seq_num = (seq_num + (lb - j)) % P;
        }
        else
        {
            A[i++] = B[j++];
        }
    }
    delete[] B;
    return seq_num % P;
}
int invInside(int lo, int hi) //左闭右开[lo,hi)
{
    if (hi - lo < 2)
        return 0;
    else
    {
        int mi = (lo + hi) >> 1;
        int left = invInside(lo, mi);
        int right = invInside(mi, hi);
        int cross = invBetween(lo, mi, hi);
        return ((left + right) % P + cross) % P;
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i].v), a[i].idx = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &b[i].v), b[i].idx = i;
    }
    sort(a + 1, a + 1 + n, cmp);
    sort(b + 1, b + 1 + n, cmp);
    for (int i = 1; i <= n; ++i)
    {
        c[b[i].idx] = a[i].idx;
    }
    cout << invInside(1, n + 1);
}