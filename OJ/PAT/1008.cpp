#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ans = 0;
    int cur = 0;
    int req;
    for (int i = 0; i < n; ++i)
    {
        cin >> req;
        if (req > cur)
        {
            ans += (req - cur) * 6;
        }
        else if (req < cur)
        {
            ans += (cur - req) * 4;
        }
        cur = req;
    }
    ans += 5 * n;
    cout << ans;
}