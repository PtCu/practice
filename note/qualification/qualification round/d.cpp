#include <bits/stdc++.h>

const int P = 1e9 + 7;

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int T;
    std::cin >> T;
    while (T--)
    {
        int n, m, k;
        std::cin >> n >> m >> k;
        m -= k * n;
        std::vector<int> f(m + 1, 0);
        f[0] = 1;
        for (int i = 1; i <= n; ++i)
            for (int j = n - i + 1; j <= m; ++j)
                (f[j] += f[j - (n - i + 1)]) %= P;
        std::cout << f[m] << '\n';
    }
    return 0;
}
