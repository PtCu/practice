#include <bits/stdc++.h>
using namespace std;
const int maxn = 128;
const int maxm = 1286;
const int maxl = 60;
bool mat[maxl][maxm][maxn];
bool visited[maxl][maxm][maxn];
int n, m, l, t;
int ans;
int dir[6][3] = {{0, 0, 1}, {0, 0, -1}, {0, 1, 0}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0}};
struct Node
{
    int k, i, j;
};
int bfs(Node root)
{
    int vol = 0;
    queue<Node> Q;
    Q.push(root);
    while (!Q.empty())
    {
        Node p = Q.front();
        Q.pop();
        if (p.k >= l || p.k < 0 || p.i >= m || p.i < 0 || p.j >= n || p.j < 0)
            continue;
        if (visited[p.k][p.i][p.j] || mat[p.k][p.i][p.j] == 0)
            continue;
        visited[p.k][p.i][p.j] = 1;
        vol++;
        for (int i = 0; i < 6; ++i)
        {
            Q.push({p.k + dir[i][0], p.i + dir[i][1], p.j + dir[i][2]});
        }
    }
    return vol;
}
int main()
{

    cin >> m >> n >> l >> t;
    for (int k = 0; k < l; ++k)
    {
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin >> mat[k][i][j];
            }
        }
    }

    for (int k = 0; k < l; ++k)
    {
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (mat[k][i][j] && !visited[k][i][j])
                {
                    int si = bfs({k, i, j});
                    if (si >= t)
                        ans += si;;
                }
            }
        }
    }
    cout << ans;
}