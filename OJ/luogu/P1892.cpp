#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
int f[maxn];
int enemies[maxn];
//并查集核心就是用老大代表这个集合
int find(int k)
{
    //路径压缩
    return f[k] == k ? k : f[k] = find(f[k]); //让沿途结点都指向祖先，以压缩路径
}
void Union(int a, int b)
{
    f[find(a)] = find(b);
}

int main()
{
    int n, m;
    cin >> n >> m;
    char E;
    for (int i = 1; i <= n; ++i)
    {
        f[i] = i;
    }
    int x, y;
    while (m--)
    {
        cin >> E >> x >> y;
        if (E == 'E')
        {
            //如果n当前没有敌人
            if (!enemies[x])
                enemies[x] = find(y);
            //如果有，就将两个敌人划分一组
            else
                Union(y, enemies[x]);

            //如果m当前没有敌人
            if (!enemies[y])
                enemies[y] = find(x);
            //如果有，就将两个敌人划分一组
            else
                Union(x, enemies[y]);
        }
        else
        {
            Union(x, y);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (f[i] == i)
            ans++;
    }

    cout << ans;
    return 0;
}