#include <bits/stdc++.h>
// Definition for a TreeNode.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/** \brief      creatList  数组建树
 *  \param[in] s 输入数组
 *  \param[in] i 必须为0
 *  \return      返回树的根节点
 */
TreeNode* creatTree(std::vector<int> nums, int i){
    if(i >= nums.size() || nums[i] == -1)               /**<出现无效下标 或者值为1均返回nullptr */
        return nullptr;

    TreeNode *root = new TreeNode(nums[i]);             /**<创建根节点 */
    root->left = creatTree(nums, 2*i+1);                /**<创建左子树 */
    root->right = creatTree(nums, 2*i+2);               /**<创建右子树 */

    return root;
}

/** \brief      freeTree  释放内存
 *  \param[in] root 输入二叉树根节点
 *  \return         void
 */
void freeTree(TreeNode* root) {
    if(root == nullptr)
        return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}
