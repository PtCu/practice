//最长不下降子序列
//PAT 1045
// 用dp[i]表示下标为i的元素nums[i]作为序列末尾时能得到的最长不下降子列长度，
//并将dp[i]作为本题的状态。然后将面临两种情况：
// nums[i]前面的元素的order排名都更大。
// nums[i]前面有order排名更小或相等的元素。
// 第一种情况好办，这说明以nums[i]为序列末尾时能得到的最长不下降子列长度dp[i]为1，
//因为前面的元素的order排名都更大，它们和nums[i]组合，无法形成排名不下降的子列。
// 第二种情况下，我们需要找出前面的所有比nums[i]的order排名更小或相等的元素nums[j]
//（其中，j = 0, 1, 2...i-1），并得到它们的dp[j]，而后，dp[i] = max{dp[j] + 1}（j = 0, 1, 2...i-1，
//且nums[j]的order排名小于等于nums[i]的order排名，即order[nums[j]] <= order[nums[i]]）。
// 至此，状态转移方程就出来了：
// dp[i] = max{dp[j] + 1, dp[i]}，其中j = 0,1,2,...,i-1且order[nums[j]] <= order[nums[i]]。
// 边界：
// dp[0] = 1。以nums[0]为末尾时能得到的最长不下降子列长度肯定为1，因为该子列就只有一个元素nums[0]。
// 之后，从边界出发，通过状态转移方程，不断计算dp[]数组，dp[]数组中的最大值就是最长不下降子列的长度。

int lengthOfLIS(vector<int> &nums)
{
    int n = (int)nums.size();
    if (n == 0)
    {
        return 0;
    }
    vector<int> dp(n, 0);
    for (int i = 0; i < n; ++i)
    {
        dp[i] = 1;
        for (int j = 0; j < i; ++j)
        {
            if (nums[j] < nums[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
int dp[maxn];
int order[201];
int nums[maxn]; //给定序列
int main()
{
    int n, m;
    cin >> n >> m;
    fill(order, order + n + 1, -1);
    for (int i = 0; i < m; ++i)
    {
        int x;
        cin >> x;
        order[x] = i;
    }
    int len;
    cin >> len;
    for (int i = 0; i < len; ++i)
    {
        cin >> nums[i];
    }
    int ans = 0;
    for (int i = 0; i < len; ++i)
    {
        //若为不喜欢的颜色直接跳过
        if (order[nums[i]] == -1)
            continue;
        int tmp = 0;
        for (int j = 0; j < i; ++j)
        {
            if (order[nums[j]] != -1 && order[nums[j]] <= order[nums[i]])
            {
                tmp = max(tmp, dp[j]);
            }
        }
        dp[i] = tmp + 1;
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}
