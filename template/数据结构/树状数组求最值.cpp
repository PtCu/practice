//luogu2880
//https://www.codenong.com/cs106012941/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e2 + 10;
int c[maxn];
int n;
int max_c[maxn];
int min_c[maxn];
int lowerbit(int x)
{
    return x & (-x);
}

//树状数组本质是分段前缀和
//就是把求区间和树状数组中的累加改为了求最值
void update(int i, int x)
{
    while (i <= n)
    {
        max_c[i] = max(max_c[i], x);
        min_c[i] = min(min_c[i], x);
        i += lowerbit(i);
    }
}

int query1(int L, int R)
{
    int len = R - L + 1, ret = 0;
    while (len && R)
    {
        if (len >= lowerbit(R))
        {
            ret = max(max_c[R], ret);
            len -= lowerbit(R);
            R -= lowerbit(R);
        }
        else
        {
            ret = max(c[R], ret);
            len--, R--;
        }
    }
    return ret;
}

int query2(int L, int R)
{
    int len = R - L + 1, ret = INT_MAX;
    while (len && R)
    {
        if (len >= lowerbit(R))
        {
            ret = min(min_c[R], ret);
            len -= lowerbit(R);
            R -= lowerbit(R);
        }
        else
        {
            ret = min(c[R], ret);
            len--, R--;
        }
    }
    return ret;
}

int main()
{
    int q;
    cin >> n >> q;
    fill(min_c, min_c + maxn, INT_MAX);
    for (int i = 1; i <= n; ++i)
    {
        cin >> c[i];
        update(i, c[i]);
    }

    int a, b;
    int max_t, min_t;
    for (int i = 1; i <= q; ++i)
    {
        cin >> a >> b;
        max_t = query1(a, b);
        min_t = query2(a, b);
        cout << max_t - min_t << endl;
    }
}