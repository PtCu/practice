#
# @lc app=leetcode.cn id=20 lang=python3
#
# [20] 有效的括号
#
# https://leetcode-cn.com/problems/valid-parentheses/description/
#
# algorithms
# Easy (41.05%)
# Likes:    1504
# Dislikes: 0
# Total Accepted:    249.8K
# Total Submissions: 604.1K
# Testcase Example:  '"()"'
#
# 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
# 
# 有效字符串需满足：
# 
# 
# 左括号必须用相同类型的右括号闭合。
# 左括号必须以正确的顺序闭合。
# 
# 
# 注意空字符串可被认为是有效字符串。
# 
# 示例 1:
# 
# 输入: "()"
# 输出: true
# 
# 
# 示例 2:
# 
# 输入: "()[]{}"
# 输出: true
# 
# 
# 示例 3:
# 
# 输入: "(]"
# 输出: false
# 
# 
# 示例 4:
# 
# 输入: "([)]"
# 输出: false
# 
# 
# 示例 5:
# 
# 输入: "{[]}"
# 输出: true
# 
#

# @lc code=start
class Solution:
    def isValid(self, s: str) -> bool:
        stack=[]
        for i in s:
            if i=='(' or i=='[' or i== '{':
                stack.append(i)
            else:
                if len(stack)==0:
                    return False
                tmp=stack.pop()
                if tmp=='(' and i!=')' or tmp=='{' and i!='}' or tmp=='[' and i!=']':
                    return False
        if len(stack)==0:
            return True
        else:
            return False
if __name__ == "__main__":
    Solution().isValid('(]')
# @lc code=end

