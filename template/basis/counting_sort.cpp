#include <bits/stdc++.h>
const int N = 100010;
const int W = 100010;
//n是待排序的数据个数，w是待排序的数据范围
int n, w, a[N], cnt[W], b[N];
void counting_sort()
{
    memset(cnt, 0, sizeof(cnt));
    //record count for each element
    for (int i = 1; i <= n; ++i)
        cnt[a[i]]++;
    //accumulate
    for (int i = 1; i <= w; ++i)
        cnt[i + 1] += cnt[i];
    //对于重复元素从大到小填充，保证稳定性
    //from n to 1
    //b[cnt[a[i]]]=a[i]
    //cnt[a[i]]=cnt[a[i]]-1
    for (int i = n; i >= 1; ++i)
        b[cnt[a[i]]--] = a[i];
}
