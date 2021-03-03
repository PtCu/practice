#include <cstdio>  
#include <cstring>  
#define maxn 50047  
int c[maxn], a[maxn]; 
int n,t;
//加lowbit等于找父亲，减lowbit等于找儿子
int Lowbit(int x)  // 2^k
{
	return x&(-x);
}
void update(int i, int x)//i点增量为x
{
	while(i <= n)
	{
		c[i] += x;
		i += Lowbit(i);
	}
}
int sum(int x)//区间求和 [1,x]
{
	int sum=0;
	while(x>0)
	{
		sum+=c[x];
		x-=Lowbit(x);
	}
	return sum;
}
  
int Getsum(int x1,int x2) //求任意区间和
{ 
    return sum(x2) - sum(x1-1); 
}  
int main() 
{ 
	int i , j;
    scanf("%d",&t); 
    int count = 0; 
    while(t--) 
    { 
        count++; 
        memset(a,0,sizeof(a)); 
        memset(c,0,sizeof(c)); 
        scanf("%d",&n); 
        for(i = 1; i <= n; i++) //i须从1开始
        { 
            scanf("%d",&a[i]); 
            update(i,a[i]); //初始的人数
        }   
        printf("Case %d:\n",count); 
        char oper[11]; 
        while(scanf("%s",oper)==1) 
        { 
            if(strcmp(oper,"End")==0) 
                break; 
            scanf("%d%d",&i,&j); 
            if(strcmp(oper,"Query")==0) 
            { 
                printf("%d\n",Getsum(i,j)); 
            } 
            if(strcmp(oper,"Add")==0) //表示第i个营地增加j个人
            { 
                a[i] += j; 
                update(i,j); 
            } 
            if(strcmp(oper,"Sub")==0) //表示第i个营地减少j个人
            { 
                a[i] -= j; 
                update(i,-j); 
            } 
        } 
    } 
    return 0; 
} 