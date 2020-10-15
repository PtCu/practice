#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
const long long inf = 1e17 + 5;
int n, m, k;
int vis[maxn];
int head[maxn], degree[maxn], siz[maxn], tot;
struct Edge
{
    int to, next, val;
} edge[maxn * 2];
long long dp[maxn][105];

void addedge(int u, int v, int w)
{
    edge[++tot].to = v, edge[tot].val = w, edge[tot].next = head[u];
    head[u] = tot;
}

void init_edge()
{
    tot = 0;
    memset(head, -1, sizeof(head));
    memset(degree, 0, sizeof(degree));
    memset(siz, 0, sizeof(siz));
    memset(vis, 0, sizeof(vis));
}

void init_dp()
{
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 0;
        for (int j = 1; j <= m; j++)
            dp[i][j] = inf;
    }
    for (int i = 1; i <= n; i++)
        if (vis[i])
            siz[i] = 1, dp[i][1] = 0;
}

void dfs(int u, int pre)
{
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].to, w = edge[i].val;
        if (v == pre)
            continue;
        dfs(v, u);
        siz[u] += siz[v];
        for (int j = min(k, siz[u]); j >= 1; j--)
            for (int kk = 1; kk <= min(j, siz[v]); kk++)
                dp[u][j] = min(dp[u][j], dp[u][j - kk] + dp[v][kk] + 1ll * w * kk * (k - kk));
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    //freopen("c:\\in.txt", "r", stdin);
    int T = 1;
    while (T--)
    {
        init_edge();
        int rt = 1;
        cin >> n >> m >> k;
        for (int u, i = 1; i <= m; i++)
        {
            cin >> u;
            vis[u] = true;
        }
        for (int u, v, w, i = 1; i < n; i++)
        {
            cin >> u >> v >> w;
            addedge(u, v, w), addedge(v, u, w);
            degree[u]++, degree[v]++;
            if (degree[u] > 1)
                rt = u;
            if (degree[v] > 1)
                rt = v;
        }
        init_dp();
        dfs(rt, 0);
        cout << dp[rt][k] << "\n";
    }
    return 0;
}