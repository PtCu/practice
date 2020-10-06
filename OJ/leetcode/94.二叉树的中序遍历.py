#
# @lc app=leetcode.cn id=94 lang=python3
#
# [94] 二叉树的中序遍历
#
# https://leetcode-cn.com/problems/binary-tree-inorder-traversal/description/
#
# algorithms
# Medium (70.44%)
# Likes:    459
# Dislikes: 0
# Total Accepted:    137K
# Total Submissions: 193.1K
# Testcase Example:  '[1,null,2,3]'
#
# 给定一个二叉树，返回它的中序 遍历。
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
# 输出: [1,3,2]
#
# 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
#
#
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
# @lc code=start
# Definition for a binary tree node.





class Solution:
    

    def inorderTraversal(self, root: TreeNode) -> List[int]:
        # ans=[]
        # def helper(root):
        #     if root:
        #         helper(root.left)
        #         ans.append(root.val)
        #         helper(root.right)
        # helper(root)
        # return ans
        res = []
        stack = []
        # 用p当做指针
        p = root
        while p or stack:
            # 把左子树压入栈中
            if p:
                stack.append(p)
                p = p.left
                # 输出 栈顶元素
            else:
                p = stack.pop()
                res.append(p.val)
                # 看右子树
                p = p.right
        return res

# @lc code=end

