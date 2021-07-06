#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int MOD = 1e9 + 7;

LL res[2] = {1LL, 1LL};
LL A[2][2] = {
    {0LL, 1LL},
    {1LL, 1LL}};

void mul(LL c[2], LL a[2], LL b[][2])
{

    LL tmp[2] = {0};
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            tmp[i] = tmp[i] + (a[j] * b[j][i]) % MOD;

    memcpy(c, tmp, sizeof tmp);
}

void mul(LL c[][2], LL a[][2], LL b[][2])
{

    LL tmp[2][2] = {0};
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                tmp[i][j] = tmp[i][j] + (a[i][k] * b[k][j]) % MOD;

    memcpy(c, tmp, sizeof tmp);
}

LL fib(int n)
{

    n--;
    while (n)
    {
        if (n & 1)
            mul(res, res, A);
        n >>= 1;
        mul(A, A, A);
    }

    return res[0];
}

int main()
{

    int n;
    scanf("%d", &n);

    printf("%lld", fib(n));

    return 0;
}
