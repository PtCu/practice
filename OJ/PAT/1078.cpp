#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
bool isPrime[maxn];
int Prime[maxn];
int cnt;
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
            if (i % Prime[j]==0)
                break;
        }
    }
}

bool hasNum[maxn];
int main()
{
    int size, n, key;
    cin >> size >> n;
    getPrime(maxn);
    if (!isPrime[size])
    {
        int idx = lower_bound(Prime+1, Prime+1 + cnt, size) - Prime;
        size = Prime[idx];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> key;
        int pos = key % size;
        if (hasNum[pos])
        {
            int j = 1;
            for (; j < size; j++)
            {
                int repos = (key + j * j) % size;
                //只考虑正向
                if (hasNum[repos] == false)
                {
                    hasNum[repos] = 1;
                    if (i > 0)
                        cout << " ";
                    cout << repos;
                    break;
                }
            }
            if (j == size)
            {
                if (i > 0)
                    printf(" ");
                printf("-");
            }
        }
        else
        {
            hasNum[pos] = 1;
            if (i > 0)
                cout << " ";
            cout << pos;
        }
    }
}