#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
int f[maxn];
int Find(int x)
{
    if (x == f[x])
        return x;
    return f[x] = Find(f[x]);
}
void Union(int a, int b)
{
    f[Find(b)] = Find(a);
}
int main()
{
    int n, k, x, pre;
    cin >> n;
    for (int i = 1; i < maxn; ++i)
    {
        f[i] = i;
    }
    int max_b = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> k;
        cin >> pre; //第一个为老大
        max_b = max(max_b, pre);
        for (int j = 1; j < k; ++j)
        {
            cin >> x;
            max_b = max(max_b, x);
            Union(pre, x);
        }
    }
    int num = 0;
    for (int i = 1; i <= max_b; ++i)
    {
        if (f[i] == i)
            num++;
    }
    cout << num << " " << max_b << endl;
    int q;
    cin >> q;
    int a, b;
    for (int i = 1; i <= q; ++i)
    {
        cin >> a >> b;
        //找公共老大时务必用Find
        if (Find(a) == Find(b))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}