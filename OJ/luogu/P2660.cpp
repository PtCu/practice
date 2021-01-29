#include <bits/stdc++.h>
using namespace std;
int main()
{

    long long x, y, z;
    cin >> x >> y;
    long long ans = 0;
    while (x != 0 && y != 0)
    {
        z = min(x, y);
        if (x == z)
            ans += 4 * (y / z) * z, y %= z; //一次切多个
        else if (y == z)
            ans += 4 * (x/ z) * z, x %= z;
    }

    cout << ans;
}