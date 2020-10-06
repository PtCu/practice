#include <bits/stdc++.h>
using namespace std;
typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild; /* 左右孩子指针 */
} BiTNode, *BiTree;

int getDepth(BiTree root)
{
    int l, r;
    if (root->lchild)
        l = getDepth(root->lchild);
    else
        l = 0;
    if (root->rchild)
        r = getDepth(root->rchild);
    else
        r = 0;
    if (l == 0 &&r == 0)
        return 1;
    int depth = l > r ? l+1 : r+1;
    return depth;
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    BiTree root = new BiTNode;
    root->data = 1;
    queue<BiTree> q;
    q.push(root);
    for (int i = 0; i < n; i++)
    {
        BiTree p = q.front();
        int l, r;
        cin >> l >> r;
        if (l != 0)
        {
            BiTree left = new BiTNode;
            left->data = l;
            p->lchild = left;
            q.push(left);
        }
        else
            p->lchild = NULL;

        if (r != 0)
        {
            BiTree right = new BiTNode;
            right->data = r;
            p->rchild = right;
            q.push(right);
        }
        else
            p->rchild = NULL;
        q.pop();
    }
    cout<<getDepth(root)+1;
    return 0;
}
