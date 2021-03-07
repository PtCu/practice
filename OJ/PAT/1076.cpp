#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 20;
vector<int> G[maxn];
int n, L;
int cnt = 0;
//dfs过程中不是只要visit过就跳过，还要注意当前层级是否到达了L，
//因为从不同路径到达同一个节点时的深度可能不同。有可能第一次到不了的，第二次某条路可以到达。

int visited[1005];

void dfs(int x, int depth)
{
    //第一次到达
    if (visited[x] == -1)
    {
        visited[x] = depth;
        cnt++;
    }
    //后续又到达
    else
    {
        visited[x] = min(depth, visited[x]);
    }
    for (auto f : G[x])
    {
        //在此处判断并返回。
        if (depth + 1 > L || (visited[f] != -1 && depth + 1 >= visited[f]))
        {
            continue;
        }
        dfs(f, depth + 1);
    }
}
int query(int s)
{
    memset(visited, -1, sizeof(visited));
    cnt = -1;
    dfs(s, 0);
    return cnt;
}
int main()
{
    int m, x;
    cin >> n >> L;
    for (int i = 1; i <= n; ++i)
    {
        cin >> m;
        for (int j = 1; j <= m; ++j)
        {
            cin >> x;
            G[x].push_back(i);
        }
    }
    int k;
    cin >> k;
    for (int i = 1; i <= k; ++i)
    {
        cin >> x;
        cout << query(x) << endl;
    }
}