#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4 + 10;
int a[maxn];
int l[maxn], r[maxn]; //l[i]记录i左边的最长的可延伸长度,r[i]同理

int main()
{
    int n, k;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    l[1] = 1;
    for (int i = 2, j = 1; i <= n; ++i)
    {
        while (a[i] - a[j] > k)
        {
            j++;
        }
        l[i] = max(l[i], i - j + 1);
    }
    r[n] = 1;
    for (int i = n - 1, j = n; i >= 1; i--)
    {
        while (a[j] - a[i] > k)
        {
            j--;
        }
        r[i] = max(r[i + 1], j - i + 1);
    }
    int ans = 0;
    for (int i = 1; i <= n - 1; ++i)
    {
        ans = max(ans, l[i] + r[i + 1]);
    }
    cout << ans;
    return 0;
}