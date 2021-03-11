#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *l, *r;
    Node *father;
    int v;
    int height;
    int level;
    Node() {}
    Node(int x) : l(NULL), r(NULL), father(NULL), v(x), height(1), level(1) {}
    Node(int x, Node *p) : l(NULL), r(NULL), father(p), v(x), height(1)
    {
        if (p == NULL)
            level = 1;
        else
            level = p->level + 1;
    }
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
int max_level = 0;
void insert(int x)
{
    if (_root == NULL)
    {
        _root = new Node(x);
        max_level = 1;
        return;
    }
    Node *p = _root;
    Node *f = p;
    while (p)
    {
        f = p;
        if (x > p->v)
            p = p->r;
        else
            p = p->l;
    }
    p = new Node(x, f);
    if (f->v >= x)
        f->l = p;
    else
        f->r = p;
    max_level = max(max_level, p->level);
    // while (p)
    // {
    //     updateHeight(p);
    //     p = p->father;
    // }
}
void bfs()
{
    queue<Node *> Q;
    Q.push(_root);
    int n1 = 0;
    int n2 = 0;
    while (!Q.empty())
    {
        auto p = Q.front();
        Q.pop();
        if (p->level == max_level)
            n1++;
        else if (p->level == max_level - 1)
            n2++;
        if (p->l)
            Q.push(p->l);
        if (p->r)
            Q.push(p->r);
    }
    cout << n1 << " + " << n2 << " = " << n1 + n2;
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
    bfs();
    return 0;
}
