#
# @lc app=leetcode.cn id=15 lang=python3
#
# [15] 三数之和
#
# https://leetcode-cn.com/problems/3sum/description/
#
# algorithms
# Medium (25.87%)
# Likes:    1895
# Dislikes: 0
# Total Accepted:    173.9K
# Total Submissions: 670.6K
# Testcase Example:  '[-1,0,1,2,-1,-4]'
#
# 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
# ？请你找出所有满足条件且不重复的三元组。
# 
# 注意：答案中不可以包含重复的三元组。
# 
# 
# 
# 示例：
# 
# 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
# 
# 满足要求的三元组集合为：
# [
# ⁠ [-1, 0, 1],
# ⁠ [-1, -1, 2]
# ]
# 
# 
#
# [-4,-1,-1,0,1,2]
# @lc code=start
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        length=len(nums)
        if not nums or length<3:    #判空用not a,而不是a is None
            return []
        nums.sort()
        ans=[]
        for i in range(length-2):
            if nums[i]>0:
                return ans
            if(i>0 and nums[i]==nums[i-1]):
                continue
            L=i+1
            R=length-1
            while L<R:
                sum=nums[i]+nums[L]+nums[R]
                if(sum==0):
                    ans.append([nums[i],nums[L],nums[R]])
                    while L<R and nums[L]==nums[L+1]:
                        L=L+1
                    while L<R and nums[R]==nums[R-1]:
                        R=R-1
                    L=L+1   #成功匹配后左右同时靠拢
                    R=R-1
                elif sum>0:
                    while nums[R]==nums[R+1] and L<R:
                        R-=1
                    R-=1
                else:
                    while nums[L]==nums[L-1] and L<R:
                        L+=1
                    L+=1
        return ans
            


# @lc code=end

