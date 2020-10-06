#
# @lc app=leetcode.cn id=44 lang=python3
#
# [44] 通配符匹配
#
# https://leetcode-cn.com/problems/wildcard-matching/description/
#
# algorithms
# Hard (26.77%)
# Likes:    295
# Dislikes: 0
# Total Accepted:    23.7K
# Total Submissions: 87.4K
# Testcase Example:  '"aa"\n"a"'
#
# 给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。
# 
# '?' 可以匹配任何单个字符。
# '*' 可以匹配任意字符串（包括空字符串）。
# 
# 
# 两个字符串完全匹配才算匹配成功。
# 
# 说明:
# 
# 
# s 可能为空，且只包含从 a-z 的小写字母。
# p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。
# 
# 
# 示例 1:
# 
# 输入:
# s = "aa"
# p = "a"
# 输出: false
# 解释: "a" 无法匹配 "aa" 整个字符串。
# 
# 示例 2:
# 
# 输入:
# s = "aa"
# p = "*"
# 输出: true
# 解释: '*' 可以匹配任意字符串。
# 
# 
# 示例 3:
# 
# 输入:
# s = "cb"
# p = "?a"
# 输出: false
# 解释: '?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
# 
# 
# 示例 4:
# 
# 输入:
# s = "adceb"
# p = "*a*b"
# 输出: true
# 解释: 第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".
# 
# 
# 示例 5:
# 
# 输入:
# s = "acdcb"
# p = "a*c?b"
# 输入: false
# 
#

# @lc code=start
#https://leetcode-cn.com/problems/wildcard-matching/solution/dong-tai-gui-hua-dai-zhu-shi-by-tangweiqun/
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        s_len=len(s)
        p_len=len(p)
        dp=[[False]*(p_len+1) for i in range(s_len+1)]
        dp[0][0]=True
        #初始化。s为空时，如果p为*则为true
        for i in range(1,p_len+1):
            dp[0][i]=dp[0][i-1] and p[i-1]=='*'
        #网格从1开始，所以字符串索引要减一
        for i in range(1,s_len+1):
            for j in range(1,p_len+1):
                if p[j-1]=='?' or p[j-1]==s[i-1]:
                    dp[i][j]=dp[i-1][j-1]
                elif p[j-1]=='*':
                    dp[i][j]=dp[i-1][j] or dp[i][j-1]   #dp[i][j - 1] 表示 * 代表的是空字符，例如 ab, ab*
                                                        #dp[i - 1][j] 表示 * 代表的是非空字符，例如 abcd, ab*

        return dp[s_len][p_len]


# @lc code=end

