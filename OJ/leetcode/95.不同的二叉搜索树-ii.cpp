/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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
    //生成从l到r的所有二叉树的集合。
    vector<TreeNode *> genTree(int l, int r)
    {

        vector<TreeNode *> ans;
        if (l > r)
            return {nullptr};

        //让节点i作为根节点
        for (int i = l; i <= r; ++i)
        {
            vector<TreeNode *> left, right;
            left = genTree(l, i - 1);
            right = genTree(i + 1, r);
            //从左右子树的集合中各取一个来作为左右子树
            for (auto &l : left)
            {
                for (auto &r : right)
                {
                    TreeNode *cur = new TreeNode(i);
                    cur->left = l;
                    cur->right = r;
                    ans.emplace_back(cur);
                }
            }
        }

        return ans;
    }
    vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
            return {};
        return genTree(1, n);
    }
};
// @lc code=end
