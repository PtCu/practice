#include <bits/stdc++.h>
using namespace std;
char maze[300][300];
bool visited[300][300];
struct Point
{
    int x, y, steps;
    Point(const int &fx, const int &fy, const int &s = 0) : x(fx), y(fy), steps(s) {}
    Point() {}
};
const int dr[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main()
{
    int n, m;
    cin >> n >> m;
    queue<Point> Q;
    unordered_map<char, pair<Point, Point>> maps;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> maze[i][j];
            if (maze[i][j] == '@')
                Q.push(Point(i, j));
            if (isalpha(maze[i][j]))
            {
                if (maps.count(maze[i][j]))
                    maps[maze[i][j]].second = Point(i, j);
                else
                {
                    maps[maze[i][j]] = make_pair(Point(i, j), Point());
                }
            }
        }
    }
    while (!Q.empty())
    {
        Point p = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            int dx = dr[i][0];
            int dy = dr[i][1];

            int x = p.x + dx, y = p.y + dy;
            if (x < 0 || x >= n || y < 0 || y >= m)
                continue;
            if (maps.count(maze[x][y]))
            {
                Point q;
                if (x == maps[maze[x][y]].first.x && y == maps[maze[x][y]].first.y)
                    q = maps[maze[x][y]].second;
                else
                    q = maps[maze[x][y]].first;
                q.steps=p.steps+1;
                Q.push(q);
            }
            else if (maze[x][y] == '.' && !visited[x][y])
            {
                Q.push(Point(x, y, p.steps + 1));
                visited[x][y] = true;
            }
            else if (maze[x][y] == '=')
            {
                cout << p.steps + 1;
                return 0;
            }
        }
    }
}