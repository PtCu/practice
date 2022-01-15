// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem33.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

 // @lc code=start
class Solution {
public:

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
                return mid;
            //去除两边，逐渐缩短
            if (nums[0] <= nums[mid]) {
                //当target位于nums[0]和nums[mid]之间时
                if (nums[0] <= target && target < nums[mid]) {
                    //往左找
                    r = mid - 1;
                }
                //其余往右找，去除左端
                else {
                    l = mid + 1;
                }
            }
            else {
                //当target位于nums[mid]和nums[n-1]之间时
                if (nums[mid] < target && target <= nums[n - 1]) {
                    //往右找
                    l = mid + 1;
                }
                //其余往左找，去除右端
                else {
                    r = mid - 1;
                }
            }
        }
        return -1;


    }
};
// @lc code=end

