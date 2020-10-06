#include <bits/stdc++.h>
using namespace std;
const int M = 10000;
const int maxn = 1000000;
int dp1[maxn];
int dp2[maxn];
int main(int argc, char **argv)
{

    int n;
    cin >> n;
    dp1[0] = 1;
    dp1[1] = 1;
    dp2[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp1[i] = ((dp1[i - 1] + dp1[i - 2]) % M + (2 * dp2[i - 2]) % M) % M;
        dp2[i] = (dp2[i - 1] + dp1[i - 1]) % M;
    }

    cout << dp1[n];
    return 0;
}
