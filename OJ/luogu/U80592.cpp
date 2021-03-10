#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
const long long P = 998244354;
int n, m; //n个点，m条边
long long D[maxn][maxn];
void Floyd()
{
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    long long a, b, w;
    fill(D[0], D[0] + maxn * maxn, INT_MAX);
    for (int i = 1; i <= n; ++i)
    {
        D[i][i] = 0;
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b >> w;
        //判重边
        D[a][b] = D[b][a] = min(D[b][a],w);
    }
    Floyd();
    for (int i = 1; i <= n; ++i)
    {
        long long ans = 0;
        for (int j = 1; j <= n; ++j)
        {
            ans = (ans + D[i][j]) % P;
        }
        cout << ans << endl;
    }
}