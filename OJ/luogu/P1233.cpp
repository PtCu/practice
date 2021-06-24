#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int l, w;
    Node() = default;
    Node(int _l, int _w) : l(_l), w(_w) {}
    bool operator<(const Node &e) const
    {
        if (l != e.l)
            return l > e.l;
        return w > e.w;
    }
};
const int maxn = 5e3 + 10;
int dp[maxn];

vector<Node> nums;
// 这道题首先要用结构体排序，以木棍的长度为第一关键字（从大到小），以宽度为第二关键字排序（同样也是从大到小）。
// 需要注意的是，如果在两根木棍长度相等的情况下，必须要按宽度排序，否则就会被 hack。
// 在排序后，我们直接可以扔到这个长度不管了，直接把宽度跑一遍最长不上升子序列，得出最长不上升子序列的个数。
// 但是我们知道，最长不上升子序列的个数等于最长上升子序列的长度，所以我们只需要求出后者即可。

int LIS()
{
    int len = 0, n = nums.size();
    if (n == 0)
        return 0;

    for (int i = 0; i < n; ++i)
    {
        //注意最长上升和最长不下降的区别
        int pos = lower_bound(dp, dp + len, nums[i].w) - dp;
        if (pos == len)
        {
            dp[len++] = nums[i].w;
        }
        else
        {
            dp[pos] = nums[i].w;
        }
    }
    return len;
}

int main()
{
    int n, l, w;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> l >> w;
        nums.push_back({l, w});
    }
    //从大到小排序
    sort(nums.begin(), nums.end());
    int ans = LIS();

    cout << ans;
    return 0;
}