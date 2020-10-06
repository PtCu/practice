#
# @lc app=leetcode.cn id=35 lang=python3
#
# [35] 搜索插入位置
#
# https://leetcode-cn.com/problems/search-insert-position/description/
#
# algorithms
# Easy (45.25%)
# Likes:    454
# Dislikes: 0
# Total Accepted:    131.2K
# Total Submissions: 289.3K
# Testcase Example:  '[1,3,5,6]\n5'
#
# 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
# 
# 你可以假设数组中无重复元素。
# 
# 示例 1:
# 
# 输入: [1,3,5,6], 5
# 输出: 2
# 
# 
# 示例 2:
# 
# 输入: [1,3,5,6], 2
# 输出: 1
# 
# 
# 示例 3:
# 
# 输入: [1,3,5,6], 7
# 输出: 4
# 
# 
# 示例 4:
# 
# 输入: [1,3,5,6], 0
# 输出: 0
# 
# 
#

# @lc code=start
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if not nums:
            return None
        length=len(nums)
        l=0;r=length-1
        while l<=r:
            mid=(l+r)//2
            if target>nums[mid]:
                l=mid+1
            elif target<nums[mid]:
                r=mid-1
            else:
                return mid
        if nums[mid]>target:
            return mid
            
        else:
            return mid+1
       
    
# @lc code=end

