#
# @lc app=leetcode.cn id=64 lang=python3
#
# [64] 最小路径和
#
# https://leetcode-cn.com/problems/minimum-path-sum/description/
#
# algorithms
# Medium (64.78%)
# Likes:    426
# Dislikes: 0
# Total Accepted:    73.7K
# Total Submissions: 113K
# Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
#
# 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
# 
# 说明：每次只能向下或者向右移动一步。
# 
# 示例:
# 
# 输入:
# [
# [1,3,1],
# ⁠ [1,5,1],
# ⁠ [4,2,1]
# ]
# 输出: 7
# 解释: 因为路径 1→3→1→1→1 的总和最小。
# 
# 
#

# grid[i][j]=min(grid[i-1][j],grid[i][j-1])+grid[i][j]
# @lc code=start
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        if not grid:
            return 0
        m=len(grid)
        n=len(grid[0])
        for i in range(m):
            for j in range(n):
                if i!=0 and j!=0:
                    grid[i][j]=min(grid[i-1][j],grid[i][j-1])+grid[i][j]
                elif i==0 and j!=0:
                    grid[i][j]=grid[i][j]+grid[i][j-1]
                elif i!=0 and j==0:
                    grid[i][j]=grid[i-1][j]+grid[i][j]
                else:
                    continue
        
        return grid[m-1][n-1]
# @lc code=end

