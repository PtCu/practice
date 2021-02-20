#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
struct node
{
    int v, x;
};
node a[maxn], tmp[maxn];
long long ans;
void solve(int l, int r)
{
    if (l >= r)
        return;
    int mid = (l + r) >> 1;
    solve(l, mid);
    solve(mid + 1, r);
    //此时已经按照x排序
    long long s2 = 0, s1 = 0;
    for (int i = l; i <= mid; ++i)
    {
        s2 += a[i].x;
    }
    int l_mid = l;
    //枚举右边mid+1到r的区间，找到有哪些x值比当前小，哪些比它大
    //mid_p为[l, mid]上划分的中点，其左边都小于a[i].x，右边都大于或等于a[i].x
    for (int i = mid + 1; i <= r; ++i)
    {
        while (a[l_mid].x < a[i].x && l_mid <= mid)
        {
            s1 += a[l_mid].x;
            s2 -= a[l_mid].x;
            ++l_mid;
        }
        //s1为前半部分大于a[i].x的和，s2为前半部分小于a[i].x的和
        ans += (a[i].x * (l_mid - l) - s1 + s2 - a[i].x * (mid - l_mid + 1)) * a[i].v;
    }

    
    //按x归并排序
    int l1 = l, l2 = mid + 1, k = l - 1;
    while (l1 <= mid || l2 <= r)
    {
        if ((a[l1].x > a[l2].x || l1 > mid) && l2 <= r)
        {
            tmp[++k] = a[l2];
            l2++;
        }
        else
        {
            tmp[++k] = a[l1];
            l1++;
        }
    }
    for (int i = l; i <= r; ++i)
    {
        a[i] = tmp[i];
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].v >> a[i].x;
    }
    sort(a + 1, a + 1 + n, [](const node &node1, const node &node2) { return node1.v < node2.v; });
    solve(1, n);
    cout << ans;
}