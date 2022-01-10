// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem384.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=384 lang=cpp
 *
 * [384] 打乱数组
 */

// @lc code=start
class Solution {
    vector<int> _nums;
    vector<int>origin;
public:
    Solution(vector<int>& nums) {
        this->_nums = nums;
        this->origin.resize(nums.size());
        copy(nums.begin(), nums.end(), origin.begin());
    }

    vector<int> reset() {
        copy(origin.begin(), origin.end(), _nums.begin());
      
        return _nums;
    }

    vector<int> shuffle() {
        //在[i,n)中随机取一个下标与i交换
        for (int i = 0;i < _nums.size();++i) {
            int j = i + rand() % (_nums.size() - i);
            swap(_nums[i], _nums[j]);
        }
        return _nums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
 // @lc code=end

