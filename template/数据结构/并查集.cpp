//https://www.luogu.com.cn/problem/P3367
#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
int f[maxn];
//并
void Union(int x, int y)
{
    int xf = find(x);
    int yf = find(y);
    if (xf == yf)
        return;
    f[xf] = yf;
}
//查
//并查集思想就是用老大代表这个集合，操作时用find(x)代替x
int find(int k)
{
    //路径压缩
    return f[k] == k ? k : f[k] = find(f[k]); //让沿途结点都指向祖先，以压缩路径
}

//迭代写法
int find2(int x) //寻找x的祖先
{
    while (f[x] != x)
        x = f[x]; //不断更新寻找祖先
    return x;
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