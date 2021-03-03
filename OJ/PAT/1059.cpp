#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
bool isPrime[maxn];
int Prime[maxn];
int cnt = 0;
void getPrime(int n)
{
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[1] = 0;
    for (int i = 2; i <= n; ++i)
    {
        if (isPrime[i])
            Prime[++cnt] = i;
        for (int j = 1; j <= cnt && Prime[j] * i <= n; ++j)
        {
            isPrime[i * Prime[j]] = 0;
            if (i % Prime[j] == 0)
            {
                break;
            }
        }
    }
}
struct Node
{
    int p, k;
} nodes[maxn];
int main()
{

    int n;
    cin >> n;
    int tmp = n;
    if(n == 1)
    {
        printf("1=1");
        return 0;
    }
    getPrime((int)sqrt(n)+100);
    int step = 0;

    for (int i = 1; Prime[i] <= n; ++i)
    {
        if (n % Prime[i] == 0)
        {
            nodes[step].p = Prime[i];
            nodes[step].k = 0;
            while (n % Prime[i] == 0)
            {
                n /= Prime[i];
                ++nodes[step].k;
            }
            ++step;
        }
    }
    if (n != 1)
    {
        nodes[step].p = n;
        nodes[step].k = 1;
        step++;
    }
    cout << tmp << "=";

    if (nodes[0].k == 1)
    {
        cout << nodes[0].p;
    }
    else
    {
        cout << nodes[0].p << "^" << nodes[0].k;
    }
    for (int i = 1; i < step; ++i)
    {
        if (nodes[i].k > 1)
        {
            cout << "*" << nodes[i].p << "^" << nodes[i].k;
        }
        else if (nodes[i].k == 1)
        {
            cout << "*" << nodes[i].p;
        }
    }
}