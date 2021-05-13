//https://www.luogu.com.cn/problem/solution/P1439
// 关于为什么可以转化成LIS问题，这里提供一个解释。
// A:3 2 1 4 5
// B:1 2 3 4 5
// 我们不妨给它们重新标个号：把3标成a,把2标成b，把1标成c……于是变成：
// A: A b c d e
// B: c b A d e
// 这样标号之后，LCS长度显然不会改变。但是出现了一个性质：
// 两个序列的子序列，一定是A的子序列。而A本身就是单调递增的。
// 因此这个子序列是单调递增的。
// 换句话说，只要这个子序列在B中单调递增，它就是A的子序列。
// 哪个最长呢？当然是B的LIS最长。
// 自此完成转化。
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
int A[maxn];
int B[maxn];
int d[maxn]; //d[i]表示长度为i的子序列中最大的数字。d递增
int n;
int LIS()
{
    int len = 1;
    d[1] = B[1];
    for (int i = 2; i <= n; ++i)
    {
        if (B[i] > d[len])
        {
            d[++len] = B[i];
        }
        else
        {
            //找到d[i-1]<B[i]<d[i]的下标i
            int pos = upper_bound(d + 1, d + 1 + len, B[i]) - d;
            d[pos] = B[i];
        }
    }
    return len;
}
int main()
{

    cin >> n;
    int x;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x;
        A[x] = i;
    }
    //求B在A中的顺序即可
    for (int i = 1; i <= n; ++i)
    {
        cin >> x;
        B[i] = A[x];
    }
    cout << LIS();
}