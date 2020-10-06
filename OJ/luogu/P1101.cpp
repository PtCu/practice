#include <bits/stdc++.h>
using namespace std;
int n;
const int maxn = 102;
char mat[maxn][maxn];
char ans[maxn][maxn];
const string cmp = "yizhong";
const int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
const int dy[8] = {1, -1, 0, 0, 1, 1, -1, -1};
bool valid(char c, char after)
{
    bool isOk = false;
    switch (c)
    {
    case 'y':
        after == 'i' ? isOk = true : isOk = false;
        break;
    case 'i':
        after == 'z' ? isOk = true : isOk = false;
        break;
    case 'z':
        after == 'h' ? isOk = true : isOk = false;
        break;
    case 'h':
        after == 'o' ? isOk = true : isOk = false;
        break;
    case 'o':
        after == 'n' ? isOk = true : isOk = false;
        break;
    case 'n':
        after == 'g' ? isOk = true : isOk = false;
        break;
    default:
        break;
    }
    return isOk;
}
void dfs(int x, int y)
{
    for (int i = 0; i < 8; i++)
    {
        bool isOk = true;
        for (int j = 0; j <= 6;j++){
            int nx = dx[i] * j + x;
            int ny = dy[i] * j + y;
            if(nx<0||nx>=n||ny<0||ny>=n)
            {
                isOk = false;
                break;
            }
            if(cmp[j]!=mat[nx][ny]){
                isOk = false;
                break;
            }
        }
        if(!isOk)
            continue;
        for (int j = 0; j <= 6;j++){
            int nx = x + j * dx[i];
            int ny = y + j * dy[i];
            ans[nx][ny] = mat[nx][ny];
        }
    }
    return;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (mat[i][j] == 'y')
                dfs(i, j); //如果发现有y就开始搜索
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(ans[i][j]==0)
                ans[i][j] = '*';
            cout << ans[i][j];
        }
        cout << endl;
    }
}