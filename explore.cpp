#include <bits/stdc++.h>
using namespace std;
long long k;
long long quickpow(long long base, long long p)
{
    long long ans = 1;
    while (p)
    {
        if (p & 1)
        {
            ans = (ans * base) % k;
        }
        base = (base * base) % k;
        p >>= 1;
    }
    return ans % k;
}
int main()
{
    long long b, p;
    cin >> b >> p >> k;
    cout << b << "^" << p << " mod " << k << "=" << quickpow(b, p);
}