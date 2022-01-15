// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include<unordered_map>
#include "commoncppproblem1.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        unordered_map<int, int> dict;
        for (int i = 0;i < nums.size();++i) {
            if (!dict.count(nums[i])) {
                dict[target - nums[i]] = i;
            }
            else {
                ans.push_back(dict[nums[i]]);
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};
// @lc code=end

