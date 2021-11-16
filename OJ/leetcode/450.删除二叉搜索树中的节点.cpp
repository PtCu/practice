/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        //第一种情况，整个树没有找到值为key的节点
        if (root == NULL)
            return root;
        if (root->val == key)
        {
            //第二种情况，左右节点都为空，直接返回NULL
            //第三种情况，左节点为空，右节点不为空,将右节点作为根节点
            if (root->left == NULL)
                return root->right;
            //第四种情况，右节点为空，左节点不为空，将左节点作为根节点
            else if (root->right == NULL)
                return root->left;
            //第五种情况，左右节都不为空,要将目标节点的左孩子插入到目标节点右孩子最左下角的节点后，
            //作为它的左孩子,然后将root节点的右孩子作为右节点，删除root。
            else
            {
                TreeNode *cur = root->right;
                while (cur->left != NULL)
                {
                    cur = cur->left;
                }
                cur->left = root->left;
                TreeNode *node = root;
                root = root->right;
                delete node;
                return root;
            }
        }

        if (root->val > key)
            root->left = deleteNode(root->left, key);
        if (root->val < key)
            root->right = deleteNode(root->right, key);
        return root;
    }
};
// @lc code=end
