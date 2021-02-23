#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+ 10;
const int P = 100003;
vector<int> G[maxn];
int path_num[maxn];
bool visited[maxn];
int depth[maxn];
void bfs()
{
    queue<int> Q;
    Q.push(1);
    depth[1] = 1;
    visited[1] = 1;
    path_num[1] = 1;
    while (!Q.empty())
    {
        int p = Q.front();
        Q.pop();
        for (int i = 0; i < G[p].size(); ++i)
        {
            if (!visited[G[p][i]])
            {
                depth[G[p][i]] = depth[p] + 1;
                visited[G[p][i]] = 1;
                Q.push(G[p][i]);
            }

            if (depth[G[p][i]] == depth[p] + 1)
            {
                path_num[G[p][i]] =( path_num[G[p][i]]+path_num[p])% P;
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    int x, y;
    for (int i = 1; i <= m; ++i)
    {
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    bfs();
    for (int i = 1; i <= n; ++i)
    {
        cout << path_num[i] << endl;
    }
}
