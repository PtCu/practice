#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *l, *r;
    Node *father;
    int v;
    int height;
    Node() {}
    Node(int x) : l(NULL), r(NULL), father(NULL), v(x), height(1) {}
    Node(int x, Node *p) : l(NULL), r(NULL), father(p), v(x), height(1) {}
};
Node *_root = NULL;
int getHeight(Node *x)
{
    if (x == NULL)
        return 0;
    return x->height;
}
void updateHeight(Node *root)
{
    root->height = max(getHeight(root->l), getHeight(root->r)) + 1;
}
void insert(int x)
{
    Node *p = _root;
    Node *f = p;
    while (p)
    {
        f = p;
        if (x < p->v)
            p = p->r;
        else
            p = p->l;
    }
    p = new Node(x, f);
    while (p)
    {
        updateHeight(p);
        p = p->father;
    }
}
int main()
{
    int n;
    cin >> n;
    int x;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        insert(x);
    }
    return 0;
}
