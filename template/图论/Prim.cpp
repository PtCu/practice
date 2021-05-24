#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 10;
typedef pair<int, int> P;
struct Edge
{
    int to, cost;
    Edge(int t, int c) : to(t), cost(c)
    {
    }
};

int n, m;
vector<Edge> G[maxn];
int D[maxn];
bool visited[maxn];
int Prim(int s)
{
    int sum = 0;
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
            int to = G[cur.second][i].to;
            int cost = G[cur.second][i].cost;
            if (D[to] > D[cur.second] + cost)
            {
                D[to] = D[cur.second] + cost;
                Q.push({D[to], to});
            }
        }
    }
    //与Dijkstra相比多了个求和
    for (int i = 0; i < n; ++i)
    {
        sum += D[i];
    }
}