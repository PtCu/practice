#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 10;
int f[maxn];
struct Edge
{
    int u, v;
    int cost;
    Edge(int _u, int _v, int _c) : u(_u), v(_v), cost(_c) {}
    bool operator<(const Edge &e) const
    {
        return cost < e.cost;
    }
};

//这里要对边权进行排序，所以用边的集合来表示整个图。
vector<Edge> G;
//n为点数，m为边数
int n, m;
void Union(int a, int b)
{
    int fa = Find(a);
    int fb = Find(b);
    if (fa != fb)
        f[fa] = fb;
}

int Find(int x)
{
    if (f[x] == x)
        return x;
    return f[x] = Find(f[x]);
}
// 需要解决两个问题：
//（1）如何判断测试边的两个端点是否在不同的连通块中；
//（2）如何将测试边加入到最小生成树中；
// 这里用并查集来表示连通块，测试顶点是否联通
// 时间复杂度O(mlogm)
int Krustal()
{
    //最小生成树的权重之和
    int sum = 0;
    for (int i = 0; i < n; ++i)
        f[i] = i;
    //边的个数
    int cnt = 0;
    sort(G.begin(), G.end());
    for (int i = 0; i < m; ++i)
    {
        int f_u = Find(G[i].u);
        int f_v = Find(G[i].v);
        if (f_u != f_v)
        {
            Union(f_u, f_v);
            sum += G[i].cost;
            cnt++;
            if (cnt == n - 1)
                break;
        }
    }
    if (cnt != n - 1)
        return -1;
    else
        return sum;
}
int main()
{
    
}