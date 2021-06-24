
#include <bits/stdc++.h>
using namespace std;
int contour[201][201], cache[201][201];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int r, c, ans;
//记忆化搜索
int dfs(int x, int y)
{
    if (cache[x][y])
        return cache[x][y];
    //刚开始为第一步
    cache[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nextX = x + dx[i], nextY = y + dy[i];
        if (nextX < r && nextX >= 0 && nextY < c && nextY >= 0)
        {
            if (contour[nextX][nextY] < contour[x][y])
                //更新该点信息
                cache[x][y] = max(cache[x][y], dfs(nextX,nextY) + 1);
        }
    }
    return cache[x][y];
}
int main()
{

    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cin >> contour[i][j];
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            ans = max(ans, dfs(i, j));
        }
    }
    cout << ans;
}