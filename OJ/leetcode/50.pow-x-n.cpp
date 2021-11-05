/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
#include <bits/stdc++.h>
class Solution
{
public:
    double myPow(double x, int n)
    {
        double ans = 1;
        bool isNeg = false;
        long abs_n = abs(n);
        while (abs_n)
        {
            if (abs_n & 1)
            {
                ans *= x;
            }
            x *= x;
            abs_n >>= 1;
        }
        if (n < 0)
            ans = 1 / ans;

        return ans;
    }
};
// @lc code=end
