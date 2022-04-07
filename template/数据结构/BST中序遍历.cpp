

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 *
 * @param proot TreeNode类
 * @param k int整型
 * @return int整型
 */
void goAlongVine(stack<TreeNode *> &S, TreeNode *node)
{
    while (node)
    {
        S.push(node);
        node = node->left;
    }
}
int KthNode(TreeNode *proot, int k)
{
    // write code here
    if (!proot)
        return -1;
    stack<TreeNode *> S;
    TreeNode *p = proot;
    int ans = -1;
    while (true)
    {
        goAlongVine(S, p);
        if (S.empty())
            break;
        p = S.top();
        S.pop();
        if (--k == 0)
        {
            ans = p->val;
            break;
        }
        p = p->right;
    }
    return ans;
}

int main()
{
    TreeNode *p1 = new TreeNode(5);
    p1->left = new TreeNode(3);
    p1->left->left = new TreeNode(2);
    p1->left->right = new TreeNode(4);
    p1->right = new TreeNode(7);
    p1->right->left = new TreeNode(6);
    p1->right->right = new TreeNode(8);
    int ans = KthNode(p1, 3);
}