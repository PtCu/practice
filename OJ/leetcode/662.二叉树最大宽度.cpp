/*
 * @lc app=leetcode.cn id=662 lang=cpp
 *
 * [662] 二叉树最大宽度
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
    // int widthOfBinaryTree(TreeNode *root)
    // {
    //     if (!root)
    //         return 0;
    //     queue<TreeNode *> Q;
    //     int ans = 0;
    //     Q.push(root);
    //     while (!Q.empty())
    //     {
    //         int size = Q.size();
    //         ans = max(size, ans);
    //         while (size--)
    //         {
    //             auto p = Q.front();
    //             Q.pop();
    //             if (p->left)
    //                 Q.push(p->left);
    //             if (p->right)
    //                 Q.push(p->right);
    //         }
    //     }
    //     return ans;
    // }
    int widthOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;
        int ans = 0;
        queue<pair<TreeNode *, int>> Q;
        Q.push({root, 1});
        while (!Q.empty())
        {
            int Lest = INT_MAX, Rest = 0;
            int size = Q.size();
            int offset = Q.front().second;
            while (size--)
            {
                auto p = Q.front();
                Q.pop();
                TreeNode *pNode = p.first;
                int index = p.second;
                if (pNode->left)
                    Q.push({pNode->left, 2 * (index - offset)});
                if (pNode->right)
                    Q.push({pNode->right, 2 * (index - offset) + 1});
                Lest = min(Lest, index);
                Rest = max(Rest, index);
            }
            ans = max(ans, Rest - Lest + 1);
        }

        return ans;
    }
};
// @lc code=end
