#include <bits/stdc++.h>
using namespace std;
int P = 9999;
//快速幂
int Pow(long long base, int v)
{
    long long res = 1;
    for (; v; v >>= 1, (base *= base) %= P)
        if (v & 1)
            (res *= base) %= P;
    return res;
}
int Pow(int base, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans *= base;
        base *= base;
        b >>= 1;
    }
    return ans;
}
const int k = 27737;
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


