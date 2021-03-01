#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 10;
int a[maxn];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n - 1; ++i)
    {
        int rank = lower_bound(a + i + 1, a + n, m - a[i]) - a;
        if (a[rank] + a[i] == m)
        {
            cout << a[i] << " " << a[rank];
            return 0;
        }
    }
    cout << "No Solution";
}