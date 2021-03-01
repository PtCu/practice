#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];
int pre[maxn];
int post[maxn];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        pre[i] = pre[i - 1] + a[i];
        post[n - i + 1] = post[n - i + 2] + a[n - i + 1];
    }
    int m;
    cin >> m;
    int a, b;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        cout << min(abs(pre[b - 1] - pre[a - 1]), abs(pre[a - 1] + post[b])) << endl;
    }
    return 0;
}