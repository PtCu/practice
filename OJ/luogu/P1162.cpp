#include <bits/stdc++.h>
using namespace std;
const int maxn = 32;
int n;
char grid[maxn][maxn];
int idx[maxn][maxn];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

//填充外圈
//在最外圈加一层0
void dfs(int i, int j)
{
    if (i < 0 || i > n + 1 || j < 0 || j > n + 1) //越界
        return;
    if (idx[i][j] != 0) //走过这里或者撞墙
        return;
    idx[i][j] = 1; //标记这里走过了

    for (int k = 0; k < 4; k++)
    {
        dfs(i + dx[k], j + dy[k]);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == '1')
                idx[i][j] = 1;
        }
    }
    int cnt = 0;
    dfs(0, 0);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (idx[i][j] == 0)
                cout << 2 << " ";
            else
                cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}