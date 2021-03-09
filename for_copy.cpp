#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
struct Edge
{
    int to, cost;
};
vector<Edge> G[maxn];
bool inQueue[maxn];
int D[maxn];
int n;
void spfa(int s)
{
    fill(D, D + maxn, INT_MAX);
    memset(inQueue, 0, sizeof(inQueue));
    D[s] = 0;
    queue<int> Q;
    Q.push(s);
    inQueue[s] = 1;
    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();
        inQueue[cur] = false;
        for (int i = 0; i < G[cur].size(); ++i)
        {
            Edge e = G[cur][i];
            int to = e.to;
            if (D[to] > D[cur] + e.cost)
            {
                D[to] = D[cur] + e.cost;
                if (inQueue[to] == 0)
                {
                    inQueue[to] = 1;
                    Q.push(to);
                }
            }
        }
    }
}
int main()
{
    int n, m, s;
    cin >> n >> m >> s;
    int u, v, w;
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v >> w;
        G[u].push_back({v, w});
    }
    spfa(s);
    for (int i = 1; i <= n; ++i)
    {
        cout << D[i] << " ";
    }
}