#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
bool G[maxn][maxn][maxn];
long dis[maxn][maxn];
int n;
void Floyed()
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            for (int k = 1; k <= n; ++k)
            {
                if (dis[i][k] + dis[k][j] < 0)
                    continue;
                dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);
            }
        }
    }
}
int main()
{
    int m;
    cin >> n >> m;
    int u, v;
    memset(G, 0, sizeof(G));
    fill(dis[0], dis[0] + maxn * maxn, INT_MAX);
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v;
        G[u][v][0] = 1;
        dis[u][v] = 1;
    }
    for (int k = 1; k <= 64; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                for (int t = 1; t <= n; ++t)
                {

                    if (G[i][t][k - 1] && G[t][j][k - 1])
                    {
                        G[i][j][k] = 1;
                        dis[i][j] = 1;
                    }
                }
            }
        }
    }
    Floyed();
    cout << dis[1][n];
}