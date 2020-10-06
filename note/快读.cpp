 #include <stdio.h>
//读入int的快读
 int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
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
//快读>scanf>cin

//字符串。直接调用cin.getline或gets即可
const int SZ = 1 << 20; //快速io
struct fastio
{
    char inbuf[SZ];
    char outbuf[SZ];
    fastio()
    {
        setvbuf(stdin, inbuf, _IOFBF, SZ);
        setvbuf(stdout, outbuf, _IOFBF, SZ);
    }
} io;