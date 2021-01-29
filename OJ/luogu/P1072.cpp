#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ans, a0, a1, b0, b1, j;
    while (n--)
    {
        ans = 0;
        cin >> a0 >> a1 >> b0 >> b1;
        for (int i = 1; i * i <= b1; ++i)
        {
            if (b1 % i == 0)
            {
                if (i % a1 == 0)
                {
                    if (__gcd(i / a1, a0 / a1) == 1 && __gcd(b1 / b0, b1 / i) == 1)
                    {
                        ans++;
                    }
                }
                j = b1 / i; //另一个因子
                if (i == j)
                    continue;
                if (j % a1 == 0)
                {
                    if (__gcd(j / a1, a0 / a1) == 1 && __gcd(b1 / b0, b1 / j) == 1)
                    {
                        ans++;
                    }
                }
            }
        }
        cout << ans << endl;
    }
}