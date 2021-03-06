//P1719
#include <bits/stdc++.h>
using namespace std;
const int maxn = 150;
int a[maxn][maxn];
int dp[maxn], f[maxn]; //f[i]表示第i列值
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
            a[i][j] += a[i - 1][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int k = 1; k <= i; ++k)
        {
            memset(dp, 0, sizeof(dp));
            memset(f, 0, sizeof(f));
            for (int j = 1; j <= n; ++j)
            {
                f[j] = a[i][j] - a[i - k][j];
                dp[j] = max(dp[j - 1] + f[j], f[j]);
                ans = max(ans, dp[j]);
            }
        }
    }
    cout << ans;
}