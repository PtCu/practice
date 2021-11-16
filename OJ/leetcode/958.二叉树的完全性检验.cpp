/*
 * @lc app=leetcode.cn id=958 lang=cpp
 *
 * [958] 二叉树的完全性检验
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool isCompleteTree(TreeNode *root)
    {
        queue<TreeNode *> Q;
        if (!root)
            return true;
        Q.push(root);
        while (!Q.empty())
        {
            auto p = Q.front();
            Q.pop();
            if (p) //结点非空，将左右子树入队
            {
                Q.push(p->left);
                Q.push(p->right);
            }
            else //结点为空，检查其后是否有非空结点
            {
                while (!Q.empty())
                {
                    auto q = Q.front();
                    Q.pop();
                    if (q)
                        return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
