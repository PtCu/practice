#include <bits/stdc++.h>
using namespace std;
//luog1955
const int maxn = 1e6;
int f[maxn];
int discrete[maxn];
//离散化
// 总得来说离散化有三步走战略：

// 1.去重（可以用到unique去重函数）

// 2.排序

// 3.二分索引（可以用到lower_bound函数）
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
        //离散化操作
        for (int i = 1; i <= n; ++i)
        {
            cin >> source[i].x >> source[i].y >> source[i].e;
            discrete[++tot] = source[i].x;
            discrete[++tot] = source[i].y;
        }
        sort(discrete, discrete + tot);
        int reu = unique(discrete, discrete + tot) - discrete; //去重 返回的是去重序列后最后一个元素 unique对有序序列操作
        //对所有源数据，范围为n
        for (int i = 1; i <= n; ++i)
        {
            //lower_bound返回第1个不小于x的位置
            source[i].x = lower_bound(discrete, discrete + reu, source[i].x) - discrete; //通过lower_bound找相对位置
            source[i].y = lower_bound(discrete, discrete + reu, source[i].y) - discrete;
        }
        sort(source + 1, source + n + 1, [](const node &a, const node &b) { return a.e > b.e; });
        //并查集操作。保留的f[]为不重复的数量
        for (int i = 1; i <= reu; ++i)
        {
            f[i] = i;
        }
        for (int i = 1; i <= n; ++i)
        {
            int r1 = find(source[i].x);
            int r2 = find(source[i].y);
            if (source[i].e) //x和y相容
            {
                f[r1] = r2;
            }
            else if (r1 == r2) //x和y不容
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