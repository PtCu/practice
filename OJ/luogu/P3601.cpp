#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 11;
long long prime[maxn];
bool isPrime[maxn];
const int P = 666623333;
long long cnt;
void getPrime(long long n)
{
    memset(isPrime, true, sizeof(isPrime));
    isPrime[1] = 0;
    for (long long i = 2; i <= n; ++i)
    {
        if (isPrime[i])
            prime[++cnt] = i;
        for (long long j = 1; j <= cnt && i * prime[j] <= n; ++j)
        {
            isPrime[i * prime[j]] = 0;
            if (i % prime[j] == 0)
                break;
        }
    }
}
long long vis[maxn];
long long phi[maxn];
int main()
{
    long long l, r;
    cin >> l >> r;
    getPrime(maxn);
    for (long long i = 0; i <= r - l; i++)
    {
        vis[i] = i + l;
        phi[i] = i + l;
    }
    //求欧拉函数
    long long p;
    //对于每1个小于1e6的质数，对它的倍数求一次欧拉函数
    for (long long i = 1; i <= cnt && prime[i] * prime[i] <= r; ++i)
    {
        p = prime[i];
        for (long long x = (p - l % p) % p; x <= r - l; x += p)
        {
            phi[x] /= p, phi[x] *= p - 1;
            while (vis[x] % p == 0) //同时使该数不还有该质因子
            {
                vis[x] /= p;
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i <= r - l; ++i)
    {
        if (vis[i] ^ 1)
        {
            phi[i] /= vis[i];
            phi[i] *= vis[i] - 1;
        }
        ans = (ans + i +l- phi[i]) % P;
    }
    cout << ans;
}