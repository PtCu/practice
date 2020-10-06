#include<cstdio>
#include<iostream>
using namespace std;
int cf[2000][2000]; //差分：当前数组元素和先前数组元素之差
int main()
{
    int n,m;
    int x1,y1,x2,y2;
    scanf("%d%d",&n,&m);
    while(m--)//循环的另一种方式（m==0时，会自动跳出，所以循环m遍）
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        for(int i=x1;i<=x2;i++)//每一行进行差分，时间复杂度O(N) 
        {
            cf[i][y1]++;
            cf[i][y2+1]--;//差分
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)   //按列复原
        {
            cf[i][j]+=cf[i][j-1];//复原，利用A[I]-A[I-1]=B[I]，可以推得B[I]+A[I-1]=A[I]（因为B[I-1]已被复原为A[I-1]，所以得到此递推公式）
            printf("%d ",cf[i][j]);//复原后输出
        }
        printf("\n");//换行
    }
    return 0;
}