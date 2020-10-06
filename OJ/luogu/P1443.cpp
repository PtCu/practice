#include <bits/stdc++.h>
using namespace std;
const int dxy[][2] = {{1, 2}, {1, -2}, {2, -1}, {2, 1}, {-1, 2}, {-1, -2}, {-2, -1}, {-2, 1}};
const int maxn = 402;
int mat[maxn][maxn];
bool been[maxn][maxn];
struct Point
{
    int x, y;
    int step;
    Point() {}
    Point(int _x, int _y) : x(_x), y(_y) {}
};
int main()
{
    int n, m, sx, sy;
    cin >> n >> m >> sx >> sy;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mat[i][j] = -1;
        }
    }
    sx -= 1;
    sy -= 1;
    mat[sx][sy] = 0;
    queue<Point> Q;
    Q.push(Point(sx, sy));
    while (!Q.empty())
    {
        Point p = Q.front();
        Q.pop();
        int x = p.x;
        int y = p.y;
        for (int i = 0; i < 8; i++)
        {
            if (x + dxy[i][0] >= 0 && x + dxy[i][0] < n && y + dxy[i][1] >= 0 && y + dxy[i][1] < m && mat[x + dxy[i][0]][y + dxy[i][1]] == -1)
            {
                mat[x + dxy[i][0]][y + dxy[i][1]] = mat[x][y] + 1;
                Q.push(Point(x + dxy[i][0], y + dxy[i][1]));
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout <<setiosflags(ios::left)<<setw(5)<< mat[i][j];
        }
        cout << endl;
    }
}