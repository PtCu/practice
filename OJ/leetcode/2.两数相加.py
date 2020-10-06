#
# @lc app=leetcode.cn id=2 lang=python3
#
# [2] 两数相加
#
# https://leetcode-cn.com/problems/add-two-numbers/description/
#
# algorithms
# Medium (36.82%)
# Likes:    4007
# Dislikes: 0
# Total Accepted:    346.9K
# Total Submissions: 942.1K
# Testcase Example:  '[2,4,3]\n[5,6,4]'
#
# 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
# 
# 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
# 
# 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
# 
# 示例：
# 
# 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
# 输出：7 -> 0 -> 8
# 原因：342 + 465 = 807
# 
# 
#

# @lc code=start
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        first=pre=ListNode(-1)
        carry=0
        #原理类似加法器
        while l1 or l2 or carry!=0:
            if l1 :
                carry+=l1.val
                l1=l1.next
            if l2 :
                carry+=l2.val
                l2=l2.next
            
            p=ListNode(0)
            p.val=carry%10
            carry=carry//10
            pre.next=p
            pre=p
        
        return first.next

if __name__ == "__main__":
    l1=now=ListNode(-1)
    for i in [2,4,3]:
        p=ListNode(i)
        now.next=p
        now=p
    l2=now=ListNode(-2)
    for i in [5,6,4]:
        p=ListNode(i)
        now.next=p
        now=p
    s=Solution().addTwoNumbers(l1.next,l2.next)
    while s:
        print(s.val)
        s=s.next
# @lc code=end

