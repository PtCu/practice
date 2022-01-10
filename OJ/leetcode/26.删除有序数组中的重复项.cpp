// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem26.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)return 0;
        int first_unique = 1;
        for (int i = 1;i < nums.size();++i) {
            if (nums[i] != nums[i - 1]) {
                nums[first_unique++] = nums[i];
            }
        }
        return first_unique;
    }
};
// @lc code=end

