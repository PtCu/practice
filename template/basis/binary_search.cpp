#include <bits/stdc++.h>
//注意细节
//https://www.zhihu.com/question/36132386
//https://blog.csdn.net/wingWC/article/details/78229684

//建议用闭区间写法

//[l,r]的写法：
int mySqrt(int x)
{
    int low = 0, high = x, mid = 0;
    int ans = 0;
    //[low,high] 等号
    while (low <= high)
    {
        mid = low + (high - low) / 2; //写(low+high)/2容易溢出
        if ((long long)mid * mid > x)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
            ans = mid;
        }
    }
    return ans;
}

//[l,r)的写法：
int mySqrt(int x)
{
    int low = 0, high = x, mid = 0;
    int ans = 0;
    //[low,high）
    while (low < high)
    {
        mid = low + (high - low) / 2;
        if ((long long)mid * mid > x)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
            ans = mid;
        }
    }
    return ans;
}