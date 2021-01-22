#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+500;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
int n, m;
int vis[maxn][maxn][3]; //vis[i][j][0]表示是否走过(i,j)
bool a[maxn][maxn];
bool out;
// 记录取模的横纵坐标x, y时，同时记录没有取模的坐标lx, ly

// 当第一次走这个迷宫的时候，x, y和lx, ly肯定是分别相等的

// 所以只要走到的一个点的x, y和lx, ly不相等（x!=lx || y!=ly），那这个点一定是被走了第二遍.
void dfs(int x, int y, int lx, int ly)
{
    if (out)
        return;
    //vis[x][y][0]为1说明之前走过。如果不一样，就说明可以无限走下去
    if (vis[x][y][0] && (vis[x][y][1] != lx || vis[x][y][2] != ly))
    {
        out = true;
        return;
    }
    //标记这点为走过，同时记录未取模的值
    vis[x][y][1] = lx, vis[x][y][2] = ly, vis[x][y][0] = 1;
    for (int i = 0; i < 4; ++i)
    {
        //取下一个点，取模并继续走
        int next_x = (x + dx[i] + n) % n, next_y = (y + dy[i] + m) % m;
        int next_lx = lx + dx[i], next_ly = ly + dy[i];
        //如果没有障碍物
        if (!a[next_x][next_y])
        {
            if (vis[next_x][next_y][1] != next_lx || vis[next_x][next_y][2] != next_ly || !vis[next_x][next_y][0])
                dfs(next_x, next_y, next_lx, next_ly);
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
        out = false;
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
        if (out)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}