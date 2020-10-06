#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<LL> a(1e6 + 10);
int main()
{

    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    LL df = 0;
    for (int i = 0; i <= n - 1; i++)
    {
        if (i + k > n - 1)
            df = max(df, a[n - 1] - a[i]);
        else
            df = max(df, a[i + k] - a[i]);
    }
    cout << a[n - 1] - df;
}