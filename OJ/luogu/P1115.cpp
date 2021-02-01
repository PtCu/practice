#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn];
int main()
{
    int n;
    cin >> n;
    int ans = 0;
    cin >> a[1];
    int sum = ans = a[1];
    for (int i = 2; i <= n; ++i)
    {
        cin >> a[i];
        sum < 0 ? sum = 0 : 1;
        sum += a[i];
        ans = max(ans, sum);
    }

    cout << ans;
}