#
# @lc app=leetcode.cn id=41 lang=python3
#
# [41] 缺失的第一个正数
#
# https://leetcode-cn.com/problems/first-missing-positive/description/
#
# algorithms
# Hard (37.65%)
# Likes:    425
# Dislikes: 0
# Total Accepted:    42K
# Total Submissions: 111.3K
# Testcase Example:  '[1,2,0]'
#
# 给定一个未排序的整数数组，找出其中没有出现的最小的正整数。
# 
# 示例 1:
# 
# 输入: [1,2,0]
# 输出: 3
# 
# 
# 示例 2:
# 
# 输入: [3,4,-1,1]
# 输出: 2
# 
# 
# 示例 3:
# 
# 输入: [7,8,9,11,12]
# 输出: 1
# 
# 
# 说明:
# 
# 你的算法的时间复杂度应为O(n)，并且只能使用常数级别的空间。
# 
#

# @lc code=start
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        size=len(nums)
        for i in range(size):
            #利用哈希映射 number->number-1
            #判断是否是索引并且放在正确的地方
            while 1<=nums[i]<=size and nums[i]!=nums[nums[i]-1]:
                self.__swap(nums,i,nums[i]-1)
        for i in range(size):
            if i+1!=nums[i]:
                return i+1
        return size+1
    def __swap(self,nums,index1,index2):
        nums[index1],nums[index2]=nums[index2],nums[index1]
# @lc code=end

