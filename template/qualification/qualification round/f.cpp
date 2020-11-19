#include <bits/stdc++.h>

int Calc(long long base1, int v, int P)
{
    long long base2 = base1, base3 = 1, res = 0;
    for (; v; v >>= 1, (base1 *= base1) %= P)   //v右移
    {
        if (v & 1)  //判断v的最后一位是不是1
        {
            (res += base2 * base3 % P) %= P;
            (base3 *= base1) %= P;
        }
        (base2 *= (1 + base1)) %= P;
    }
    return res;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int T;
    std::cin >> T;
    while (T--)
    {
        int q, n, p;
        std::cin >> q >> n >> p;
        std::cout << Calc(q, n, p) << '\n';
    }
    return 0;
}
