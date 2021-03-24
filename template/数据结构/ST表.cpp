//https://zhuanlan.zhihu.com/p/105439034
//Luogu P2880
#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4 + 10;
int Min[maxn][17], Max[maxn][17];
int Log2[maxn];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> Min[i][0] >> Max[i][0];
    }
    for (int i = 2; i <= n; ++i)
    {
        Log2[i] = Log2[i / 2] + 1;
    }
    for (int i = 1; i <= 16; ++i)
    {
        for (int j = 1; j + (1 << i) - 1 <= n; ++j)
        {
            Min[j][i] = min(Min[j][i - 1], Min[j + (1 << (i - 1))][i - 1]);
            Max[j][i] = max(Max[j][i - 1], Max[j + (1 << (i - 1))][i - 1]);
        }
    }

    int l, r;
    for (int i = 0; i < m; ++i)
    {
        cin >> l >> r;
        int s = Log2[r - l + 1];
        int ma = max(Max[l][s], Max[r - (1 << s) + 1][s]);
        int mi = min(Min[l][s], Min[r - (1 << s) + 1][s]);
        cout << ma - mi << endl;
    }
}