#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int f[maxn], hobby[maxn], num[maxn];
int Find(int x)
{
    if (x == f[x])
        return x;
    return f[x] = Find(f[x]);
}
void Union(int a, int b)
{
    int fa = Find(a);
    int fb = Find(b);
    if (fa != fb)
    {
        f[fb] = fa;
        num[fa] += num[fb];
        num[fb] = 0;
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        f[i] = i, num[i] = 1;
    for (int i = 0; i < n; ++i)
    {
        int k, x;
        scanf("%d:", &k);
        for (int j = 0; j < k; ++j)
        {
            cin >> x;
            if (hobby[x] == 0)
                hobby[x] = i;
            Union(hobby[x], i);
        }
    }
    int cnt = 0;
    sort(num + 1, num + 1 + n, greater<int>());
    for (int i = 1; i <= n; ++i)
    {
        if (num[i] != 0)
            cnt++;
    }
    cout << cnt << endl;
    for (int i = 1; i <= cnt; ++i)
    {
        if (i != 1)
            cout << " ";
        cout << num[i];
    }
}