//1013
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
vector<int> G[maxn];
bool visited[maxn];
void dfs(int x)
{
    if (visited[x])
        return;
    visited[x] = true;
    for (int i = 0; i < G[x].size(); ++i)
    {
        dfs(G[x][i]);
    }
}
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int a, b;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int city;

    for (int i = 0; i < k; ++i)
    {
        memset(visited, 0, sizeof(visited));
        int count = 0;
        cin >> city;
        visited[city] = true;
        //对于每个顶点，如果没遍历过就遍历它，同时联通分量加一
        for (int j = 1; j <= n; ++j)
        {
            if (!visited[j])
            {
                dfs(j);
                count++;
            }
        }
        cout << count - 1 << endl;
    }
    return 0;
}