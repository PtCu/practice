#
# @lc app=leetcode.cn id=39 lang=python3
#
# [39] 组合总和
#
# https://leetcode-cn.com/problems/combination-sum/description/
#
# algorithms
# Medium (68.53%)
# Likes:    559
# Dislikes: 0
# Total Accepted:    73.5K
# Total Submissions: 107.2K
# Testcase Example:  '[2,3,6,7]\n7'
#
# 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
# 
# candidates 中的数字可以无限制重复被选取。
# 
# 说明：
# 
# 
# 所有数字（包括 target）都是正整数。
# 解集不能包含重复的组合。 
# 
# 
# 示例 1:
# 
# 输入: candidates = [2,3,6,7], target = 7,
# 所求解集为:
# [
# ⁠ [7],
# ⁠ [2,2,3]
# ]
# 
# 
# 示例 2:
# 
# 输入: candidates = [2,3,5], target = 8,
# 所求解集为:
# [
# [2,2,2,2],
# [2,3,3],
# [3,5]
# ]
# 
#

# @lc code=start
from typing import List
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res=[]
        candidates.sort()
        self.__dfs(candidates,target,0,[],res)
        return res
    def __dfs(self, nums, target, index, path, res):
        # if target<0:
        #     return
        if target==0:
            res.append(path)
            return
        for i in range(index,len(nums)):
            #将i当作index传入，为下一次递归的起点
            #如果Target<0，就返回。此时进行i+1，找下一个
            #从这一索引开始
            if nums[i]>target:
                return
            self.__dfs(nums,target-nums[i],i,path+[nums[i]],res)    

       
# @lc code=end
if __name__ == "__main__":
    print(Solution().combinationSum([2,3,6,7],7))

