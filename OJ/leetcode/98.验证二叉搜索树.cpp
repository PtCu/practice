/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    bool isValid(TreeNode *r, long lower, long upper)
    {
        if (!r)
            return true;
        if (r->val <= lower || r->val >= upper)
            return false;
        return isValid(r->left, lower, r->val) && isValid(r->right, r->val, upper);
    }

    bool traverse(TreeNode *r, long &min_v, long &max_v)
    {
        if (!r)
            return true;
        if (r->val < min_v)
            min_v = r->val;
        if (r->val > max_v)
            max_v = r->val;
        long left_min = LONG_MAX, right_min = LONG_MAX;
        long left_max = LONG_MIN, right_max = LONG_MIN;

        if (!traverse(r->left, left_min, left_max) || !traverse(r->right, right_min, right_max))
            return false;

        if (left_max >= r->val || right_min <= r->val)
        {
            return false;
        }

        min_v = min(left_min, min_v);
        max_v = max(right_max, max_v);
        return true;
    }
    void goAlongVine(stack<TreeNode *>& S, TreeNode *r)
    {
        while (r)
        {
            S.push(r);
            r = r->left;
        }
    }
    //只要看它中序遍历的结果是不是递增的就可以了。
    //我们用pre指针记录前一个节点，如果当前节点小于等于前一个节点，就返回false
    bool traverse2(TreeNode *r)
    {
        stack<TreeNode *> S;
        TreeNode *p = r;
        long pre = LONG_MIN;
        while (true)
        {
            goAlongVine(S, p);
            if (S.empty())
                break;
            p = S.top();
            if (p->val <= pre)
                return false;
            pre = p->val;
            p = p->right;
            S.pop();
        }
        return true;
    }
    bool isValidBST(TreeNode *root)
    {
        // long min_v = LONG_MIN;
        // long max_v = LONG_MAX;
        // return traverse(root, min_v, max_v);
        // return isValid(root, min_v, max_v);
        return traverse2(root);
    }
};
// @lc code=end
