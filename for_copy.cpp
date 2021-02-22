#include <bits/stdc++.h>
using namespace std;
bool isPrime[100000001];
int Prime[60000];
int cnt;
void filter(int n)
{
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[1] = 0;
    for (int i = 2; i <= n; ++i)
    {
        if (isPrime[i])
            Prime[++cnt] = i;
        for (int j = 1; j <= cnt && Prime[j] * i <= n; ++j)
        {
            isPrime[Prime[j] * i] = 0;
            if (i % Prime[j]==0)
                break;
        }
    }
}