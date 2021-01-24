//luogu 2789
#include <bits/stdc++.h>
using namespace std;
bool dp[30][900];
//dp[i][j]为有i条直线时，交点数为j的情况存不存在
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        dp[i][0] = 1;
    }
    for (int i = 2; i <= n; ++i)
    {
        for (int j = i - 1; j >= 1; --j)
        {
            //j为平行线个数
            //不平行的线的交点个数最多为 n*(n-1)/2
            for (int k = 0; k <= (i - j) * (i - j - 1) / 2; ++k)
            {
                dp[i][j * (i - j) + k] |= dp[i - j][k]; //dp[i-j][k]为去除j条平行线后剩下的线的交点个数为k时存不存在，
            }
        }
    }
    int ans = 0;
    for (size_t i = 0; i <= (n - 1) * n / 2; ++i)
    {
        if (dp[n][i])
            ++ans;
    }
    cout << ans << endl;
}