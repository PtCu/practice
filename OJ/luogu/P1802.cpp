#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 20;
int lose[maxn]; //输了拿到的经验
int win[maxn];  //赢了拿到的经验
int use[maxn];  //打过至少使用的药的数量
// int dp[maxn][maxn]; //dp[i][j]表示前i个好友中挑选好友，且总药量不超过j，每个好友最多调一个，

long long dp2[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x; //n个好友，x个药
    cin >> n >> x;
    for (size_t i = 1; i <= n; ++i)
    {
        cin >> lose[i] >> win[i] >> use[i];
    }

    //     for (size_t i = 1; i <= n; ++i)
    //     {
    //         for (size_t j = 0; j <= x; ++j)
    //         {
    //             if (use[i] <= j && use[i] > 0) //不用药打不过,看是用药能打过还是不用药认输
    //             {
    //                 dp[i][j] = max(dp[i - 1][j] + lose[i], dp[i-1][j - use[i]] + win[i]);
    //             }
    //             else if (use[i] == 0)
    //             { //不用药就能打过
    //                 dp[i][j] = dp[i-1][j] + win[i];
    //             }
    //             else
    //             { //use[i]>j,一定打不过
    //                 dp[i][j] = dp[i-1][j] + lose[i];
    //             }
    //         }
    //     }
    // cout << dp[n][x] * 5;
    for (size_t i = 1; i <= n; ++i)
    {
        for (int j = x; j >= 0; --j)
        {
            if (use[i] <= j && use[i] > 0)
            {
                dp2[j] = max(dp2[j - use[i]] + win[i], dp2[j] + lose[i]);
            }
            else if (use[i] == 0)
            {
                dp2[j] = dp2[j] + win[i];
            }
            else
            {
                dp2[j] = dp2[j] + lose[i];
            }
        }
    }
    cout << dp2[x] * 5;
}