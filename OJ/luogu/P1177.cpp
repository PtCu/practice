#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];

//[lo, hi)
int partition(int lo, int hi)
{
    swap(a[lo], a[lo + rand() % (hi - lo)]);
    int pivot = a[lo];
    int mi = lo;
    for (int k = lo + 1; k < hi; ++k) //自左向右逐一考察每个a[k]
    {
        if (a[k] < pivot)        //若[k]小于轴点
            swap(a[++mi], a[k]); //将其与a[mi]交换, L向右扩展
    }
    swap(a[lo], a[mi]); //候选轴点归为，从而名副其实
    return mi;          //返回轴点的秩
}
void quicksort(int lo, int hi)
{
    if (hi - lo < 2)
        return;
    int mi = partition(lo, hi);
    quicksort(lo, mi);
    quicksort(mi + 1, hi);
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    quicksort(1, n + 1);
    for (int i = 1; i <= n; ++i)
    {
        printf("%d ", a[i]);
    }
}