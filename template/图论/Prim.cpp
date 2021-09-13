//https://blog.csdn.net/qq_33769475/article/details/98449393
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
//prim更新的是未标记集合到已标记集合之间的距离(G[cur.second][i].cost)
//Dijkstra更新的是源点到未标记集合之间的距离(G[cur.second][i].cost+D[cur.second])
//注意与Dijkstra的区别
int D[maxn]; //源点到其他点的距离
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
            //这里与Dijkstra不同，只比较cost和D[to]
            if (D[to] > cost)
            {
                D[to] = cost;
                Q.push({D[to], to});
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        sum += D[i];
    }
}