#include <bits/stdc++.h>
using namespace std;

//O(logn)
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main()
{
    int x, y;
    cin >> x >> y;
    long long s = x * y;
    int ans = 0;
    if (x == y)
        ans--;
    for (int i = 1; i * i <= s; ++i)
    {
        if (s % i == 0 && gcd(i, s / i) == x)
            ans+=2;
    }
    cout << ans;
}