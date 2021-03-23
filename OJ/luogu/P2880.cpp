#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4 + 10;
int c[maxn];
int n;
int max_c[maxn];
int min_c[maxn];
int lowerbit(int x)
{
    return x & (-x);
}

//更新位置i的数，同时更新后面的数，因为树状数组本质是分段前缀和
void update(int i, int x)
{
    while (i <= maxn)
    {
        max_c[i] = max(max_c[i], x);
        min_c[i] = min(min_c[i], x);
        i += lowerbit(i);
    }
}

int sum(int i)
{
    int s = 0;
    while (i > 0)
    {
        s += c[i];
        i -= lowerbit(i);
    }
    return s;
}
int query1(int a, int b)
{
    return sum(b) - sum(a);
}

int main()
{
    int q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
    {
        cin >> c[i];
    }
    int a, b;
    for (int i = 1; i <= q; ++i)
    {
        cin >> a >> b;
    }
}