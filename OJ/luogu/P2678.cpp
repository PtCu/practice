#include <bits/stdc++.h>
using namespace std;
int l, n, m;
int main()
{
    cin >> l >> n >> m;
    vector<int> sources(n + 1);

    sources[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> sources[i];
    }
    int low = 0, high = l;
    int ans = 0;
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        int sum = 0;
        int cur = 0;
        for (int i = 1; i <= n; i++)
        {
            if (sources[i] - sources[cur] < mid)
                sum++;
            else
                cur = i;
        }
        if (sum <= m)
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid-1;
    }
    if (n == 0 && m == 0)
        cout << l;
    else

        cout << ans;
}