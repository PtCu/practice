#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+500;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
int n, m;
int vis[maxn][maxn][3]; //vis[i][j][0]表示是否走过(i,j)
bool a[maxn][maxn];
bool success;
void dfs(int x, int y, int lx, int ly)
{
    if (success)
        return;
    if (vis[x][y][0] && (vis[x][y][1] != lx || vis[x][y][2] != ly))
    {
        success = true;
        return;
    }
    vis[x][y][1] = lx, vis[x][y][2] = ly, vis[x][y][0] = 1;
    for (int i = 0; i < 4; ++i)
    {
        int xx = (x + dx[i] + n) % n, yy = (y + dy[i] + m) % m;
        int lxx = lx + dx[i], lyy = ly + dy[i];
        if (!a[xx][yy])
        {
            if (vis[xx][yy][1] != lxx || vis[xx][yy][2] != lyy || !vis[xx][yy][0])
                dfs(xx, yy, lxx, lyy);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    char ch;
    int start_x, start_y;
    while (cin >> n >> m)
    {
        success = false;
        memset(a, 0, sizeof(a));
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin >> ch;
                if (ch == '#')
                    a[i][j] = 1;
                if (ch == 'S')
                    start_x = i, start_y = j;
            }
        }
        dfs(start_x, start_y, start_x, start_y);
        if (success)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}