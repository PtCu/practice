#include <iostream>
using namespace std;
bool pri[1000000 + 10];
bool ispri[10000000 + 10]; //ispri[i-a]=true代表i是素数

void getpri()
{
    memset(pri, true, sizeof(pri));
    pri[0] = pri[1] = 0;
    for (int i = 2; i <= 1000000; i++)
    {
        if (pri[i])
        {
            for (int j = 2 * i; j <= 1000000; j += i)
                pri[j] = 0;
        }
    }
}

int main()
{
    long long a, b;
    scanf("%lld%lld", &a, &b);
    getpri();
    memset(ispri, true, sizeof(ispri));
    for (long long i = 2; i * i < b; i++)
    {
        if (pri[i])
        {
            for (long long j = max((a + i - 1) / i, 2LL) * i; j < b; j += i)
                ispri[j - a] = 0;
        }
    }
    long long cnt = 0;
    for (int i = 0; i < b - a; i++)
        if (ispri[i])
            cnt++;
    if (a == 1)
        cnt--;
    printf("%lld\n", cnt);
}
