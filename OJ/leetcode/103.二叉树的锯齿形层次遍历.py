#
# @lc app=leetcode.cn id=103 lang=python3
#
# [103] 二叉树的锯齿形层次遍历
#
# https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/description/
#
# algorithms
# Medium (53.81%)
# Likes:    173
# Dislikes: 0
# Total Accepted:    41.9K
# Total Submissions: 77.5K
# Testcase Example:  '[3,9,20,null,null,15,7]'
#
# 给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
#
# 例如：
# 给定二叉树 [3,9,20,null,null,15,7],
#
# ⁠   3
# ⁠  / \
# ⁠ 9  20
# ⁠   /  \
# ⁠  15   7
#
#
# 返回锯齿形层次遍历如下：
#
# [
# ⁠ [3],
# ⁠ [20,9],
# ⁠ [15,7]
# ]
#
#
#

# @lc code=start
# Definition for a binary tree node.


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    #BFS遍历后反转即可
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        queue=[root]
        res=[]
        while queue:
            tmp=[]
            n=len(queue)
            for i in range(n):
                node=queue.pop(0)
                tmp.append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            res.append(tmp)
        for i in range(len(res)):
            if i%2!=0:
                res[i].reverse()
        return res
              

# @lc code=end

