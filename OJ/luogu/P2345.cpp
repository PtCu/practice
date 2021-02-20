#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 100000 + 10;
// 取音量较大的奶牛，于是可以先将奶牛的音量排序，然后将奶牛一个一个加入线段树中（线段树是以x值建立的）；

// 本题中可维护两个sum值，sum1为（l，r)中所有奶牛到0点的距离和；sum2位（l，r）中奶牛的个数；

// 然后就查询此前奶牛与当前奶牛的距离差和；
struct nod
{
    long long v, x;
} s[maxn];
struct node
{
    int left, right;
    long long sum1, sum2;
} t[maxn * 4];
long long n, maxs, ans;
bool cmp(nod a, nod b)
{
    return a.v < b.v;
}
void build(int g, int l, int r)
{
    t[g].left = l;
    t[g].right = r;
    t[g].sum1 = t[g].sum2 = 0;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(g << 1, l, mid);
    build(g << 1 | 1, mid + 1, r);
}
long long get(int g, int l, int r, int opt)
{
    if (r < t[g].left || t[g].right < l)
        return 0;
    if (l <= t[g].left && t[g].right <= r)
    {
        if (opt == 1)
            return t[g].sum1;
        if (opt == 2)
            return t[g].sum2;
    }
    return get(g << 1, l, r, opt) + get(g << 1 | 1, l, r, opt);
}
void add(int g, int x, long long y)
{
    if (t[g].left == t[g].right)
    {
        t[g].sum1 += y;
        t[g].sum2++;
        return;
    }
    if (x <= t[g << 1].right)
        add(g << 1, x, y);
    else
        add(g << 1 | 1, x, y);
    t[g].sum1 = t[g << 1].sum1 + t[g << 1 | 1].sum1;
    t[g].sum2 = t[g << 1].sum2 + t[g << 1 | 1].sum2;
}
int main()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%lld", &s[i].v, &s[i].x);
        maxs = max(maxs, s[i].x);
    }
    sort(s + 1, s + n + 1, cmp);
    build(1, 1, maxs);
    for (int i = 1; i <= n; i++)
    {
        long long g = get(1, s[i].x + 1, maxs, 1); //距离
        long long k = get(1, s[i].x + 1, maxs, 2); //个数
        ans += s[i].v * (g - k * s[i].x);
        g = get(1, 1, s[i].x - 1, 1);
        k = get(1, 1, s[i].x - 1, 2);
        ans += s[i].v * (k * s[i].x - g);
        add(1, s[i].x, s[i].x);
    }
    printf("%lld\n", ans);
}