//https://www.cnblogs.com/MingSD/p/8387345.html

#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
struct node
{
    int l, r, sum;
} tree[maxn << 2];
void build(int k, int l, int r)
{
    tree[k].l = l, tree[k].r = r, tree[k].sum = 0;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(k << 1, l, mid);
    build(k << 1 | 1, mid + 1, r);
}
void change(int k, int x, int v)
{
    if (tree[k].l == x && x == tree[k].r)
    {
        tree[k].sum += v;
        return;
    }
    int mid = (tree[k].l + tree[k].r) >> 1;
    if (x <= mid)
    {
        change(k << 1, x, v);
    }
    else
    {
        change(k << 1 | 1, x, v);
    }
    tree[k].sum = tree[k << 1].sum + tree[k << 1 | 1].sum;
}
long long query(int k, int l, int r)
{
    if (l <= tree[k].l && tree[k].r <= r)
    {
        return tree[k].sum;
    }
    int mid = (tree[k].l + tree[k].r) >> 1;
    long long cnt = 0;
    if (l <= mid)
    {
        cnt += query(k << 1, l, r);
    }
    if (mid < r)
    {
        cnt += query(k << 1 | 1, l, r);
    }
    return cnt;
}

//线段树维护的是按顺序排列的输入元素的出现个数。如输入5,2,3,4,7
//线段树中节点是按顺序的 2,3,4,5,7，并且记录了每个节点的出现个数。
//按输入数据的次序遍历，每次查询出比当前数大的数的出现次数，并加到ans中，
//同时更新线段树。
int a[maxn], dis[maxn];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        dis[i] = a[i];
    }
    sort(dis + 1, dis + 1 + n);
    int retn = unique(dis + 1, dis + 1 + n) - dis - 1;
    build(1, 1, retn);
    int l;
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        l = lower_bound(dis + 1, dis + 1 + retn, a[i]) - dis;
        ans += (long long)query(1, l + 1, retn);
        change(1, l, 1);
    }
    cout << ans;
    return 0;
}