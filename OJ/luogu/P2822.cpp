#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 5;
int c[maxn][maxn];
int ans[maxn][maxn];
void preProc(int k)
{
    c[0][0] = c[1][0] = c[1][1] = 1;
    for (int i = 2; i <= 2000; ++i)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j)
        {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % k;
            ans[i][j] = ans[i - 1][j] + ans[i][j - 1] - ans[i - 1][j - 1];
            if (!c[i][j])
                ans[i][j]++;
        }
        ans[i][i + 1] = ans[i][i];
    }
}
int main()
{
    int t, k;
    int n, m;
    cin >> t >> k;
    preProc(k);

    while (t--)
    {
        cin >> n >> m;
        if (m > n)
            cout << ans[n][n] << endl;

        else
            cout << ans[n][m] << endl;
    }
}