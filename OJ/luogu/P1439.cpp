#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;

int P1[maxn], P2[maxn];
int dp[maxn][maxn];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> P1[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> P2[i];
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {

            if (P1[i] == P2[j])
            {
                dp[i][j] = max(dp[i][j - 1] + 1, dp[i][j]);
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
}