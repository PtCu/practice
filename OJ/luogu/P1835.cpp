#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+1;
bool isPrime[maxn];
int Prime[maxn], cnt = 0;
void GetPrime(int n)
{
    memset(isPrime, 1, sizeof(isPrime));
    for (int i = 2; i <= n; ++i)
    {
        if (isPrime[i])
            Prime[++cnt] = i;
        for (int j = 1; j <= cnt && Prime[j] * i <= n; ++j)
        {
            isPrime[Prime[j] * i] = 0;
            if (i % Prime[j] == 0)
                break;
        }
    }
}
int main()
{
    int l, r;
    cin >> l >> r;
    l = l == 1 ? 2 : l; //特判L=1的情况
    GetPrime(50000);
    memset(isPrime, 0, sizeof(isPrime));
    for (int i = 1; i <= cnt; ++i)
    {
        //从大于L的最小的能被p整除的数开始
        for (long long j = max(2, (l + Prime[i] - 1) / Prime[i]) * Prime[i]; j <= r; j += Prime[i])
        {
            isPrime[j - l + 1] = 1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= r - l + 1; ++i)
    {
        if (!isPrime[i])
            ans++;
    }
    cout << ans;
}