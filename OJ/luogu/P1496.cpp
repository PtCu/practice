#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e4 + 10;
int start_p[maxn];
int end_p[maxn];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> start_p[i];
        cin >> end_p[i];
    }
    sort(start_p + 1, start_p + n + 1);
    sort(end_p + 1, end_p + n + 1);
    int ans = 0;
    end_p[0] = -INT_MAX;
    for (int i = 1; i <= n; ++i)
    {
        if (start_p[i] < end_p[i - 1])
        {
            ans -= end_p[i - 1] - start_p[i];
        }
        ans += end_p[i] - start_p[i];
    }
    cout << ans;
    return 0;
}