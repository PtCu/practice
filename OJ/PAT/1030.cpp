#include <bits/stdc++.h>
using namespace std;
const int maxn = 510;
struct Edge
{
    int to, distance, cost;
    Edge(const int &_to, const int &_dis, const int &_co) : to(_to), distance(_dis), cost(_co) {}
};
vector<Edge> G[maxn];
using P = pair<int, int>; //第一个距离，第二个编号
int D[maxn];
int Cost[maxn];
bool visited[maxn];
vector<int> pre[maxn]; //前驱
void Dijkstra(int s)
{
    fill(D, D + maxn, INT_MAX);
    D[s] = 0;
    Cost[s] = 0;
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
            if (e.distance + D[cur.second] < D[e.to])
            {
                D[e.to] = e.distance + D[cur.second];
                Q.push({D[e.to], e.to});
                Cost[e.to] = e.cost + Cost[cur.second];
                pre[e.to].clear();
                pre[e.to].push_back(cur.second);
            }
            else if (e.distance + D[cur.second] == D[e.to])
            {
                if (Cost[e.to] > e.cost + Cost[cur.second])
                {
                    pre[e.to].clear();
                    pre[e.to].push_back(cur.second);
                    Cost[e.to] = e.cost + Cost[cur.second];
                }
            }
        }
    }
}
vector<int> path, tmp;
void dfs(int s, int d)
{
    path.push_back(s);
    for (int i = 0; i < pre[s].size(); ++i)
    {
        dfs(pre[s][i], d);
    }
    if (s == d)
    {
        for (int i = path.size() - 1; i >= 0; --i)
        {
            cout << path[i] << " ";
        }
    }
}
int main()
{
    int n, m, s, d;
    cin >> n >> m >> s >> d;
    int a, b, c, e;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b >> c >> e;
        G[a].push_back({b, c, e});
        G[b].push_back({a, c, e});
    }
    Dijkstra(s);
    dfs(d, s);
    cout << D[d] << " " << Cost[d];
}