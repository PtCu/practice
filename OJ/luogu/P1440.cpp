#include <cstdio>
int n, m, a[2000000], q[2000000], l = 1, r = 0;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
    {
        printf("%d\n", a[q[l]]); //输出队首
        if (i - q[l] + 1 > m && l <= r)
            l++; //查看队首是否在区间内，不在的话出队列
        while (a[i] < a[q[r]] && l <= r)
            r--; //进队比较，把比它大的都踢出去
        q[++r] = i;
    }
}