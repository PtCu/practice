#include <bits/stdc++.h>
using namespace std;
vector<int> nodes;
struct Node
{
    struct Node *l, *r;
    int v;
};
Node *root_;
bool isBST(int begin, int end)
{
    if (begin >= end)
    {
        return true;
    }
    int root = nodes[begin];
    int left_s = begin + 1, left_e = left_s;
    for (int i = left_s; i <= end; ++i)
    {
        if (nodes[i] < root)
        {
            left_e++;
        }
        else
        {

            break;
        }
    }
    left_e--;
    int right_s = left_e + 1, right_e = right_s;
    for (int i = right_s; i <= end; ++i)
    {
        if (nodes[i] >= root)
        {
            right_e++;
        }
        else
        {
            return false;
        }
    }
    right_e--;
    return isBST(left_s, left_e) && isBST(right_s, right_e);
}
bool isMirror(int begin, int end)
{
    if (begin >= end)
    {
        return true;
    }
    int root = nodes[begin];
    int left_s = begin + 1, left_e = left_s;
    for (int i = left_s; i <= end; ++i)
    {
        if (nodes[i] >= root)
        {
            left_e++;
        }
        else
        {

            break;
        }
    }
    left_e--;
    int right_s = left_e + 1, right_e = right_s;
    for (int i = right_s; i <= end; ++i)
    {
        if (nodes[i] < root)
        {
            right_e++;
        }
        else
        {
            return false;
        }
    }
    right_e--;
    return isMirror(left_s, left_e) && isMirror(right_s, right_e);
}
Node *buildBST(int begin, int end)
{
    if (begin > end)
    {
        return NULL;
    }
    if (begin == end)
    {
        int root = nodes[begin];
        Node *_root = new Node;
        _root->v = root;
        _root->l = _root->r = NULL;
        return _root;
    }
    int root = nodes[begin];
    Node *_root = new Node;
    _root->v = root;
    int left_s = begin + 1, left_e = left_s;
    for (int i = left_s; i <= end; ++i)
    {
        if (nodes[i] < root)
        {
            left_e++;
        }
        else
        {
            break;
        }
    }
    left_e--;
    int right_s = left_e + 1, right_e = right_s;
    for (int i = right_s; i <= end; ++i)
    {
        if (nodes[i] >= root)
        {
            right_e++;
        }
    }
    right_e--;
    _root->l = buildBST(left_s, left_e);
    _root->r = buildBST(right_s, right_e);
    return _root;
}
Node *buildMirror(int begin, int end)
{
    if (begin > end)
    {
        return NULL;
    }
    if (begin == end)
    {
        int root = nodes[begin];
        Node *_root = new Node;
        _root->v = root;
        _root->l = _root->r = NULL;
        return _root;
    }
    int root = nodes[begin];
    Node *_root = new Node;
    _root->v = root;
    int left_s = begin + 1, left_e = left_s;
    for (int i = left_s; i <= end; ++i)
    {
        if (nodes[i] >= root)
        {
            left_e++;
        }
        else
        {

            break;
        }
    }
    left_e--;
    int right_s = left_e + 1, right_e = right_s;
    for (int i = right_s; i <= end; ++i)
    {
        if (nodes[i] < root)
        {
            right_e++;
        }
    }
    right_e--;
    _root->l = buildMirror(left_s, left_e);
    _root->r = buildMirror(right_s, right_e);
    return _root;
}
void postTrav(Node *root)
{
    if (!root)
        return;
    postTrav(root->l);
    postTrav(root->r);
    if (root == root_)
    {
        cout << root->v;
    }
    else
        cout << root->v << " ";
}
int main()
{
    int n;
    cin >> n;
    nodes.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nodes[i];
    }

    if (isBST(0, n - 1))
    {
        cout << "YES" << endl;
        root_ = buildBST(0, n - 1);
        postTrav(root_);
    }
    else if (isMirror(0, n - 1))
    {
        cout << "YES" << endl;
        root_ = buildMirror(0, n - 1);
        postTrav(root_);
    }
    else
    {
        cout << "NO" << endl;
    }
}