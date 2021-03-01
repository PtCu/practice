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
