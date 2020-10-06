#
# @lc app=leetcode.cn id=10 lang=python3
#
# [10] 正则表达式匹配
#
# https://leetcode-cn.com/problems/regular-expression-matching/description/
#
# algorithms
# Hard (26.41%)
# Likes:    1037
# Dislikes: 0
# Total Accepted:    62.6K
# Total Submissions: 232.7K
# Testcase Example:  '"aa"\n"a"'
#
# 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
# 
# '.' 匹配任意单个字符
# '*' 匹配零个或多个前面的那一个元素
# 
# 
# 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
# 
# 说明:
# 
# 
# s 可能为空，且只包含从 a-z 的小写字母。
# p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
# 
# 
# 示例 1:
# 
# 输入:
# s = "aa"
# p = "a"
# 输出: false
# 解释: "a" 无法匹配 "aa" 整个字符串。
# 
# 
# 示例 2:
# 
# 输入:
# s = "aa"
# p = "a*"
# 输出: true
# 解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
# 
# 
# 示例 3:
# 
# 输入:
# s = "ab"
# p = ".*"
# 输出: true
# 解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
# 
# 
# 示例 4:
# 
# 输入:
# s = "aab"
# p = "c*a*b"
# 输出: true
# 解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
# 
# 
# 示例 5:
# 
# 输入:
# s = "mississippi"
# p = "mis*is*p*."
# 输出: false
# 
#

# @lc code=start
class Solution:
    #dp[i][j] 表示 s 的前 ii 个是否能被 p 的前 jj 个匹配
    def isMatch(self, s: str, p: str) -> bool:
        """
        状态
        很容易想到，dp[i][j] 表示的状态是 s 的前 i 项和 p 的前 j 项是否匹配。

        转移方程
        现在如果已知了 dp[i-1][j-1] 的状态，我们该如何确定 dp[i][j] 的状态呢？我们可以分三种情况讨论，其中，前两种情况考虑了所有能匹配的情况，剩下的就是不能匹配的情况了：
        1、s[i] == p[j] or p[j] == '.'：比如 abb 和 abb，或者 abb 和 ab. ，很容易得到 dp[i][j] = dp[i-1][j-1] = True。因为 ab 和 ab 是匹配的，如果后面分别加一个 b，或者 s 加一个 b 而 p 加一个 . ，仍然是匹配的。
        2、p[j] == '*'：当 p[j] 为星号时，由于星号与前面的字符相关，因此我们比较星号前面的字符 p[j-1] 和 s[i] 的关系。根据星号前面的字符与 s[i] 是否相等，又可分为以下两种情况：
            2.1、p[j-1] != s[i]：如果星号前一个字符匹配不上，星号匹配了 0 次，应忽略这两个字符，看 p[j-2] 和 s[i] 是否匹配。 这时 dp[i][j] = dp[i][j-2]。
            2.2、p[j-1] == s[i] or p[j-1] == '.':星号前面的字符可以与 s[i] 匹配，这种情况下，星号可能匹配了前面的字符的 0 个，也可能匹配了前面字符的多个，当匹配 0 个时，如 ab 和 abb*，或者 ab 和 ab.* ，这时我们需要去掉 p 中的 b* 或 .* 后进行比较，即 dp[i][j] = dp[i][j-2]；当匹配多个时，如 abbb 和 ab*，或者 abbb 和 a.*，我们需要将 s[i] 前面的与 p 重新比较，即 dp[i][j] = dp[i-1][j]
        3、其他情况：以上两种情况把能匹配的都考虑全面了，所以其他情况为不匹配，即 dp[i][j] = False

        """
        if not p: return not s
        if not s and len(p) == 1: return False 

        nrow = len(s) + 1   
        ncol = len(p) + 1

        dp = [[False for c in range(ncol)] for r in range(nrow)]
        #初始状态    
        dp[0][0] = True
        dp[0][1] = False
        #单独对第一行处理
        for c in range(2, ncol):
            j = c-1
            if p[j] == '*': dp[0][c] = dp[0][c-2]
            
        for r in range(1, nrow):
            i = r-1
            for c in range(1, ncol):
                j = c-1
                #如果匹配则有  dp[r][c] = dp[r-1][c-1]
                if s[i] == p[j] or p[j] == '.':
                    dp[r][c] = dp[r-1][c-1]
                    #如果p[j]为*，则分类讨论
                elif p[j] == '*':
                    if p[j-1] == s[i] or p[j-1] == '.':
                        dp[r][c] = dp[r-1][c] or dp[r][c-2]

                    #如果*前面的不匹配，比如(ab, abc * )。遇到 * 往前看两个，发现前面 s[i] 的 ab 对 p[j-2] 的 ab 能匹配，虽然后面是 c*，但是可以看做匹配 00 次 c，相当于直接去掉 c *，所以也是 True
                    else:
                        dp[r][c] = dp[r][c-2]
                else:
                    dp[r][c] = False

        return dp[nrow-1][ncol-1]
        # @lc code=end

       
