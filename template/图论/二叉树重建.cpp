//PAT 1119
#include <bits/stdc++.h>
using namespace std;
const int maxn = 35;
vector<int> pre, pos;
struct Node
{
    Node *l, *r;
    int v;
};
int n;
Node *build(int pre_s, int pre_e, int pos_s, int pos_e)
{
    if (pre_s > pre_e || pos_s > pos_e)
        return NULL;
    Node *root = new Node;
    root->v = pre[pre_s];
    if (pre_s == pre_e)
    {
        root->l = NULL;
        root->r = NULL;
        return root;
    }

    int pre_l_s, pre_r_s, pre_l_e, pre_r_e, pos_l_s, pos_r_s, pos_l_e, pos_r_e;
    int count = 0;
    for (pre_l_s = pre_l_e = pre_s + 1, pos_l_s = pos_l_e = pos_s; pre[pre_l_s] != pos[pos_l_e] && pos_l_e < n; pos_l_e++)
        ;
    pre_l_e += pos_l_e - pos_l_s;

    for (pre_r_s = pre_r_e = pre_l_e + 1, pos_r_s = pos_r_e = pos_l_e + 1; pos[pos_r_e] != root->v && pos_r_e < n; ++pos_r_e)
        ;
    pos_r_e--;
    pre_r_e += pos_r_e - pos_r_s;
    root->l = build(pre_l_s, pre_l_e, pos_l_s, pos_l_e);
    root->r = build(pre_r_s, pre_r_e, pos_r_s, pos_r_e);
    return root;
}
vector<int> ans;
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->l);
    ans.push_back(root->v);
    inorder(root->r);
}
bool isValid(Node *root)
{
    queue<Node *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        auto p = Q.front();
        Q.pop();
        if ((!p->l || !p->r) && (p->l || p->r))
        {
            return false;
        }
        if (p->l)
            Q.push(p->l);
        if (p->r)
            Q.push(p->r);
    }
    return true;
}
int main()
{
    int x;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        pre.push_back(x);
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        pos.push_back(x);
    }
    Node *root = build(0, n - 1, 0, n - 1);
    if (isValid(root))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    inorder(root);
    cout << ans[0];
    for (int i = 1; i < ans.size(); ++i)
    {
        cout << " " << ans[i];
    }
    cout << endl;
    return 0;
}