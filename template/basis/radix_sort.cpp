#include <bits/stdc++.h>
const int N = 100010;
const int W = 100010;
const int K = 100;

int n, w[K], k, cnt[W];

struct Element
{
    int key[K];
    // 两个元素的比较流程
    bool operator<(const Element &e) const
    {
        for (int i = 1; i <= K; ++i)
        {
            if (key[i] == e.key[i])
                continue;
            return key[i] < e.key[i];
        }
        return false;
    }
} a[N], b[N];

void counting_sort(int idx)
{
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= K; ++i)
        cnt[a[i].key[idx]]++;
    for (int i = 1; i <= w[idx]; ++i)
        cnt[i + 1] += cnt[i];
    // 为保证排序的稳定性，此处循环i应从n到1
    // 即当两元素关键字的值相同时，原先排在后面的元素在排序后仍应排在后面
    for (int i = n; i >= 1; --i)
        b[cnt[a[i].key[idx]]--] = a[i];
    memcpy(a, b, sizeof(a));
}
void radix_sort()
{
    for (int i = k; i >= 1; --i)
    {
        //借助计数排序完成对关键字的排序
        counting_sort(i);
    }
}