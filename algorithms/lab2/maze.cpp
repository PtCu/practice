#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
int maze[maxn][maxn];
int n;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
void Solution()
{
    stack<pair<int, int>> S;
    S.push(make_pair(1, 1));
    while (!S.empty())
    {
        pair<int, int> p = S.top();
        S.pop();
        for (int i = 0; i < 4; i++)
        {
            if (!maze[p.first + dx[i]][p.second + dy[i]])
            {
                if (p.first + dx[i] == 8 && p.second + dy[i])
                {
                    
                                }
                S.push(make_pair(p.first + dx[i], p.second + dy[i]));
            }
        }
        
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> maze[i][j];
        }
    }
}