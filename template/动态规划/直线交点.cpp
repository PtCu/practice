#include <bits/stdc++.h>
using namespace std;
bool dp[30][900];
//计算N条直线所有可能的交点个数
// dp[i][j]为有i条直线时，交点数为j的情况存不存在
// dp[i][j] i是有i条直线 j代表交点个数

// 假设有n条直线，前n -1条直线的所有交点都知道
// 假设第n条线段与前n -1条平行: n条平行 交点数 0

// 假设第n条线段与前n -2条平行：n - 1条平行 交点数 1 * (n - 1)(剩下那一条与n - 1的平行线都有一个交点但是那两条直线有dp [1][j]) 
// 加上以后就是n - 1条平行所能组成的交点数 
// 假设第n条线段与前n - 3条平行：n - 2条平行 交点数 2 * (n - 2) + dp[2][j] 所有交点

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
            // j为平行线个数
            // j*(i-j)表示剩下的线和j条平行线的交点
            // k表示剩下的直线可能的交点个数
            //不平行的线的交点个数最多为 n*(n-1)/2
            for (int k = 0; k <= (i - j) * (i - j - 1) / 2; ++k)
            {
                if (dp[i-j][k])
                {
                    dp[i][j * (i - j) + k] = 1;
                }

               // dp[i][j * (i - j) + k] |= dp[i - j][k]; // dp[i-j][k]为去除j条平行线后剩下的线的交点个数为k时存不存在，
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