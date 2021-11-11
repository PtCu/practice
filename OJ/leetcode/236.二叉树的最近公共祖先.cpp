/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    // TreeNode *ans;
    // bool traverse(TreeNode *root, TreeNode *p, TreeNode *q)
    // {
    //     if (!root)
    //         return false;
    //     bool left = traverse(root->left, p, q);
    //     bool right = traverse(root->right, p, q);
    //     if (left && right || ((root->val == p->val) || (root->val == q->val)) && (left || right))
    //         ans = root;
    //     return left || right || (root->val == p->val || root->val == q->val);
    // }
    //检查p,q是否存在于root为根节点的树中，如果是则返回公共祖先
    TreeNode *test(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return NULL;
        if (root == p || root == q)
            return root;
        //看p,q是否存在于左子树
        TreeNode *left_exist = test(root->left, p, q);
        //看p,q是否存在于右子树
        TreeNode *right_exist = test(root->right, p, q);
        if (!right_exist)
            return left_exist;
        if (!left_exist)
            return right_exist;
        if (right_exist && left_exist)
            return root;
        return NULL;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        return test(root, p, q);
    }
};
// @lc code=end
