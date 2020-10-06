#
# @lc app=leetcode.cn id=32 lang=python3
#
# [32] 最长有效括号
#
# https://leetcode-cn.com/problems/longest-valid-parentheses/description/
#
# algorithms
# Hard (29.84%)
# Likes:    562
# Dislikes: 0
# Total Accepted:    47.7K
# Total Submissions: 159.1K
# Testcase Example:  '"(()"'
#
# 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
# 
# 示例 1:
# 
# 输入: "(()"
# 输出: 2
# 解释: 最长有效括号子串为 "()"
# 
# 
# 示例 2:
# 
# 输入: ")()())"
# 输出: 4
# 解释: 最长有效括号子串为 "()()"
# 
# 
#

# @lc code=start
class Solution:
    """
    dp[i] 表示以下标 i 为字符结尾的最长有效字符串的长度

    状态转移方程
    以 ( 结尾的子字符串不考虑，因为不可能构成合法括号

    if s[i] == ')'
    s[i - 1] == '('，也就是字符串形如 “……()”，我们可以推出：
    dp[i] = dp[i − 2] + 2。
    因为结束部分的 "()" 是一个有效子字符串，并且将之前有效子字符串的长度增加了 2.
    s[i - 1] == ')'，也就是字符串形如 “.......))”，我们可以推出：
    if s[i - dp[i - 1] - 1] == '('，dp[i] = dp[i − 1] + dp[i − dp[i − 1] − 2] + 2。
    因为如果倒数第二个 )是一个有效子字符串的一部分（记为subs），我们此时需要判断 subs 前面一个符号是不是 ( ，如果恰好是(，我们就用 subs 的长度(dp[i - 1)加上 2 去更新 dp[i]。除此以外，我们也会把子字符串 subs 前面的有效字符串的长度加上，也就是 dp[i − dp[i − 1] − 2].
    边界情况
    i - 2 有可能小于零越界了，这种情况下就是只有 () ，前面记为 0 就好了.
    i - dp[i - 1] - 1 和 i - dp[i - 1] - 2 都可能越界，越界了当成 0 来计算就可以了.

    """
    def longestValidParentheses(self, s: str) -> int:
        maxLen=0
        size=len(s)
        dp=[0]*size
        for i in range(1,size):
            if s[i]==')':
                if s[i-1]=='(':
                    dp[i]=(dp[i-2] if i>=2 else 0)+2
                elif i-dp[i-1]-1>=0 and s[i-dp[i-1]-1]=='(':
                    dp[i]=(dp[i-dp[i-1]-2] if i-dp[i-1]-2>=0 else 0)+dp[i-1]+2
            maxLen=max(maxLen,dp[i])
        return maxLen 
# @lc code=end

