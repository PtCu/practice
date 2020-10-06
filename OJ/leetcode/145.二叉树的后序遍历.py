#
# @lc app=leetcode.cn id=145 lang=python3
#
# [145] 二叉树的后序遍历
#
# https://leetcode-cn.com/problems/binary-tree-postorder-traversal/description/
#
# algorithms
# Hard (70.44%)
# Likes:    273
# Dislikes: 0
# Total Accepted:    67.3K
# Total Submissions: 94.8K
# Testcase Example:  '[1,null,2,3]'
#
# 给定一个二叉树，返回它的 后序 遍历。
# 
# 示例:
# 
# 输入: [1,null,2,3]  
# ⁠  1
# ⁠   \
# ⁠    2
# ⁠   /
# ⁠  3 
# 
# 输出: [3,2,1]
# 
# 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
# 
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
 
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        # ans=[]
        # def helper(root):
        #     if not root:
        #         return
        #     helper(root.left)
        #     helper(root.right)
        #     ans.append(root.val)
        # helper(root)
        # return ans

        #迭代版
        #后序遍历结果为从左到右，从下到上。  利用栈可以达到相反的顺序，然后再反转即可
        if not root:
            return []
        stack=[root]
        ans=[]
        while stack:
            node=stack.pop()
            ans.append(node.val)
            if node.left:
                stack.append(node.left)
            if node.right:
                stack.append(node.right)
        return ans[::-1]
# @lc code=end

