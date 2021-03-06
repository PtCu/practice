//反向建边的例题：
//比如有向图中已知a可以到达b，求可以到达b的点
//可以通过反向建边，从b点出发，所有访问过的都是可以到达b的
//luogu3916
#include <bits/stdc++.h>
using namespace std;
const int XN = 1e5+100;
vector<int> G[XN];
int a[XN];
void dfs(int k, int x)
{
    if (a[x])
        return;
    a[x] = k;
    for (int i = 0; i < G[x].size(); i++)
    {
        dfs(k, G[x][i]);
    }
}
//有向图，反着建边
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        //反向建边
        G[v].push_back(u);
    }
    for (int i = n; i >= 1; i--)
        dfs(i, i);
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
}