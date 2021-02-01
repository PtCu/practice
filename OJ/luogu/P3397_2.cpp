#include <cstdio>
#include <iostream>
using namespace std;
int a[2000][2000]; //差分：当前数组元素和先前数组元素之差
int main()
{
    int n, m;
    int x1, y1, x2, y2;
    scanf("%d%d", &n, &m);
    
    // 1 0 0 0 -1
    // 0 0 0 0 0
    // 0 0 0 0 0
    // -1 0 0 0 1
    while (m--) 
    {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        ++a[x1][y1];
        --a[x2 + 1][y1];
        --a[x1][y2 + 1];
        ++a[x2+1][y2+1];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++) 
        {
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
            printf("%d ", a[i][j]);  //复原后输出
        }
        printf("\n"); //换行
    }
    return 0;
}