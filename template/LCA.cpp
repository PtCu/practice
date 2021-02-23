//P3379  倍增
#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e6 + 10;
vector<int> G[maxn];
int depth[maxn];
int fa[maxn][31]; //fa[i][j]存的[i]向上走2的j次方那么长的路径所到的祖先
void dfs(int root, int fno) //fno为其父亲节点。0表示没有父亲节点，也就是根节点
{
    fa[root][0] = fno;
    depth[root] = depth[fa[root][0]] + 1;
    for (int i = 1; (1 << i) <= depth[root]; i++)
    {
        fa[root][i] = fa[fa[root][i - 1]][i - 1]; //2^i=2^(i-1)+2^(i-1)
    }
    for (int i = 0; i < G[root].size(); ++i)
    {
        int v = G[root][i];
        if (v != fno)
            dfs(v, root);
    }
}
int lca(int a, int b)
{
    if (depth[a] > depth[b])
    {
        swap(a, b); //保证a是在b结点上方，即a的深度小于b的深度
    }
    for (int i = 20; i >= 0; i--) //先把b移到和a同一个深度
    {
        if (depth[a] <= depth[b] - (1 << i))
        {
            b = fa[b][i];
        }
    }
    if (a == b)  //特判，如果b上来和就和a一样了，那就可以直接返回答案了
    {
        return a;
    }
    for (int i = 20; i >= 0; i--)
    {
        if (fa[a][i] == fa[b][i])
            continue;
        else
            a = fa[a][i], b = fa[b][i]; //A和B一起上移
    }
    return fa[a][0]; //找出最后a值的数字
}
int main()
{
    int n, m, s;
    cin >> n >> m >> s;
    int x, y;
    for (int i = 0; i < n-1; ++i)
    {
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(s, 0);
    int a, b;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b;
        cout << lca(a, b)<<endl;
    }
    return 0;
}