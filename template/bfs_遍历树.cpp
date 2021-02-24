//PAT 1021
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
vector<int> G[maxn];
int depth[maxn];
bool visited[maxn];
bool used[maxn];
int max_depth = 1;
vector<int> max_root;
void bfs(int x)
{
    memset(visited, 0, sizeof(visited));
    memset(depth, 0, sizeof(depth));
    queue<int> Q;
    depth[x] = 1;
    visited[x] = 1;
    used[x] = 1;
    Q.push(x);
    int tmp_max_depth = 1;
    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();
        for (int i = 0; i < G[cur].size(); ++i)
        {
            if (!visited[G[cur][i]])
            {
                visited[G[cur][i]] = 1;
                used[G[cur][i]] = 1;
                depth[G[cur][i]] = depth[cur] + 1;
                tmp_max_depth = max(tmp_max_depth, depth[G[cur][i]]);
                Q.push(G[cur][i]);
            }
        }
    }
    if (max_depth < tmp_max_depth)
    {
        max_depth = tmp_max_depth;
        max_root.clear();
        max_root.push_back(x);
    }
    else if (max_depth == tmp_max_depth)
    {
        max_root.push_back(x);
    }
}
int main()
{
    int n;
    cin >> n;
    int a, b;
    for (int i = 1; i <= n - 1; ++i)
    {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (!used[i])
        {
            cnt++;
        }
        bfs(i);
    }
    if (cnt != 1)
    {
        cout << "Error: " << cnt << " components";
    }
    else
    {
        for (int i = 0; i < max_root.size(); ++i)
        {
            cout << max_root[i] << endl;
        }
    }
}