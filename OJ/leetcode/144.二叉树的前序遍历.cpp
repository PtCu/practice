/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    void visitAlongLeft(stack<TreeNode *> &S, TreeNode *p, vector<int> &ans)
    {
        while (p)
        {
            ans.push_back(p->val);
            S.push(p);
            p = p->left;
        }
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        TreeNode *p = root;
        stack<TreeNode *> S;
        while (true)
        {
            visitAlongLeft(S, p, ans);
            if (S.empty())
                break;
            p = S.top()->right;
            S.pop();
        }
        return ans;
    }
};
// @lc code=end
