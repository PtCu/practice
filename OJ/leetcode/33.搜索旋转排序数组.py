#
# @lc app=leetcode.cn id=33 lang=python3
#
# [33] 搜索旋转排序数组
#
# https://leetcode-cn.com/problems/search-in-rotated-sorted-array/description/
#
# algorithms
# Medium (36.45%)
# Likes:    561
# Dislikes: 0
# Total Accepted:    84.4K
# Total Submissions: 231.2K
# Testcase Example:  '[4,5,6,7,0,1,2]\n0'
#
# 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
# 
# ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
# 
# 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
# 
# 你可以假设数组中不存在重复的元素。
# 
# 你的算法时间复杂度必须是 O(log n) 级别。
# 
# 示例 1:
# 
# 输入: nums = [4,5,6,7,0,1,2], target = 0
# 输出: 4
# 
# 
# 示例 2:
# 
# 输入: nums = [4,5,6,7,0,1,2], target = 3
# 输出: -1
# 
#

# @lc code=start
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if not nums:
            return -1
        left=0;right=len(nums)-1
        while left<=right:      #注意等号.eg: length=1时
            mid=(left+right)//2
            if target==nums[mid]:
                return mid
            elif nums[left]<=nums[mid]: #在left到mid区间上连续
                if nums[left]<=target and target<=nums[mid]:
                    right=mid-1 #收缩后的区间不包括mid
                else:   
                    left=mid+1  #收缩后的区间不包括mid
            else:                       #在mid到right区间上连续
                if nums[mid]<=target and target<=nums[right]:
                    left=mid+1  #收缩后的区间不包括mid
                else:
                    right=mid-1 #收缩后的区间不包括mid
        
        return -1
# @lc code=end

