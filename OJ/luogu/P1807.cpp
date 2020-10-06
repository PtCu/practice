#include <bits/stdc++.h>
using namespace std;
const int MAX = 1500;
int d[MAX];   //表示从源点s到顶点i的最短路
int inq[MAX]; //顶点i在不在队列中
struct edge
{
    int to;
    int weight;
};
vector<edge> G[MAX];
//spfa
void bfs(int s)
{
    memset(d, -1, sizeof(d));
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i].to;
            if (d[v] < d[u] + G[u][i].weight)
            {
                d[v] = d[u] + G[u][i].weight;
                q.push(v);
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
    }
    bfs(1);
    cout << d[n];
}