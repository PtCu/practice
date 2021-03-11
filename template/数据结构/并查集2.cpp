//PAT 1107
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int f[maxn];
int num[maxn], hobby[maxn]; //hobby[i]表示爱好i的第一个人
int Find(int x)
{
    if (f[x] == x)
        return x;
    return f[x] = Find(f[x]);
}
void Union(int a, int b)
{
    int fa = Find(a);
    int fb = Find(b);
    if (fa != fb)
        f[fa] = fb;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        f[i] = i;
    for (int i = 1; i <= n; ++i)
    {
        int k, x;
        scanf("%d:", &k);
        for (int j = 0; j < k; ++j)
        {
            cin >> x;
            //hobby[x]被第一次选中，则第一个选它的人为老大
            if (hobby[x] == 0)
                hobby[x] = i;
            Union(i, Find(hobby[x]));
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        num[Find(i)]++;
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (num[i] != 0)
            cnt++;
    }
    cout << cnt << endl;
    sort(num + 1, num + 1 + n, greater<int>());
    for (int i = 1; i <= cnt; ++i)
    {
        if (i != cnt)
            cout << num[i] << " ";
        else
            cout << num[i];
    }
}