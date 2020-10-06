#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 100005;
int a[MAXN];
int ll, n, k;
int MoS2(int mid)
{
    int m = 0;
    for (int i = 2; i <= n; i++)
        if (a[i] - a[i - 1] >= mid)
        {
            m += (a[i] - a[i - 1]) / mid;
            if ((a[i] - a[i - 1]) % mid == 0)
                m--;
        }
    if (m > k)
        return 0;
    return 1;
}
int main()
{
    scanf("%d%d%d", &ll, &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int l = 0;
    int r = ll;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (MoS2(mid) == 1)
            r = mid-1;
        else
            l = mid + 1;
    }
    printf("%d", l);
    return 0;
}