#include <bits/stdc++.h>
using namespace std;
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}
const int maxn = 1e5 + 10;
int Max[maxn][21];
int Log2[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    int n, m;
    n = read();
    m = read();
    for (int i = 1; i <= n; ++i)
    {
        Max[i][0] = read();
    }
    for (int i = 2; i <= n; ++i)
    {
        Log2[i] = Log2[i / 2] + 1;
    }
    for (int i = 1; i <= 21; ++i)
    {
        for (int j = 1; j + (1 << i) - 1 <= n; ++j)
        {
            Max[j][i] = max(Max[j][i - 1], Max[j + (1 << (i - 1))][i - 1]);
        }
    }
    int l, r;
    for (int i = 0; i < m; ++i)
    {
        l = read();
        r = read();
        int s = Log2[r - l + 1];
        int ma = max(Max[l][s], Max[r - (1 << s) + 1][s]);
        printf("%d\n", ma);
    }
}