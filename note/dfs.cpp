#include <bits/stdc++.h>
//输入一个m行n列的字符矩阵，统计字符“@”组成多少个八连块
//种子填充
const int maxn = 100 + 5;

char pic[maxn][maxn];
int m, n, idx[maxn][maxn];

void dfs(int r, int c, int id)
{
    if (r < 0 || r >= m || c < 0 || c >= n) //出界的格子
        return;
    if (idx[r][c] > 0 || pic[r][c] != '@')  //不是@或者已经访问过的格子
        return;
    idx[r][c] = id; //连通分量编号
    for (int dr = -1; dr <= 1; dr++)
        for (int dc = -1; dc <= 1; dc++)
            if (dr != 0 || dc != 0)
                dfs(r + dr, c + dc, id);
}

int main()
{
    while (scanf("%d%d", &m, &n) == 2 && m && n)
    {
        for (int i = 0; i < m; i++)
            scanf("%s", pic[i]);
        memset(idx, 0, sizeof(idx));
        int cnt = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (idx[i][j] == 0 && pic[i][j] == '@')
                    dfs(i, j, ++cnt);
        printf("%d\n", cnt);
    }
    return 0;
}