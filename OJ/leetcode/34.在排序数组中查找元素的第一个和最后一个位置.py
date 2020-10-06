#
# @lc app=leetcode.cn id=34 lang=python3
#
# [34] 在排序数组中查找元素的第一个和最后一个位置
#
# https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
#
# algorithms
# Medium (39.13%)
# Likes:    344
# Dislikes: 0
# Total Accepted:    71.8K
# Total Submissions: 183.1K
# Testcase Example:  '[5,7,7,8,8,10]\n8'
#
# 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
# 
# 你的算法时间复杂度必须是 O(log n) 级别。
# 
# 如果数组中不存在目标值，返回 [-1, -1]。
# 
# 示例 1:
# 
# 输入: nums = [5,7,7,8,8,10], target = 8
# 输出: [3,4]
# 
# 示例 2:
# 
# 输入: nums = [5,7,7,8,8,10], target = 6
# 输出: [-1,-1]
# 
#

# @lc code=start
from typing import List
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if not nums:
            return [-1,-1]
        n=len(nums)
        left=0;right=n-1
        while left<=right:
            mid=(left+right)//2
            if nums[mid]<target:
                left=mid+1
            elif nums[mid]>target:
                right=mid-1
            else:
                l=r=mid
                while l>0 and nums[l]==nums[l-1]:
                    l-=1
                while r<n-1 and nums[r]==nums[r+1]:
                    r+=1
                return [l,r]

        return [-1,-1]
# @lc code=end
if __name__ == "__main__":
    print(Solution().searchRange([5,7,7,8,8,10],6))

