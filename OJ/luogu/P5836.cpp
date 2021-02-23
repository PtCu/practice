#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int f[maxn];
char col[maxn];
int ans[maxn];
int find(int x)
{
    if (f[x] == x)
        return x;
    return f[x] = find(f[x]);
}
void Union(int a, int b)
{
    f[find(a)] = find(b);
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        f[i] = i;
        cin >> col[i];
    }
    int a, b;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> a >> b;
        if (col[a] == col[b]) //只要记录树上一个个颜色相同的连通块
            Union(a, b);
    }
    char c;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        cin >> c;
        if (find(a) == find(b) && col[a] != c) //只有当所查询两点是同一连通块且连通块颜色与目标颜色不同时输出0。
            ans[i] = 0;
        else
            ans[i] = 1;
    }
    for (int i = 0; i < m; ++i)
    {
        cout << ans[i];
    }
}