#
# @lc app=leetcode.cn id=40 lang=python3
#
# [40] 组合总和 II
#
# https://leetcode-cn.com/problems/combination-sum-ii/description/
#
# algorithms
# Medium (60.55%)
# Likes:    221
# Dislikes: 0
# Total Accepted:    45.6K
# Total Submissions: 75.1K
# Testcase Example:  '[10,1,2,7,6,1,5]\n8'
#
# 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
# 
# candidates 中的每个数字在每个组合中只能使用一次。
# 
# 说明：
# 
# 
# 所有数字（包括目标数）都是正整数。
# 解集不能包含重复的组合。 
# 
# 
# 示例 1:
# 
# 输入: candidates = [10,1,2,7,6,1,5], target = 8,
# 所求解集为:
# [
# ⁠ [1, 7],
# ⁠ [1, 2, 5],
# ⁠ [2, 6],
# ⁠ [1, 1, 6]
# ]
# 
# 
# 示例 2:
# 
# 输入: candidates = [2,5,2,1,2], target = 5,
# 所求解集为:
# [
# [1,2,2],
# [5]
# ]
# 
#

# @lc code=start
from typing import List
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        res=[]
        candidates.sort()   #通过排序来防止重复
       
        self.__dfs(candidates,target,0,[],res)
        return res
    def __dfs(self,nums,target,index,path,res):
        if target<0:
            return
        # Base case: if the sum of the path satisfies the target, we will consider 
        # it as a solution, and stop there
        elif target==0:
            res.append(path)
            return 
        for i in range(index,len(nums)):
            #同一层级上遇到重复的就跳过，避免同一层级的重复
            if i>index and nums[i]==nums[i-1]:
                continue
            if nums[i]>target:
                break
            #从下一索引开始
            self.__dfs(nums,target-nums[i],i+1,path+[nums[i]],res)

# @lc code=end
if __name__ == "__main__":
    [1,1,2,5,6,7,10]
    Solution().combinationSum2([10,1,2,7,6,1,5],8)

