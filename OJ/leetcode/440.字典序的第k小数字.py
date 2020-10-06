#
# @lc app=leetcode.cn id=440 lang=python3
#
# [440] 字典序的第K小数字
#
# https://leetcode-cn.com/problems/k-th-smallest-in-lexicographical-order/description/
#
# algorithms
# Hard (32.02%)
# Likes:    69
# Dislikes: 0
# Total Accepted:    2.8K
# Total Submissions: 8.7K
# Testcase Example:  '13\n2'
#
# 给定整数 n 和 k，找到 1 到 n 中字典序第 k 小的数字。
# 
# 注意：1 ≤ k ≤ n ≤ 10^9。
# 
# 示例 :
# 
# 
# 输入:
# n: 13   k: 2
# 
# 输出:
# 10
# 
# 解释:
# 字典序的排列是 [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9]，所以第二小的数字是 10。
# 
# 
#

# @lc code=start
class Solution:
    def findKthNumber(self, n: int, k: int) -> int:
        
# @lc code=end

