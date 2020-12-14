#include <bits/stdc++.h>
using namespace std;
int f[1010];
int find(int x)
{
    if (x == f[x])
        return x;
    return f[x] = find(f[x]);
}
void Union(int a, int b)
{
    //a的祖先的祖先置为b
    f[find(a)] = find(b);
}

int main()
{
    int n, m, ans;
    for (;;)
    {
        ans = 0;
        cin >> n;
        if (!n)
            break;
        cin >> m;
        int x, y;
        for (size_t i = 1; i <= n; ++i)
            f[i] = i;

        while (m--)
        {
            cin >> x >> y;
            Union(x, y);
        }
        for (size_t i = 1; i <= n; ++i)
        {
            if (find(i) == i)
                ++ans;
        }
        cout << ans - 1 << endl;
    }
}