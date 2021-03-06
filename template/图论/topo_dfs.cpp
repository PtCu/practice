#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1000 + 10;
const int INF = 1e9 + 7;
int T, n, m, cases;
vector<int> Map[maxn];
int c[maxn]; //标记数组c[i] = 0 表示还未访问过点i， c[i] = 1表示已经访问过点i，并且还递归访问过它的所有子孙，c[i] = -1表示正在访问中，尚未返回
int topo[maxn], t;
bool dfs(int u) //从u出发
{
    c[u] = -1; //访问标志
    for (int i = 0; i < Map[u].size(); i++)
    {
        int v = Map[u][i];
        if (c[v] < 0)
            return false; //如果子孙比父亲先访问，说明存在有向环，失败退出
        else if (!c[v] && !dfs(v))
            return false; //如果子孙未被访问，访问子孙返回假，说明也是失败
    }
    c[u] = 1;

    //此处可用栈
    topo[--t] = u; //在递归结束才加入topo排序中，这是由于在最深层次递归中，已经访问到了尽头，此时才是拓扑排序中的最后一个元素
    return true;
}
bool toposort()
{
    t = n;
    memset(c, 0, sizeof(c));
    for (int u = 1; u <= n; u++)
        if (!c[u])
            if (!dfs(u))
                return false;
    return true;
}
int main()
{
    while (cin >> n >> m)
    {
        if (!n && !m)
            break;
        int u, v;
        for (int i = 0; i <= n; i++)
            Map[i].clear();
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            Map[u].push_back(v);
        }
        if (toposort())
        {
            cout << "Great! There is not cycle." << endl;
            for (int i = 0; i < n; i++)
                cout << topo[i] << " ";
            cout << endl;
        }
        else
            cout << "Network has a cycle!" << endl;
    }
    return 0;
}