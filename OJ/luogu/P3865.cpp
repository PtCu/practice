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
int Max[maxn][17];
int Log2[maxn];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> Max[i][0];
    }
    for (int i = 1; i <= n; ++i)
    {
        Log2[i] = Log2[i / 2] + 1;
    }
    for (int i = 1; i <= 16; ++i)
    {
        for (int j = 1; j + (1 << i) - 1 <= n; ++i)
        {
            Max[j][i] = max(Max[j][i - 1], Max[j + (1 << (i - 1))][i - 1]);
        }
    }
    int l, r;
    for (int i = 0; i < m; ++i)
    {
        cin >> l >> r;
        int s = Log2[r - l + 1];
        int ma = max(Max[l][s], Max[r - (1 << s) + 1][s]);
        cout << ma << endl;
    }
}