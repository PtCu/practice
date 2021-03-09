#include <bits/stdc++.h>
using namespace std;
const int maxn = 128;
const int maxm = 1286;
const int maxl = 60;
bool mat[maxl][maxm][maxn];
bool visited[maxl][maxm][maxn];
int n, m, l, t;
int ans;
int max_size;
int dir[6][3] = {{0, 0, 1}, {0, 0, -1}, {0, 1, 0}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0}};
//dfs 爆栈
void dfs(int k, int i, int j)
{
    if (i < 0 || i >= m || j < 0 || j >= n || k < 0 || k >= l)
        return;
    if (mat[k][i][j] == false || visited[k][i][j])
        return;
    visited[k][i][j] = 1;
    ++max_size;
    for (int idx = 0; idx < 6; ++idx)
    {
        dfs(dir[idx][0] + k, dir[idx][1] + i, dir[idx][2] + j);
    }
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
                    max_size = 0;
                    dfs(k, i, j);
                    if (max_size >= t)
                        ans += max_size;
                }
            }
        }
    }
    cout << ans;
}