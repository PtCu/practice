//普通搜索
// #include <bits/stdc++.h>
// using namespace std;
// int contour[100][100];
// int dx[4] = {0, 0, 1, -1};
// int dy[4] = {1, -1, 0, 0};
// int r, c, ans;
// void dfs(int x, int y, int length)
// {

//     ans = max(ans, length);

//     for (int i = 0; i < 4; i++)
//     {
//         int nextX = x + dx[i], nextY = y + dy[i];
//         if ((nextX) < r && (nextX) >= 0 && (nextY) < c && ((nextY) >= 0))
//         {
//             if (contour[nextX][nextY] < contour[x][y])
//                 dfs(nextX, nextY, length + 1);
//         }
//     }
// }
// int main()
// {

//     cin >> r >> c;
//     for (int i = 0; i < r; i++)
//     {
//         for (int j = 0; j < c; j++)
//             cin >> contour[i][j];
//     }
//     for (int i = 0; i < r; i++)
//     {
//         for (int j = 0; j < c; j++)
//             {
//                 dfs(i, j, 1);}
//     }
//     cout << ans;
// }
#include <bits/stdc++.h>
using namespace std;
int contour[100][100], cache[100][100];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int r, c, ans;
int dfs(int x, int y)
{

    if (cache[x][y])
        return cache[x][y];
        //刚开始为第一步
    cache[x][y]=1;
    for (int i = 0; i < 4; i++)
    {
        int nextX = x + dx[i], nextY = y + dy[i];
        if (nextX < r && nextX >= 0 && nextY < c && nextY >= 0)
        {
            if (contour[nextX][nextY] < contour[x][y])
                dfs(nextX, nextY); 
                //更新该点信息
                cache[x][y]=max(cache[x][y],cache[nextX][nextY]+1);
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
            ans=max(ans,dfs(i, j));
        }
    }
    cout << ans;
}