#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
struct node
{
    long long v, x;
} a[maxn];
// 取音量较大的奶牛，于是可以先将奶牛的音量排序，然后将奶牛一个一个加入线段树中（线段树是以x值建立的）；
// 本题中可维护两个sum值，sum1为（l，r)中所有奶牛到0点的距离和；sum2位（l，r）中奶牛的个数；
// 然后就查询此前奶牛与当前奶牛的距离差和；
struct tree_node
{
    int left, right;
    long long dis_sum, num_sum;
} tree[maxn << 2];

void build(int k, int l, int r)
{
    tree[k].left = l, tree[k].right = r;
    tree[k].dis_sum = tree[k].num_sum = 0;
    if (l == r)
    {
        return;
    }
    int mid = (l + r) >> 1;
    build(k << 1, l, mid);
    build(k << 1 | 1, mid + 1, r);
}
//单点修改. 对标号为x的加z
void changeInterval(int k, int x, int z)
{
    if (tree[k].left == tree[k].right)
    {
        tree[k].dis_sum += z;
        tree[k].num_sum++;
        return;
    }
    int mid = (tree[k].left + tree[k].right) / 2;
    if (x <= mid)
        changeInterval(2 * k, x, z);
    if (x > mid)
        changeInterval(2 * k + 1, x, z);
    tree[k].dis_sum = tree[2 * k].dis_sum + tree[2 * k + 1].dis_sum;
    tree[k].num_sum = tree[2 * k].num_sum + tree[2 * k + 1].num_sum;
}

long long askInterval(int k, int l, int r, int opt)
{
    if (r < tree[k].left || tree[k].right < l)
        return 0;
    if (tree[k].left >= l && tree[k].right <= r)
    {
        if (opt == 1)
        {
            return tree[k].dis_sum;
        }
        if (opt == 2)
        {
            return tree[k].num_sum;
        }
    }
    return askInterval(k << 1, l, r, opt) + askInterval(k << 1 | 1, l, r, opt);
}

int main()
{
    int n;
    cin >> n;
    long long max_x = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].v >> a[i].x;
        max_x = max(max_x, a[i].x);
    }
    sort(a + 1, a + 1 + n, [](const node &node1, const node &node2) { return node1.v < node2.v; });
    build(1, 1, max_x);
    long long ans = 0;
    long long dis, num;
    for (int i = 1; i <= n; ++i)
    {
        dis = askInterval(1, a[i].x + 1, max_x, 1);
        num = askInterval(1, a[i].x + 1, max_x, 2);
        ans += a[i].v * (dis - num * a[i].x);
        dis = askInterval(1, 1, a[i].x, 1);
        num = askInterval(1, 1, a[i].x, 2);
        ans += a[i].v * (num * a[i].x - dis);
        changeInterval(1, a[i].x, a[i].x);
    }
    cout << ans;
}