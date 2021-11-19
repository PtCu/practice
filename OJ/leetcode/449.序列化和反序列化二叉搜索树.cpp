// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem449.h"
#include <bits/stdc++.h>

// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=449 lang=cpp
 *
 * [449] 序列化和反序列化二叉搜索树
 */

using namespace std;
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    // void visitAlongLeft(TreeNode *p, stack<TreeNode *> &s, string &ans)
    // {
    //     while (p)
    //     {
    //         ans.push_back(p->val);
    //         s.push(p->right);
    //         p = p->left;
    //     }
    // }
    // // Encodes a tree to a single string.
    // string serialize(TreeNode *root)
    // {
    //     string ans;
    //     stack<TreeNode *> S;
    //     auto p = root;
    //     while (true)
    //     {
    //         visitAlongLeft(p, S, ans);
    //         if (S.empty())
    //             break;
    //         p = S.top(); //p可能为空，留给下一回合处理
    //         S.pop();
    //     }
    //     return ans;
    // }
    // //[start,end]
    // TreeNode *gen(string &data, int start, int end)
    // {
    //     if (start > end)
    //         return nullptr;
    //     TreeNode *root = new TreeNode(data[start]);
    //     int i = start + 1;
    //     for (; i <= end; ++i)
    //     {
    //         if (data[i] > data[start])
    //             break;
    //     }

    //     root->left = gen(data, start + 1, i - 1);
    //     root->right = gen(data, i, end);
    //     return root;
    // }
    // // Decodes your encoded data to tree.
    // TreeNode *deserialize(string data)
    // {
    //     return gen(data, 0, data.size() - 1);
    // }

    string serialize(TreeNode *root)
    {
        if (root == nullptr)
            return "#";
        return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
    }

  

    TreeNode *rebuildTree(stringstream &ss)
    {
        string tmp;
        ss >> tmp; //遇到空格自动停止
        if (tmp == "#")
            return nullptr;
        TreeNode *p = new TreeNode(stoi(tmp));
        p->left = rebuildTree(ss);
        p->right = rebuildTree(ss);
        return p;
    }


    TreeNode *deserialize(string data)
    {
        stringstream ss(data);
        return rebuildTree(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end
