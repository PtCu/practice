#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 100;
constexpr int dest_x = 8;
constexpr int dest_y = 8;
int maze[maxn][maxn] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 1, 1, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
    {1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
bool visited[maxn][maxn];
int n;
//方向
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};
vector<pair<int, int>> path;

void Solution()
{
    stack<pair<int, int>> S;
    //起点入栈
    S.push(make_pair(1, 1));
    path.push_back(make_pair(1, 1));
    visited[1][1] = true;
    while (!S.empty())
    {
        pair<int, int> p = S.top();
        //如果到达目的地
        if (p.first == dest_x && p.second == dest_y)
        {
            //输出路径
            cout << "路径为:" << endl;
            for (auto j : path)
            {
                maze[j.first][j.second] = -1;
                cout << "(" << j.first << "," << j.second << ") ";
            }
            cout << endl;
            return;
        }
        int n_x, n_y;
        //朝四个方向试探
        bool step = false; //是否有路可走
        for (int i = 0; i < 4; ++i)
        {
            n_x = p.first + dx[i], n_y = p.second + dy[i];
            //如果该方向没有障碍物且没被访问过
            if (!maze[n_x][n_y] && !visited[n_x][n_y])
            {
                //压栈，并记录路径
                visited[n_x][n_y] = true;
                step = true; //有路可走
                S.push(make_pair(n_x, n_y));
                path.push_back(make_pair(n_x, n_y));
                break;
            }
        }
        //回溯
        if (!step)
        {
            S.pop();
            path.pop_back();
        }
    }
}
int main()
{
    // cin >> n;
    // for (int i = 0; i < n; ++i)
    // {
    //     for (int j = 0; j < n; ++j)
    //     {
    //         cin >> maze[i][j];
    //     }
    // }
    Solution();
    n = 10;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (maze[i][j] == -1)
            {
                cout << '*' << " ";
            }
            else
                cout << maze[i][j] << " ";
        }
        cout << endl;
    }
}