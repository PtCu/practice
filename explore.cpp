#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 10;
struct Edge
{
    int u, v, cost;
    Edge(int _u, int _v, int _c) : u(_u), v(_v), cost(_c) {}
    bool operator<(const Edge &e) const
    {
        return cost < e.cost;
    }
};
vector<Edge> G;
int n, m;
int f[maxn];
void Union(int a, int b)
{
    int x = Find(a);
    int y = Find(b);
    if (x == y)
        return;
    f[x] = y;
}
int Find(int x)
{
    return x == f[x] ? x : f[x] = Find(f[x]);
}
int Krustal()
{
    sort(G.begin(), G.end());
    for (int i = 0; i < n; ++i)
    {
        f[i] = i;
    }
    int cnt = 0;
    int sum = 0;
    for (int i = 0; i < m; ++i)
    {
        int f_u = Find(G[i].u);
        int f_v = Find(G[i].v);
        if(f_u!=f_v){
            Union(f_u, f_v);
            cnt++;
            sum += G[i].cost;
        }
        if(cnt==n-1)
            break;
    }
    if(cnt!=n-1)
        return -1;
    return sum;
}
int main()
{
}