#include <bits/stdc++.h>

/*
二分查找的函数有 3 个： 
lower_bound(起始地址，结束地址，要查找的数值) 返回的是数值 第一个 出现的位置。 大于等于
upper_bound(起始地址，结束地址，要查找的数值) 返回的是 第一个大于待查找数值 出现的位置。  大于
binary_search(起始地址，结束地址，要查找的数值)  返回的是是否存在这么一个数，是一个bool值。
注意：使用二分查找的前提是数组有序。
*/

//简单二分查找，输入参数x满足：x>=1
int iqrt2(unsigned x)
{
    unsigned a = 1;            //下界
    unsigned b = (x >> 5) + 8; //上界
    if (b > 65535)
        b = 65535;
    do
    {
        int m = (a + b) >> 1;
        if (m * m > x)
            b = m - 1;
        else
            a = m + 1;
    } while (b >= a);
    return a - 1;
}

unsigned ss[16] = {
    4,       //(1+1)^2
    9,       //(2+1)^2
    25,      //(4+1)^2
    81,      //(8+1)^2
    17 * 17, //(16+1)^2  (2^s+1)^2
    33 * 33,
    65 * 65,
    129 * 129,
    257 * 257,
    513 * 513,
    1025 * 1025,
    2049 * 2049,
    4097 * 4097,
    8193 * 8193,
    16385 * 16385,
    32769 * 32769,
};

unsigned my_isqrt(unsigned c)
{
    if (c <= 1)
        return c;
    unsigned *temp = std::upper_bound(ss, ss + 16, c);
    int s = temp - ss;             //c的整数平方根下取整在[2^(s-1)+1,2^s+1),即(2^(s-1),2^s]之间
    int x0 = 1 << s;               //x0为上界,c>>s为下界(即 (x0)^2/(2^s) ) (可证明)
    int x1 = (x0 + (c >> s)) >> 1; //取中间
    while (x1 < x0)
    {
        x0 = x1;
        x1 = (x0 + c / x0) >> 1;
    }
    return x0;
}

//牛顿迭代法，初始值选取速度快但是没有达到最优
//s并不严格符合2^(s-1)<floor(sqrt(x))<=2^s
int isqrt3(unsigned x)
{
    if (x <= 1)
        return x;
    int x1 = x - 1;
    int s = 1; //x的整数平方根在2^s次方到2^(s-1)次方之间
    if (x1 > 65535)
    {
        s += 8;
        x1 >>= 16;
    }
    if (x1 > 255)
    {
        s += 4;
        x1 >>= 8;
    }
    if (x1 > 15)
    {
        s += 2;
        x1 >>= 4;
    }
    if (x1 > 3)
    {
        s += 1;
    }
    int x0 = 1 << s;           //x0为上界
    x1 = (x0 + (x >> s)) >> 1; //x0为上界,x>>s为下界(即 (x0)^2/(2^s) ) (可证明)

    while (x1 < x0)
    {
        x0 = x1;
        x1 = (x0 + x / x0) >> 1;
    }
    return x0;
}

unsigned int isqrt4(unsigned long M)
{
    unsigned int N, i;
    unsigned long tmp, ttp; //结果、循环计数
    if (M == 0)             //被开方数，开方结果也为0
        return 0;
    N = 0;

    tmp = (M >> 30); //获取最高位：B[m-1]
    M << 2;
    if (tmp > 1)    //最高位为1
    {
        N++;        //结果当前位为1
        tmp -= N;   //否则为默认的0
    }
    for (i = 15; i > 0; i--)
    {
        N <<= 1;

        tmp <<= 2;
        tmp += (M >> 30);

        ttp = N;
        ttp = (ttp << 1) + 1;
        M <<= 2;
        if (tmp >= ttp)
        {
            tmp -= ttp;
            N++;
        }
    }
    return N;
}
int main()
{
    int source;
    std::cin >> source;
    time_t start1, stop1;
    start1 = time(NULL);
    for (int i = 0; i < 1e6; i++)
    {
        std::cout << isqrt3(source) << std::endl;
    }
    stop1 = time(NULL);
    std::cout << stop1 - start1 << std::endl;
    time_t start2, stop2;
    start2 = time(NULL);
    for (int i = 0; i < 1e6; i++)
    {
        std::cout << sqrt(source) << std::endl;
    }
    stop2 = time(NULL);
    std::cout << stop2 - start2 << std::endl;
}
