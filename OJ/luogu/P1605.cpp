#include <bits/stdc++.h>
using namespace std;
struct Point
{
    int x, y;
    Point() {}
    Point(int _x, int _y) : x(_x), y(_y) {}
};
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
int ans = 0;
int n, m, t;
int sx, sy, fx, fy;
int dp[10][10];
void dfs(int x, int y)
{
    if (x == fx && y == fy)
    {
        ans += 1;
        return;
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            if ((x + dx[i] > 0) && (x + dx[i] <= n) && (y + dy[i] <= m) && (y + dy[i] > 0) && !dp[x + dx[i]][y + dy[i]])
            {
                dp[x + dx[i]][y + dy[i]] = 1;
                dfs(x + dx[i], y + dy[i]);
                dp[x + dx[i]][y + dy[i]] = 0;
            }
        }
    }
}
// void bfs()
{
    queue<Point> Q;
    Q.push(Point(sx, sy));

    while (!Q.empty())
    {
        Point p = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            if ((p.x + dx[i] > 0) && (p.x + dx[i] <= n) && (p.y + dy[i] <= m) && (p.y + dy[i] > 0) && !dp[p.x + dx[i]][p.y + dy[i]]) //如果没障碍物
            {
                dp[p.x + dx[i]][p.y + dy[i]] = 1;
                Q.push(Point(p.x + dx[i], p.y + dy[i]));
            }
            if (p.x==fx&&p.y==fy)
            {
                ans += 1;
            }
        }
        // dp[p.x][p.y] = 0;
    }
}
int main()
{
    // for (int i = 0; i < 10;i++){
    //     dp[i][0] = 1;
    //     dp[0][i] = 1;
    // }

    cin >> n >> m >> t;
    int sx, sy, fx, fy;
    cin >> sx >> sy >> fx >> fy;
    dp[sx][sy] = 1;
    // dp[fx][fy] = 2;
    int hx, hy;
    for (int i = 0; i < t; i++)
    {
        cin >> hx >> hy;
        dp[hx][hy] = 1;
    }
    dfs(sx, sy);
    cout << ans;
}