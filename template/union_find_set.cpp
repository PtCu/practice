//https://www.luogu.com.cn/problem/P3367
#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
int f[maxn];
//并
void Union(int x, int y)
{
    f[find(x)] = find(y);
}
//查
int find(int k)
{
    //路径压缩
    if (f[k] == k)
        return k;
    return f[k] = find(f[k]); //让沿途结点都指向祖先，以压缩路径
}
int main()
{
    int n, m, z, x, y;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        f[i] = i;
    while (m--)
    {
        cin >> z >> x >> y;
        if (z == 1)
        {
            f[find(x)] = find(y);
        }
        else
        {
            if (find(x) == find(y))
                cout << "Y" << endl;
            else
                cout << "N" << endl;
        }
    }
}