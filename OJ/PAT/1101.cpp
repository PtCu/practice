#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
long long a[maxn];
long long lower[maxn];
long long upper[maxn];
long long ans[maxn];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        lower[i] = max(lower[i - 1], a[i - 1]);
    }
    a[n + 1] = LONG_LONG_MAX;
    upper[n + 1] = a[n + 1];
    for (int i = n; i >= 1; --i)
    {
        upper[i] = min(upper[i + 1], a[i + 1]);
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (upper[i] >= a[i] && lower[i] <= a[i])
        {
            ans[cnt++] = a[i];
        }
    }
    cout << cnt << endl;
    if (cnt == 0)
    {
        cout << endl;
        return 0;
    }

    cout << ans[0];
    for (int i = 1; i < cnt; ++i)
    {
        cout << " " << ans[i];
    }
}