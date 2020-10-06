#include<vector>
#include <utility>
#include <stack>
using namespace std;

typedef struct TreeNode
{
    int val;
    struct TreeNode *right,*left;
}TreeNode;

//更简单的非递归前序遍历
void preorderTraversalNew(TreeNode *root, vector<int> &path)
{
    stack< pair<TreeNode *, bool> > s;
    s.push(make_pair(root, false));
    bool visited;
    while(!s.empty())
    {
        root = s.top().first;
        visited = s.top().second;
        s.pop();
        if(root == NULL)
            continue;
        if(visited)
        {
            path.push_back(root->val);
        }
        else
        {
            s.push(make_pair(root->right, false));
            s.push(make_pair(root->left, false));
            s.push(make_pair(root, true));
        }
    }
}
//更简单的非递归中序遍历
void inorderTraversalNew(TreeNode *root, vector<int> &path)
{
    stack< pair<TreeNode *, bool> > s;
    s.push(make_pair(root, false));
    bool visited;
    while(!s.empty())
    {
        root = s.top().first;
        visited = s.top().second;
        s.pop();
        if(root == NULL)
            continue;
        if(visited)
        {
            path.push_back(root->val);
        }
        else
        {
            s.push(make_pair(root->right, false));
            s.push(make_pair(root, true));
            s.push(make_pair(root->left, false));
        }
    }
}
//更简单的非递归后序遍历
void postorderTraversalNew(TreeNode *root, vector<int> &path)
{
    stack< pair<TreeNode *, bool> > s;
    s.push(make_pair(root, false));
    bool visited;
    while(!s.empty())
    {
        root = s.top().first;
        visited = s.top().second;
        s.pop();
        if(root == NULL)
            continue;
        if(visited)
        {
            path.push_back(root->val);
        }
        else
        {
            s.push(make_pair(root, true));
            s.push(make_pair(root->right, false));
            s.push(make_pair(root->left, false));
        }
    }
}