#include <bits/stdc++.h>
using namespace std;
const int maxn = 510;
struct edge
{
    int to, cost;
};
vector<edge> G[maxn];
int D[maxn];
int p[maxn];
using P = pair<int, int>; //第一位为最小距离，第二位为最小距离对应的点
bool used[maxn];
int path_num[maxn]; //从s到i的最短路径数量
int t_nums[maxn];   //从s到i的team数量
void Dijkstra(int s)
{
    priority_queue<P, vector<P>, greater<P>> q;
    fill(D, D + maxn, INT_MAX);
    D[s] = 0;
    t_nums[s] = p[s];
    path_num[s] = 1;
    q.push({0, s});
    while (!q.empty())
    {
        P cur = q.top();
        q.pop();
        if (used[cur.second])
            continue;
        used[cur.second] = 1;
        for (int i = 0; i < G[cur.second].size(); ++i)
        {
            edge e = G[cur.second][i];
            if (D[e.to] > D[cur.second] + e.cost)
            {
                D[e.to] = D[cur.second] + e.cost;
                q.push({D[e.to], e.to});
                path_num[e.to] = path_num[cur.second];
                t_nums[e.to] = t_nums[cur.second] + p[e.to];
            }
            else if (D[e.to] == D[cur.second] + e.cost)
            {
                t_nums[e.to] = max(t_nums[e.to], t_nums[cur.second] + p[e.to]);
                path_num[e.to] += path_num[cur.second];
            }
        }
    }
}
int main()
{
    int n, m, c1, c2;
    cin >> n >> m >> c1 >> c2;
    for (int i = 0; i < n; ++i)
    {
        cin >> p[i];
    }
    int a, b, c;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b >> c;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }
    Dijkstra(c1);
    cout << path_num[c2]<<" "<< t_nums[c2];
    return 0;
}