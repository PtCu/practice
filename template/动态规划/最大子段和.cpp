//PAT 1007
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
int dp[maxn]; //[1,i]内最大的数
int a[maxn];
int s, e;
int main()
{
    int k;
    cin >> k;
    bool flag = true;
    cin >> a[0];
    dp[0] = a[0];
    int ans =dp[0];
    //分类dp[i-1]不小于0 or 小于0.
    //去掉负前缀
    for (int i = 1; i < k; ++i)
    {
        cin >> a[i];
        dp[i] = max(dp[i - 1] + a[i], a[i]);
        if (dp[i] > ans)
        {
            ans = dp[i];
            e = i;
        }
    }

    if (ans < 0)
    {
        ans = 0, e = k - 1;
    }
    else
    {
        for (int i = 0; i <= e; ++i)
        {
            if (dp[i] < 0)
                s = i + 1;
        }
    }
    cout << ans << " " << a[s] << " " << a[e];
    return 0;
}