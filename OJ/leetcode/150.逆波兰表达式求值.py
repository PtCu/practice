#
# @lc app=leetcode.cn id=150 lang=python3
#
# [150] 逆波兰表达式求值
#
# https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/description/
#
# algorithms
# Medium (49.26%)
# Likes:    125
# Dislikes: 0
# Total Accepted:    34.4K
# Total Submissions: 69.1K
# Testcase Example:  '["2","1","+","3","*"]'
#
# 根据逆波兰表示法，求表达式的值。
#
# 有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
#
# 说明：
#
#
# 整数除法只保留整数部分。
# 给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
#
#
# 示例 1：
#
# 输入: ["2", "1", "+", "3", "*"]
# 输出: 9
# 解释: ((2 + 1) * 3) = 9
#
#
# 示例 2：
#
# 输入: ["4", "13", "5", "/", "+"]
# 输出: 6
# 解释: (4 + (13 / 5)) = 6
#
#
# 示例 3：
#
# 输入: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
# 输出: 22
# 解释:
# ⁠ ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
# = ((10 * (6 / (12 * -11))) + 17) + 5
# = ((10 * (6 / -132)) + 17) + 5
# = ((10 * 0) + 17) + 5
# = (0 + 17) + 5
# = 17 + 5
# = 22
#
#

# @lc code=start
from typing import List

class Solution:
    def calculate(self, a, b, i):
        a=int(a);b=int(b)
        if i == '*':
            return a*b
        elif i == '/':
            return a/b
        elif i == '-':
            return a-b
        elif i == '+':
            return a+b

    def isOperator(self, i):
        return i == '/' or i == '+' or i == '-' or i == '*'

    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for i in tokens:
            if not self.isOperator(i):
                stack.append(i)
            else:
                b = stack.pop()
                a = stack.pop()
                stack.append(self.calculate(a,b,i))

        ans=int(stack.pop())
        return ans
# @lc code=end
if __name__ == "__main__":
    Solution().evalRPN(["4","13","5","/","+"])