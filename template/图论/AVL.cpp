//PAT 1123
#include <bits/stdc++.h>
using namespace std;
#define FromParentTo(x) (x == _root ? _root : (x->parent->l == x) ? (x->parent->l) \
                                                                  : (x->parent->r))

struct Node
{
    Node *l, *r, *parent;
    int height;
    int v;
    Node() {}
    Node(int x) : l(NULL), r(NULL), parent(NULL), height(1), v(x) {}
    Node(int x, Node *f) : l(NULL), r(NULL), parent(f), height(1), v(x) {}
};
Node *_root;
int n;
int getHeight(Node *x)
{
    if (x == NULL)
        return 0;
    return x->height;
}
void updateHeight(Node *x)
{
    x->height = max(getHeight(x->l), getHeight(x->r)) + 1;
}
int getBalance(Node *x)
{
    return getHeight(x->l) - getHeight(x->r);
}

Node *connect34(Node *a, Node *b, Node *c, Node *t1, Node *t2, Node *t3, Node *t4)
{
    a->l = t1;
    if (t1)
        t1->parent = a;
    a->r = t2;
    if (t2)
        t2->parent = a;
    //修改完便更新
    updateHeight(a);
    c->l = t3;
    if (t3)
        t3->parent = c;
    c->r = t4;
    if (t4)
        t4->parent = c;
    //修改完便更新
    updateHeight(c);
    b->l = a;
    b->r = c;
    a->parent = b;
    c->parent = b;
    updateHeight(b);
    return b;
}
//根据zig-zag情况而调用connect34
Node *rotateAt(Node *root)
{
    Node *tmp = root->parent;
    Node *new_root;
    if (getHeight(root->l) > getHeight(root->r))
    {
        Node *lc = root->l;
        if (getHeight(lc->l) > getHeight(lc->r))
        {
            new_root = connect34(lc->l, lc, root, lc->l->l, lc->l->r, lc->r, root->r);
        }
        else
        {
            new_root = connect34(lc, lc->r, root, lc->l, lc->r->l, lc->r->r, root->r);
        }
    }
    else
    {
        Node *rc = root->r;
        if (getHeight(rc->l) > getHeight(rc->r))
        {
            new_root = connect34(root, rc->l, rc, root->l, rc->l->l, rc->l->r, rc->r);
        }
        else
        {
            new_root = connect34(root, rc, rc->r, root->l, rc->l, rc->r->l, rc->r->r);
        }
    }
    new_root->parent = tmp;
    return new_root;
}

void insert(int x)
{
    if (_root == NULL)
    {
        _root = new Node(x);
        return;
    }
    Node *p, *f;
    p = f = _root;
    while (p)
    {
        f = p;
        if (p->v < x)
            p = p->r;
        else
            p = p->l;
    }
    p = new Node(x, f);
    if (f->v > x)
        f->l = p;
    else
        f->r = p;
    while (p)
    {
        updateHeight(p);
        int balance = getBalance(p);
        if (balance >= 2 || balance <= -2)
        {
            //p=FromParentTo(p)=rotateAt(p);
            if (p == _root)
            {
                _root = rotateAt(p);
                p = _root;
            }
            else if (p->parent->l == p)
            {
                p->parent->l = rotateAt(p);
            }
            else
            {
                p->parent->r = rotateAt(p);
            }
        }
        p = p->parent;
    }
}
bool isComp()
{
    queue<Node *> Q;
    Q.push(_root);

    while (Q.front() != NULL)
    {
        auto p = Q.front();
        Q.pop();
        Q.push(p->l);
        Q.push(p->r);
    }
    while (!Q.empty())
    {
        if (Q.front() != NULL)
            return false;
        Q.pop();
    }
    return true;
}
void level()
{
    vector<int> ans;
    queue<Node *> Q;
    Q.push(_root);
    while (!Q.empty())
    {
        auto p = Q.front();
        Q.pop();
        ans.push_back(p->v);
        if (p->l)
            Q.push(p->l);
        if (p->r)
            Q.push(p->r);
    }
    cout << ans[0];
    for (int i = 1; i < ans.size(); ++i)
    {
        cout << " " << ans[i];
    }
}
int main()
{

    cin >> n;
    int x;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        insert(x);
    }

    level();
    cout << endl;
    if (isComp())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}