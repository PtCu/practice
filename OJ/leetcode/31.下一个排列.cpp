// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem31.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

 // @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 1;
        //从后向前找第一个顺序的数
        for (;i > 0 && nums[i - 1] >= nums[i];--i)
            ;
        --i;
        if (i < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int j = n - 1;
        //从后向前（直到i为止）找第一个比nums[i]大的数
        for (;j > i && nums[i] >= nums[j];--j)
            ;
        swap(nums[i], nums[j]);
        //反转[i+1,n]内的数字
        reverse(nums.begin() + i + 1, nums.end());
    }
};
// @lc code=end

