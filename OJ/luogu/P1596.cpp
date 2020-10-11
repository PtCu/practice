#include <bits/stdc++.h>
using namespace std;
const int maxn = 102;
char grid[maxn][maxn];
int idx[maxn][maxn];
int n, m;
void dfs(int i, int j, int id)
{
    if (i < 0 || i >= n || j < 0 || j >= m) //越界
        return;
    if (grid[i][j] == '.' || idx[i][j] > 0)
        return;
    idx[i][j] = id;
    for (int dx = -1; dx <= 1; dx++)
        for (int dy = -1; dy <= 1; dy++)
        {
            if (dx || dy)
                dfs(i + dx, j + dy, id);
        }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", grid[i]);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'W' && !idx[i][j])
                dfs(i, j, ++cnt);
        }
    }
    cout << cnt;
}