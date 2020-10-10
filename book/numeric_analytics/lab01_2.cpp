#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
// const int N = 16;
// const int MAX = 9999999;
// float p[N + 1] = {
//     0,
//     0,
//     0,
//     0,
//     0,
//     0,
//     0,
//     0,
//     0,
//     0,
//     0,
//     0,
// };
// float q[N + 1] = {0, 1.0 / 128, 1.0 / 64, 1.0 / 32, 1.0 / 16, 1.0 / 8, 1.0 / 4, 1.0 / 2, 0, 0, 0, 0, 0, 0, 0, 0};

// float e[N + 2][N + 1];
// int root[N + 1][N + 1];
// float w[N + 2][N + 1];

// void optimal_bst_search_tree(float p[], float q[], int n)
// {
//     int i;
//     for (i = 1; i <= n + 1; i++)
//     {
//         e[i][i - 1] = q[i - 1];
//         w[i][i - 1] = q[i - 1];
//     }
//     int l, j, r;
//     for (l = 1; l <= n; l++)
//     {
//         for (i = 1; i <= n - l + 1; i++) //步长
//         {
//             j = i + l - 1;
//             e[i][j] = MAX;
//             w[i][j] = w[i][j - 1] + p[j] + q[j];
//             for (r = i; r <= j; r++)
//             {
//                 double t = e[i][r - 1] + e[r + 1][j] + w[i][j];
//                 if (t < e[i][j])
//                 {
//                     e[i][j] = t;
//                     root[i][j] = r;
//                 }
//             }
//         }
//     }
// }

// void construct_optimal_bst(int i, int j)
// {
//     if (i <= j)
//     {
//         int r = root[i][j];
//         cout << r << " ";
//         construct_optimal_bst(i, r - 1);
//         construct_optimal_bst(r + 1, j);
//     }
// }

/*
二分查找的函数有 3 个： 
lower_bound(起始地址，结束地址，要查找的数值) 返回的是数值 第一个 出现的位置。 大于等于
upper_bound(起始地址，结束地址，要查找的数值) 返回的是 第一个大于待查找数值 出现的位置。  大于
binary_search(起始地址，结束地址，要查找的数值)  返回的是是否存在这么一个数，是一个bool值。
注意：使用二分查找的前提是数组有序。
*/

//简单二分查找，输入参数x满足：x>=1
unsigned int isqrt2(unsigned x)
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
unsigned int isqrt2(unsigned x, unsigned long long &times)
{
    unsigned a = 1;            //下界
    unsigned b = (x >> 5) + 8; //上界
    if (b > 65535)
        b = 65535;
    do
    {
        times++;
        int m = (a + b) >> 1;
        if (m * m > x)
            b = m - 1;
        else
            a = m + 1;
    } while (b >= a);
    return a - 1;
}

unsigned ss[16] = {
    4,       //(1+1)^2  (2^0+1)^2
    9,       //(2+1)^2  (2^1+1)^2
    25,      //(4+1)^2  (2^2+1)^2
    81,      //(8+1)^2  (2^3+1)^2
    17 * 17, //(16+1)^2 (2^4+1)^2
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

unsigned int my_isqrt(unsigned c)
{
    if (c <= 1)
        return c;
    unsigned *temp = std::upper_bound(ss, ss + 16, c);
    int s = temp - ss;             //c的整数平方根下取整在[2^(s-1)+1,2^s+1),即(2^(s-1),2^s]之间
    unsigned int x0 = 1 << s;      //x0为上界,c>>s为下界(即 (x0)^2/(2^s) ) (可证明)
    int x1 = (x0 + (c >> s)) >> 1; //取中间
    while (x1 < x0)
    {
        x0 = x1;
        x1 = (x0 + c / x0) >> 1;
    }
    return x0;
}
unsigned int my_isqrt(unsigned c, unsigned long long &times)
{
    if (c <= 1)
        return c;
    unsigned *temp = std::upper_bound(ss, ss + 16, c);
    int s = temp - ss;             //c的整数平方根下取整在[2^(s-1)+1,2^s+1),即(2^(s-1),2^s]之间
    unsigned int x0 = 1 << s;      //x0为上界,c>>s为下界(即 (x0)^2/(2^s) ) (可证明)
    int x1 = (x0 + (c >> s)) >> 1; //取中间
    while (x1 < x0)
    {
        times++;
        x0 = x1;
        x1 = (x0 + c / x0) >> 1;
    }
    return x0;
}

//牛顿迭代法，初始值选取速度快但是没有达到最优
//s并不严格符合2^(s-1)<floor(sqrt(x))<=2^s
unsigned int isqrt3(unsigned x)
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
    unsigned int x0 = 1 << s;  //x0为上界
    x1 = (x0 + (x >> s)) >> 1; //x0为上界,x>>s为下界(即 (x0)^2/(2^s) ) (可证明)

    while (x1 < x0)
    {
        x0 = x1;
        x1 = (x0 + x / x0) >> 1;
    }
    return x0;
}
unsigned int isqrt3(unsigned x, unsigned long long &times)
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
    unsigned int x0 = 1 << s;  //x0为上界
    x1 = (x0 + (x >> s)) >> 1; //x0为上界,x>>s为下界(即 (x0)^2/(2^s) ) (可证明)

    while (x1 < x0)
    {
        times++;
        x0 = x1;
        x1 = (x0 + x / x0) >> 1;
    }
    return x0;
}

