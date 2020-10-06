#include <bits/stdc++.h>
using namespace std;
const int maxn = 305;
int land[maxn][maxn];
bool been[maxn][maxn];
int dx[] = {0, 1, -1, 0, 0};
int dy[] = {0, 0, 0, 1, -1};
struct Point
{
    int x, y, t;
    Point() {}
    Point(int _x, int _y, int _t) : x(_x), y(_y), t(_t) {}
};
int main()
{
    int n;
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < maxn; i++)
    {
        for (int j = 0; j < maxn; j++)
            land[i][j] = -1;
    }
    int x, y, t;
    int x_, y_;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y >> t;
        for (int j = 0; j < 5; j++)
        {
            x_ = dx[j] + x;
            y_ = dy[j] + y;
            if (x_ >= 0 && y_ >= 0 && (land[x_][y_] == -1 || land[x_][y_] > t))
                land[x_][y_] = t;
        }
    }
    queue<Point> q;
    q.push(Point(0, 0, 0));
    been[0][0] = true; //bsf判断是否遍历过
    while (!q.empty())
    {
        Point p = q.front();
        q.pop();
        for (int i = 1; i < 5; i++)
        {
            x_ = p.x + dx[i];
            y_ = p.y + dy[i];
            if (x_ >= 0 && y_ >= 0 && !been[x_][y_] && (land[x_][y_] == -1 || land[x_][y_] > p.t + 1))
            {
                Point s(x_, y_, p.t + 1);
                been[x_][y_] = true;
                q.push(s);
                if (land[x_][y_] == -1)
                {
                    cout << s.t << endl;
                    return 0;
                }
            }
        }
        
    }
    cout << -1 << endl;
    return 0;
}