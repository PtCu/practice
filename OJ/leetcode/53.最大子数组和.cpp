// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem53.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int>dp;
        int n = nums.size();
        dp.resize(n);
        int ans = nums[0];
        dp[0] = nums[0];
        for (int i = 1;i < n;++i) {
            dp[i] = max(dp[i - 1], 0) + nums[i];
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
// @lc code=end

