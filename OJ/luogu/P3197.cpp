#include <bits/stdc++.h>
using namespace std;
const long long k = 100003;
long long pow_(long long b, long long p)
{
    if (p == 0)
        return 1;
    long long ans = 1;
    while (p)
    {
        if (p & 1)
        {
            ans = (ans * b) % k;
        }
        p >>= 1;
        b = (b * b) % k;
    }
    return ans % k;
}
int main()
{
    long long n, m;
    cin >> m >> n;
    cout << (pow_(m, n) - (m * pow_(m - 1, n - 1)) % k + k) % k;
}