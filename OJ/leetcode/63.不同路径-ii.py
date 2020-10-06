#
# @lc app=leetcode.cn id=63 lang=python3
#
# [63] 不同路径 II
#
# https://leetcode-cn.com/problems/unique-paths-ii/description/
#
# algorithms
# Medium (32.46%)
# Likes:    256
# Dislikes: 0
# Total Accepted:    51K
# Total Submissions: 156.4K
# Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
#
# 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
# 
# 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
# 
# 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
# 
# 
# 
# 网格中的障碍物和空位置分别用 1 和 0 来表示。
# 
# 说明：m 和 n 的值均不超过 100。
# 
# 示例 1:
# 
# 输入:
# [
# [0,0,0],
# [0,1,0],
# [0,0,0]
# ]
# 输出: 2
# 解释:
# 3x3 网格的正中间有一个障碍物。
# 从左上角到右下角一共有 2 条不同的路径：
# 1. 向右 -> 向右 -> 向下 -> 向下
# 2. 向下 -> 向下 -> 向右 -> 向右
# 
# 
#

# @lc code=start
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        if obstacleGrid[0][0]==1:
            return 0
        m=len(obstacleGrid)
        n=len(obstacleGrid[0])
 
        obstacleGrid[0][0]=1
        for i in range(1,m):
            if obstacleGrid[i][0]==0:
                obstacleGrid[i][0]=obstacleGrid[i-1][0]
            else:
                obstacleGrid[i][0]=0
        for i in range(1,n):
            if obstacleGrid[0][i]==0:
                obstacleGrid[0][i]=obstacleGrid[0][i-1]
            else:
                obstacleGrid[0][i]=0
        for i in range(1,m):
            for j in range(1,n):
                if obstacleGrid[i][j]==0:
                    obstacleGrid[i][j]=obstacleGrid[i-1][j]+obstacleGrid[i][j-1]
                else:
                    obstacleGrid[i][j]=0
        return obstacleGrid[m-1][n-1]
# @lc code=end

