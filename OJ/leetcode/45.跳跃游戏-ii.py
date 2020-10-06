#
# @lc app=leetcode.cn id=45 lang=python3
#
# [45] 跳跃游戏 II
#
# https://leetcode-cn.com/problems/jump-game-ii/description/
#
# algorithms
# Hard (33.37%)
# Likes:    392
# Dislikes: 0
# Total Accepted:    35.4K
# Total Submissions: 105.4K
# Testcase Example:  '[2,3,1,1,4]'
#
# 给定一个非负整数数组，你最初位于数组的第一个位置。
# 
# 数组中的每个元素代表你在该位置可以跳跃的最大长度。
# 
# 你的目标是使用最少的跳跃次数到达数组的最后一个位置。
# 
# 示例:
# 
# 输入: [2,3,1,1,4]
# 输出: 2
# 解释: 跳到最后一个位置的最小跳跃数是 2。
# 从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
# 
# 
# 说明:
# 
# 假设你总是可以到达数组的最后一个位置。
# 
#
from typing import List
# @lc code=start
class Solution:
    # def jump(self, nums: List[int]) -> int:
    #     if not nums:
    #         return 0
    #     size=len(nums)
    #     start=0;end=1
    #     ans=0
    #     while end<size:
    #         maxStep=0
    #         for i in range(start,end):
    #             #从下一个格子开始到现在能跳到最远的距离
    #             maxStep=max(maxStep,i+nums[i])
    #         start=end
    #         end=maxStep+1
    #         ans+=1
    #     return ans

    def jump(self, nums: List[int]) -> int:
        if not nums:
            return 0
        size=len(nums)
        ans=0;end=0
        maxStep=0
        #对每一个元素进行分析，
        for i in range(size-1):
            #确定最大步。最大步内的所有单元都可以是下一步能走的地方
            maxStep=max(nums[i]+i,maxStep)
            #当到达end时，说明已经遍历了最大步之内的所有单元，拿到了最大步之内的下一个最大步数。此时下一步走最大步
            if i==end:
                end=maxStep
                ans+=1
        return ans
# @lc code=end
if __name__ == "__main__":
    print(Solution().jump([2,3,1,1,4]))

