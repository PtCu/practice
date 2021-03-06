//luogu1069
#include <bits/stdc++.h>
using namespace std;
int s[100001];
int prime[100001]; //记录质数j的次数
int main()
{
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    for (int i = 1; i <= n; ++i)
    {
        cin >> s[i];
    }
     if (m1==1) {cout<<0<<endl;return 0;}
    //筛质因数
    int max_prime = 0;
    int p = 2;
    while (m1 != 1)
    {
        while (!(m1 % p))
        {
            m1 /= p;
            prime[p]++;
        }
        max_prime = max(max_prime, p);
        prime[p++] *= m2;
    }
    int times = 0;
    int distance = 0;
    int ans = INT_MAX;
    for (int i = 1; i <= n; ++i)
    {
        distance = 0;
        for (int j = 2; j <= max_prime; ++j)
        {
            if (!prime[j])
                continue;
            times = 0;
            while (!(s[i] % j))
            {
                s[i] /= j;
                times++;
            }
            if (times == 0)
            {
                distance = INT_MAX;
                break;
            }
            distance = max(distance, (prime[j] - 1) / times);
        }
        ans = min(ans, distance);
    }
    if (ans == INT_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans + 1 << endl;
    }
}