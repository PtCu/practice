#include <bits/stdc++.h>

const int N = 1e6, XN = N + 11, P = 1e9 + 7;

int Pow(long long base, int v)
{
    long long res = 1;
    for (; v; v >>= 1, (base *= base) %= P)
        if (v & 1)
            (res *= base) %= P;
    return res;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    static int fact[XN], inv[XN];
    fact[0] = 1;
    for (int i = 1; i <= N; ++i)
        fact[i] = 1LL * fact[i - 1] * i % P;    //1LL*将int转为long long并赋值

    //计算逆元
    for (int i = N, x = Pow(fact[N], P - 2); i >= 1; x = 1LL * x * i % P, --i)
        inv[i] = 1LL * fact[i - 1] * x % P;
    int T;
    std::cin >> T;
    while (T--)
    {
        int n, m;
        std::cin >> n >> m;
        std::cout << (1LL * fact[n] * inv[m] % P) << '\n';
    }
    return 0;
}
