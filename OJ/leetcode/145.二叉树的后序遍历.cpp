// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem145.h"
#include <bits/stdc++.h>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */
// #include <bits/stdc++.h>
// using namespace std;
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
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

    void visitAlongLeft(stack<TreeNode *> &S, TreeNode *p, vector<int> &res)
    {
        while (p)
        {
            res.push_back(p->val);
            S.push(p->left);
            p = p->right;
        }
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> S;
        vector<int> ans;
        TreeNode *p = root;
        while (true)
        {
            visitAlongLeft(S, p, ans);
            if (S.empty())
                break;
            p = S.top();
            S.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end
