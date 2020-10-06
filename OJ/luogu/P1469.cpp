#include <bits/stdc++.h>
using namespace std;

 int read()//这是一个读入数字的快读
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
int main()
{
    int n;
    n=read();
    int ans=0;
    for (int i = 0; i < n; i++)
    {
        int x;
        x=read();
        ans^=x;
        
    }
    cout<<ans;
}