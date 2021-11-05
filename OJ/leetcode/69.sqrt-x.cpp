/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution
{
public:
    int mySqrt(int x)
    {
        int low = 0, high = x, mid = 0;
        int ans = 0;
        //[low,high]
        while (low <= high)
        {
            mid = low + (high - low) / 2;
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
};
// @lc code=end
