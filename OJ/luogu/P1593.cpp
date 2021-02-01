#include <bits/stdc++.h>
using namespace std;
const int P = 9901;
const int maxn = 1e6;
int prime[maxn];
int quick_pow(int base, int b)
{
    int ans = 1;
    while (b>0)
    {
        if (b & 1)
        {
            ans = (ans * base) % P;
        }
        base = (base * base) % P;
        b >>= 1;
    }
    return ans;
}
int sum(int x, int y)
{
    return (quick_pow(x, y + 1) - 1) * (quick_pow(x-1, P - 2)) % P;
}
int main()
{
    int a, b;
    cin >> a >> b;
    int cnt = 0;
    int ans = 1;
    int times = 0;
    for (int i = 2; i * i <= a; ++i)
    {
        if (a % i == 0)
        {
            times = 0;
            while (!(a % i))
            {
                a /= i;
                times++;
            }
            if (i % P == 1)
            {
                ans = ans * (1 + times) % P;
            }
            else
            {
                times *= b;
                ans = ans * sum(i % P, times) % P;
            }
        }
    }
    if (a != 1)
    {
        if (a % P == 1)
            ans = ans * (b + 1) % P;
        else
        {
            ans = ans * sum(a % P, b) % P;
        }
    }
    cout << ans;
}