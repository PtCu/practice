//P2004
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
long long a[maxn][maxn];
int main()
{
    int n, m, c;
    cin >> n >> m >> c;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }
    long long ans = 0;
    int max_i, max_j;
    long long tmp;
    for (int i = c; i <= n; ++i)
    {
        for (int j = c; j <= m; ++j)
        {
            tmp = a[i][j] - a[i - c][j] - a[i][j - c] + a[i - c][j - c];
            if (tmp > ans)
            {
                ans = tmp;
                max_i = i - c + 1;
                max_j = j - c + 1;
            }
        }
    }
    cout << max_i << " " << max_j;
}