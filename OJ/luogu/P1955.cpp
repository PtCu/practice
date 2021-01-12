#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
int f[maxn];
int discrete[maxn];
struct node
{
    int x, y, e;
} source[maxn];
int find(int x)
{
    return x == f[x] ? x : f[x] = find(f[x]);
}
void Union(int a, int b)
{
    f[find(a)] = find(b);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        bool flag = true;
        memset(f, 0, sizeof(f));
        memset(discrete, 0, sizeof(discrete));
        int n;
        int tot = -1;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> source[i].x >> source[i].y >> source[i].e;
            discrete[++tot] = source[i].x;
            discrete[++tot] = source[i].y;
        }
        sort(discrete, discrete + tot);
        int reu = unique(discrete, discrete + tot) - discrete; //去重
        for (int i = 1; i <= n; ++i)
        {
            source[i].x = lower_bound(discrete, discrete + reu, source[i].x) - discrete;
            source[i].y = lower_bound(discrete, discrete + reu, source[i].y) - discrete;
        }
        sort(source + 1, source + n + 1, [](const node &a, const node &b) { return a.e > b.e; });
        for (int i = 1; i <= reu; ++i)
        {
            f[i] = i;
        }
        for (int i = 1; i <= n; ++i)
        {
            int r1 = find(source[i].x);
            int r2 = find(source[i].y);
            if (source[i].e)
            {
                f[r1] = r2;
            }
            else if (r1 == r2)
            {
                cout << "NO" << endl;
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "YES" << endl;
    }
    return 0;
}