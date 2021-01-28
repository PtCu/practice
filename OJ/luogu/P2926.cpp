#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1000100; //数组大小
const int maxn = 1000000;
int n, a[Maxn], c[Maxn], w[Maxn]; //n个数，数列，数字统计容器，贡献值
int main()
{
    scanf("%d", &n); //输入
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]); //输入数列
        c[a[i]]++;
    }
    for (int i = 1; i <= maxn; i++)
        for (int j = i; j <= maxn; j += i)
            w[j] += c[i]; //i这个数会对j产生c[i]的贡献。j是i的倍数
    for (int i = 1; i <= n; i++)
        printf("%d\n", w[a[i]] - 1); //输出时要把a[i]对自己的贡献减去
    return 0;
}
