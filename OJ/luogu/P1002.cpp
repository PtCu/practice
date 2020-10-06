#include <bits/stdc++.h>
using namespace std;
const int dx[] = {-2, -2, -1, -1, 0, 1, 1, 2, 2};
const int dy[] = {-1, 1, -2, 2, 0, 2, -2, 1, -1};
const int maxn = 30;
long long dp[maxn][maxn];
bool s[maxn][maxn];
int main(int argc, char **argv)
{
    int n, m, hx, hy;
    cin >> n >> m >> hx >> hy;

    for (int i = 0; i < 9; i++)
    {
        s[hx + dx[i]][hy + dy[i]] = true;
    }
    for (int i = 0; i < n + 1; i++)
    {
        if (s[i][0])
            break;
        dp[i][0] = 1;
    }
    for (int i = 0; i < m + 1; i++)
    {
        if (s[0][i])
            break;
        dp[0][i] = 1;
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (s[i][j])
                continue;
            dp[i][j] = max(dp[i][j - 1] + dp[i - 1][j], dp[i][j]);
        }
    }
    cout << dp[n][m];
    return 0;
}
