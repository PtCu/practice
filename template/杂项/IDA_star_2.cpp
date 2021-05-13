//https://www.luogu.com.cn/problem/solution/P1379
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read()
{
    ll f = 1, x = 0;
    char ch;
    do
    {
        ch = getchar();
        if (ch == '-')
            f = -1;
    } while (ch > '9' || ch < '0');
    do
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    } while (ch >= '0' && ch <= '9');
    return f * x;
}

char s[15];

char goal[] = {'1', '2', '3', '8', '0', '4', '7', '6', '5'};

int maxdepth;

inline int h(char *cur)
{
    int res = 0;
    for (int i = 0; i < 9; i++)
    {
        if (goal[i] != cur[i] && cur[i] != 0)
            res++;
    }
    return res;
}

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

bool dfs(int depth, char *a, int pre)
{
    if (h(a) == 0)
        return true;
    //这里做了限制，使得和普通的dfs不同
    if (depth + h(a) - 1 > maxdepth)
        return false;
    int sx, sy;
    for (int i = 0; i < 9; i++)
        if (a[i] == '0')
            sx = i / 3 + 1, sy = i % 3 + 1;
    for (int i = 0; i < 4; i++)
    {
        int xx = dx[i] + sx, yy = dy[i] + sy;
        if (xx < 1 || xx > 3 || yy < 1 || yy > 3 || (pre + i == 3))
            continue;
        swap(a[(xx - 1) * 3 + yy - 1], a[(sx - 1) * 3 + sy - 1]);
        if (dfs(depth + 1, a, i))
            return true;
        swap(a[(xx - 1) * 3 + yy - 1], a[(sx - 1) * 3 + sy - 1]);
    }
    return false;
}

int main()
{
    scanf("%s", s);
    if (h(s) == 0)
    {
        puts("0");
        return 0;
    }
    for (maxdepth = 1;; maxdepth++)
    {
        if (dfs(0, s, -1))
        {
            printf("%d\n", maxdepth);
            return 0;
        }
    }
    return 0;
}
