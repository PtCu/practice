#
# @lc app=leetcode.cn id=53 lang=python3
#
# [53] 最大子序和
#
# https://leetcode-cn.com/problems/maximum-subarray/description/
#
# algorithms
# Easy (49.58%)
# Likes:    1753
# Dislikes: 0
# Total Accepted:    188.5K
# Total Submissions: 377.6K
# Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
#
# 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
# 
# 示例:
# 
# 输入: [-2,1,-3,4,-1,2,1,-5,4],
# 输出: 6
# 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
# 
# 
# 进阶:
# 
# 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
# 
#

# @lc code=start
class Solution:
    #贪心算法
    # def maxSubArray(self, nums: List[int]) -> int:
    #     size=len(nums)
    #     cur_sum=nums[0]   #当前元素最大和
    #     max_sum=nums[0]   #迄今为止最大和
    #     for i in range(1,size):
    #         cur_sum=max(nums[i],nums[i]+cur_sum)    #取当前最大的元素
    #         max_sum=max(cur_sum,max_sum)            #取迄今为止最大的元素
        
    #     return max_sum

    #动态规划
    def maxSubArray(self, nums: List[int]) -> int:
    # f(k): max subarray sum of nums[0..k), ending with nums[k-1]
    # res = max { f(k) }

    # f(0) = 0
    # f(k) = max{ f(k-1), 0 } + nums[k-1]
        size=len(nums)
        dp=[0]*size
        dp[0]=nums[0]
        res=dp[0]
        #状态转移方程:dp[i]=max(dp[i-1]+nums[i],nums[i])
        for i in range(1,size):
            if dp[i-1]>0:
                dp[i]=dp[i-1]+nums[i]
            else:
                dp[i]=nums[i]
            res=max(res,dp[i])
        return res

    #分治
    def cross_sum(self, nums, left, right, p):
        if left==right:
            return nums[left]
        #确定从中间向左，一直连续的子数组的最大和（从右至左）
        left_sum=float("-inf")
        cur_sum=0
        for i in range(p,left-1,-1):
            cur_sum+=nums[i]    #加上当前的数 现在的和
            left_sum=max(left_sum,cur_sum)  #如果加上当前的数之后和变小了就取之前最大的
        #确定从中间向右，一直连续的子数组的最大和（从左至右）
        right_sum=float("-inf")
        cur_sum=0
        for i in range(p+1,right+1):
            cur_sum+=nums[i]
            right_sum=max(right_sum,cur_sum)
        #返回两半部分的和
        return right_sum+left_sum

    def helper(self, nums, left, right): 
        if left==right:
            return nums[left]
        p=(left+right)//2
        left_sum=self.helper(nums,left,p)
        right_sum=self.helper(nums,p+1,right)
        cross_sum=self.cross_sum(nums, left, right, p)
        
        return max(left_sum,right_sum,cross_sum)

    def maxSubArray(self, nums: 'List[int]') -> 'int':
        return self.helper(nums,0,len(nums)-1)
# @lc code=end

