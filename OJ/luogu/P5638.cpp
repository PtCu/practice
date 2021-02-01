#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
long long a[maxn];
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n - 1; ++i)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    long long diff = 0;
    for (int i = 0; i <= n-1; ++i)
    {
        if (i + k > n)
        {
            diff = max(diff, a[n] - a[i]);
        }
        else
        {
            diff = max(diff, a[i + k] - a[i]);
        }
    }
    cout << a[n-1] - diff;
}