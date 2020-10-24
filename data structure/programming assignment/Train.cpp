#include <iostream>
const int MAX = 1.6e6;
int stack[MAX];
int output[MAX];
bool isPush[7 * MAX];
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
int main(int argc, char **argv)
{
    int m, n;
    scanf("%d %d", &n, &m);
    int top = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &output[i]); //待判断的出栈序列
    }
    int j = 1; //出栈序列的指针
    int k = 0; //输出是push还是pop
    bool isOk = true;
    //遍历输入序列（1，2，3，4...)
    for (int i = 1; i <= n; i++)
    {
        if (top < m)
        {
            stack[++top] = i; //push操作
            isPush[k++] = true;
        }
        else
            isOk = false;
        while (top > 0 && stack[top] == output[j])
        {
            //pop操作
            top--;
            isPush[k++] = false;
            j++;
        }
    }
    if(!isOk||top!=0){
        printf("No\n");
    }
    else  //最终栈为空
    {
        for (int i = 0; i < k; i++)
        {
            if (isPush[i])
                printf("push\n");
            else
                printf("pop\n");
        }
    }
    
}
