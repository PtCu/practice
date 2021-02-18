#include <bits/stdc++.h>
using namespace std;
long long k;
long long Pow(long long base, long long b)
{
    long long ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * base) % k;
        base = (base * base) % k;
        b >>= 1;
    }
    return ans;
}
int main()
{
    long long b, p;
    cin >> b >> p >> k;
    cout << b << "^" << p << " mod " << k << "=" << Pow(b, p);
}