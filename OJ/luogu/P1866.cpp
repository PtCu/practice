#include <bits/stdc++.h>
using namespace std;
const int maxn = 50;
int Maxnumber[maxn];
int main()
{
    int n;
    cin >> n;
    for (size_t i = 0; i < n; ++i)
    {
        cin >> Maxnumber[i];
    }
    sort(Maxnumber, Maxnumber + n);
    long long ans = 1;
    for (size_t i = 0; i < n; ++i)
    {
        ans *= (Maxnumber[i] - i);
        ans %= 1000000007;
    }
    cout << ans;
}