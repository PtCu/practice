#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        long long a, b, c;
        // cin >> a >> b >> c;
        scanf("%lld %lld %lld", &a, &b, &c);
        bool res = true;
        if (a + b <= c)
            res = false;

        if (a < 0 && b < 0 && a + b >= 0)
        {
            res = false;
        }
        if (a > 0 && b > 0 && a + b <= 0)
        {
            res = true;
        }
        if (res)
            printf("Case #%d: true\n", i);
        else
            printf("Case #%d: false\n", i);
    }
}