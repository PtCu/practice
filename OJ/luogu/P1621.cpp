#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int f[maxn];
int Find(int a)
{
    return a == f[a] ? a : f[a] = Find(f[a]);
    
}
void Union(int a, int b)
{
    f[Find(a)] = f[b];
}
bool pri[maxn];

//埃氏筛
int solve(int a, int b, int p)
{
    int num = 0;
    pri[0] = pri[1] = false;
    memset(pri, true, sizeof(pri));
    for (int i = 2; i <= b; ++i)
    {
        //对一素数来说
        if (pri[i])
        {
            if (i >= p)
            {
                //将i的倍数标记为非素数并将i的倍数们合并
                for (int j = 2 * i; j <= b; j += i)
                {
                    pri[j] = false;
                    if (j - i >= a && Find(j) != Find(j - i))
                    {
                        Union(j - i, j);
                        num++;
                    }
                }
            }
            else
            {
                //将i的倍数标记为非素数
                for (int j = 2 * i; j <= b; j += i)
                {
                    pri[j] = false;
                }
            }
        }
    }
    return num;
}
int main()
{
    int a, b, p;
    cin >> a >> b >> p;
    int ans = b - a + 1;
    for (int i = a; i <= b; ++i)
    {
        f[i] = i;
    }
    ans -= solve(a, b, p);
    cout << ans;
}