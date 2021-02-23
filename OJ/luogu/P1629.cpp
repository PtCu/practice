#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
struct Edge
{
    int to, cost;
};
vector<Edge> G[maxn];
vector<Edge> G2[maxn];
using P = pair<int, int>; //第一个距离，第二个编号
int D[maxn];
int D2[maxn];
bool visited[maxn];
void Dijkstra(int s, vector<Edge>* G, int *D)
{
    memset(visited, 0, sizeof(visited));
    fill(D, D + maxn, INT_MAX);
    D[s] = 0;
    priority_queue<P, vector<P>, greater<P>> Q;
    Q.push({0, s});
    while (!Q.empty())
    {
        P cur = Q.top();
        Q.pop();
        if (visited[cur.second])
            continue;
        visited[cur.second] = 1;
        for (int i = 0; i < G[cur.second].size(); ++i)
        {
            Edge e = G[cur.second][i];
            if (D[e.to] > D[cur.second] + e.cost)
            {
                D[e.to] = D[cur.second] + e.cost;
                Q.push({D[e.to], e.to});
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    int a, b, c;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b >> c;
        G[a].push_back({b, c});
        G2[b].push_back({a, c});
    }
    Dijkstra(1, G, D);
    Dijkstra(1, G2, D2);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans += (D[i] + D2[i]);
    }
    cout << ans;
}