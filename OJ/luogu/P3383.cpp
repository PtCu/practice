#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e8;
int prime[maxn];        //第i个素数
bool is_pri[maxn + 10]; //is_pri[i]表示i是素数
int sieve(int n)
{

    int p = 0;
    memset(is_pri, true, sizeof(is_pri));
    is_pri[0] = is_pri[1] = true;
    for (int i = 2; i <= n; ++i)
    {
        if (is_pri[i])
        {
            prime[++p] = i;
            for (int j = 2 * i; j <= n; j += i)
            {
                is_pri[j] = false;
            }
        }
    }
    return p;
}

int main()
{
    int n, q;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    int k;
    sieve(n);
    while (q--)
    {
        cin >> k;
        cout << prime[k] << endl;
    }
}