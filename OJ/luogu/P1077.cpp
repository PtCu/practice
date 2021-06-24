#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int dp[maxn][maxn];
int a[maxn];
int v[maxn];
int w[maxn];
//i种j盆花的方案总数
//b[i][j]+=b[i−1][k](j>=k>=j−a[i])

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        dp[i][0] = 1;
    }
    dp[0][0] = 1;

    //变量i表示有多少种花，j表示有多少盆花，k则是用于计算某种花放多少盆。/
    //如果k小于0（说明最大盆数大于总盆数）就退出循环
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            //最少0盆
            for (int k = 0; k <= a[i]; ++k)
            {
                if (j >= k)
                {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % 1000007;
                }
                else
                    break;
            }
        }
    }
    cout << dp[n][m] << endl;
}