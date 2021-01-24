#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
unsigned long long c[maxn][maxn];
void preProc()
{
    c[0][0] = c[1][0] = c[1][1] = 1;
    for (int i = 2; i <= maxn; ++i)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j)
        {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }
}
int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    preProc();
    unsigned long long ans = 0;
    for (int i = 0; i <= a; ++i)
    {
        for (int j = 0; j <= b; ++j)
        {
            ans += c[i + n - 1][n - 1] * c[j + n - 1][n - 1];
        }
    }
    cout << ans;
}