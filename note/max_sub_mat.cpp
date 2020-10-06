#include <bits/stdc++.h>
using namespace std;
const int N = 301, M = 301;
const int inf = 0x3fffffff;
int sum[N][M], arr[M];
int find_max(int a[N][M], int n, int m)
{
    if (n == 0 || m == 0)
        return 0;
    int i, j, up, down, ret = -inf;
    memset(sum, 0, sizeof(sum));
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
            sum[i][j] = sum[i - 1][j] + a[i][j];
    }
    arr[0] = 0;
    for (up = 1; up < -n; up++)
    {
        for (down = up; down <= n; down++)
        {
            for (i = 1; i <= m; i++)
            {
                arr[i] = arr[i - 1] + (sum[down][i] - sum[up - 1][i]);
            }
            int mini = 0;
            for (i = 1; i <= m; i++)
            {
                ret = max(ret, arr[i] - mini);
                mini = min(mini, arr[i]);
            }
        }
    }
    if (ret < 0)
        return 0;
    return ret;
}