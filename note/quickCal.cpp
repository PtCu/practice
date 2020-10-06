#include<bits/stdc++.h>
using namespace std;
int P=9999;
//快速幂
int Pow(long long base, int v)
{
    long long res = 1;
    for (; v; v >>= 1, (base *= base) %= P)
        if (v & 1)
            (res *= base) %= P;
    return res;
}
int Pow(int base, int b) {
    int ans = 1;
    while (b)
    {
        if(b&1)
            ans *= base;
        base *= base;
        b >>= 1;
    }
    return ans;
}