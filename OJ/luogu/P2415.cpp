#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a;
    long long ans = 0;
    int i = 0;
    while (cin >> a)
    {
        ans += a;
        ++i;
    }
    ans *= (1 << (i - 1));
    cout << ans;
}