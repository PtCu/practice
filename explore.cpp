#include <bits/stdc++.h>

using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *dfs(const vector<int> &pre, const vector<int> &vin, int pre_start, int pre_end, int vin_start, int vin_end)
{
    if (pre_start > pre_end || vin_start > vin_end)
        return nullptr;
    TreeNode *root = new TreeNode(pre[pre_start]);
    int left_pre_start = pre_start + 1;
    int left_len = 0;
    while (vin[vin_start + left_len] != root->val)
    {
        left_len++;
    }
    int left_pre_end = left_pre_start + left_len - 1;
    int right_pre_start = left_pre_start + left_len;
    int right_len = pre_end - pre_start - left_len;
    int right_pre_end = right_pre_start + right_len - 1;
    int left_vin_start = vin_start;
    int left_vin_end = left_vin_start + left_len - 1;
    int right_vin_start = left_vin_end + 2;
    int right_vin_end = right_vin_start + right_len - 1;

    root->left = dfs(pre, vin, left_pre_start, left_pre_end, left_vin_start, left_vin_end);
    root->right = dfs(pre, vin, right_pre_start, right_pre_end, right_vin_start, right_vin_end);

    return root;
}

TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin)
{
    return dfs(pre, vin, 0, pre.size() - 1, 0, vin.size() - 1);
}

vector<int> pre{1, 2, 4, 7, 3, 5, 6, 8};

vector<int> vin{4, 7, 2, 1, 5, 3, 8, 6};

void dfs(TreeNode *p, bool should_add, int &sum)
{
    if (!p)
        return;
    if (should_add)
        sum += p->val;
    if (p->right)
    {
        dfs(p->right, true, sum);
    }
    dfs(p->left, false, sum);
}
int main()
{
    // reConstructBinaryTree(pre, vin);
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    int ans = 0;
    dfs(root, false, ans);
    cout << ans;
}
