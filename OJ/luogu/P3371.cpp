#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
#define MAX 2147483647
struct Edge
{
    int to;
    int cost;
    Edge(int _to, int _cost) : to(_to), cost(_cost) {}
};
vector<Edge> G[maxn];
using P = pair<int, int>; //第一个长度，第二个编号
int D[maxn];              //到其他点的距离
bool visited[maxn];
void Dijkstra(int s)
{
    priority_queue<P, vector<P>, greater<P>> Q;
    fill(D, D + maxn, MAX);
    D[s] = 0;
    Q.push({0, s});
    while (!Q.empty())
    {
        P p = Q.top();
        Q.pop();
        if (visited[p.second])
            continue;
        visited[p.second] = 1;
        for (int i = 0; i < G[p.second].size(); ++i)
        {
            Edge e = G[p.second][i];
            if (D[e.to] > D[p.second] + e.cost)
            {
                D[e.to] = D[p.second] + e.cost;
                Q.push({D[e.to], e.to});
            }
        }
    }
}
int main()
{
    int n, m, s;
    cin >> n >> m >> s;
    int a, b, c;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b >> c;
        G[a].push_back({b, c});
       
    }
    Dijkstra(s);
    for (int i = 1; i <= n; ++i)
    {
        cout << D[i] << " ";
    }
}