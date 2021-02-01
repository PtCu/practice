#include <cstdio>
int n, j, sum, maxx;
int main()
{
    scanf("%d%d", &n, &maxx);
    sum = maxx; //输入n
    while (--n)
    {
        scanf("%d", &j);
        sum = sum > 0 ? sum : 0;
        sum += j;
        maxx = maxx > sum ? maxx : sum;
    }                                //贪心，如果负了就舍去
    return (printf("%d", maxx)) & 0; //输出并return 0
}