unsigned int isqrt4(unsigned M)
{
    unsigned int N, i;
    unsigned long tmp, ttp; //结果、循环计数
    if (M == 0)             //被开方数，开方结果也为0
        return 0;
    N = 0;

    tmp = (M >> 30); //获取最高位：B[m-1]
    M << 2;
    if (tmp > 1) //最高位为1
    {
        N++;      //结果当前位为1
        tmp -= N; //否则为默认的0
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

unsigned int isqrt4(unsigned M, unsigned long long &times)
{
    unsigned int N, i;
    unsigned long tmp, ttp; //结果、循环计数
    if (M == 0)             //被开方数，开方结果也为0
        return 0;
    N = 0;

    tmp = (M >> 30); //获取最高位：B[m-1]
    M << 2;
    if (tmp > 1) //最高位为1
    {
        N++;      //结果当前位为1
        tmp -= N; //否则为默认的0
    }
    for (i = 15; i > 0; i--)
    {
        times++;
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
    unsigned (*isqrt_f[4])(unsigned x);
    isqrt_f[0] = my_isqrt;
    isqrt_f[1] = isqrt2;
    isqrt_f[2] = isqrt3;
    isqrt_f[3] = isqrt4;

    cout << "********************************" << endl;
    cout << setw(12) << left << "函数"
         << setw(12) << left << "误差"
         << setw(15) << left << "时间"
         << setw(10) << left << "平均迭代次数" << endl;

    LARGE_INTEGER start, stop, tc;
    double time_cost[5];
    bool hasError[4];
    memset(time_cost, 0, sizeof(time_cost));
    memset(hasError, 0, sizeof(time_cost));

    unsigned long max_n = 1UL << 31; //2^32

    int count = 0;
    for (unsigned long source = 1; source < max_n; source++)
    {
        //如果四种方法都有误差则提前结束
        if (count == 4)
            break;
        //求标准值
        unsigned int standard = (int)sqrt(source);
        //比较各个方法的误差
        for (int i = 0; i < 4; i++)
        {
            if (hasError[i])
                continue;
            if (isqrt_f[i](source) - standard)
            {
                hasError[i] = true;
                count++;
            }
        }
    }
    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&start);
    //记录标准库的用时
    for (unsigned long source = 1; source < max_n; source++)
    {
        sqrt(source);
    }

    QueryPerformanceCounter(&stop);
    time_cost[4] = (double)(stop.QuadPart - start.QuadPart) / (double)tc.QuadPart;

    //比较各个方法的用时
    for (int i = 0; i < 4; i++)
    {
        QueryPerformanceCounter(&start);
        for (unsigned int source = 1; source < max_n; source++)
        {
            isqrt_f[i](source);
        }
        QueryPerformanceCounter(&stop);
        time_cost[i] = (double)(stop.QuadPart - start.QuadPart) / (double)tc.QuadPart;
    }

    //为了比较每个方法的迭代次数的重载函数
    unsigned (*isqrt_f_t[4])(unsigned x, unsigned long long &t);
    isqrt_f_t[0] = my_isqrt;
    isqrt_f_t[1] = isqrt2;
    isqrt_f_t[2] = isqrt3;
    isqrt_f_t[3] = isqrt4;

    unsigned long long times[4];
    memset(times, 0, sizeof(times));
    for (int i = 0; i < 4; i++)
    {

        for (unsigned int source = 1; source < max_n; source++)
        {
            isqrt_f_t[i](source, times[i]);
        }
    }
    cout << setw(12) << left << "sqrt";
    cout << setw(12) << left << "无";
    cout << setw(15) << time_cost[4];
    cout << setw(10) << "/" << endl;
    for (int i = 0; i < 4; i++)
    {
        switch (i)
        {
        case 0:
            cout << setw(12) << left << "my_isqrt";
            break;
        case 1:
            cout << setw(12) << left << "isqrt2";
            break;
        case 2:
            cout << setw(12) << left << "isqrt3";
            break;
        case 3:
            cout << setw(12) << left << "isqrt4";
            break;
        default:
            break;
        }
        if (hasError[i])
            cout << setw(12) << left << "有";
        else
            cout << setw(12) << left << "无";
        cout << setw(15) << time_cost[i];
        cout << setw(10) << (double)times[i] / max_n << endl;
    }
}
