//PAT1127
#include <bits/stdc++.h>
using namespace std;
vector<int> in, pos;
int n;
struct Node
{
    Node *l, *r;
    int v;
};
Node *build(int in_s, int in_e, int pos_s, int pos_e)
{
    if (in_s > in_e || pos_s > pos_e)
        return NULL;

    int in_l_s, in_l_e, in_r_s, in_r_e, pos_l_s, pos_l_e, pos_r_s, pos_r_e;
    Node *root = new Node;
    root->v = pos[pos_e];
    if (in_s == in_e)
    {
        root->l = NULL;
        root->r = NULL;
        return root;
    }
    for (in_l_s = in_l_e = in_s, pos_l_s = pos_l_e = pos_s; in[in_l_e] != root->v; ++in_l_e)
        ;
    --in_l_e;
    pos_l_e += in_l_e - in_l_s;

    pos_r_s = pos_l_e + 1;
    pos_r_e = pos_e - 1;
    in_r_s = in_l_e + 2;
    in_r_e = in_e;
    root->l = build(in_l_s, in_l_e, pos_l_s, pos_l_e);
    root->r = build(in_r_s, in_r_e, pos_r_s, pos_r_e);
    return root;
}
void zigzag(Node *root)
{
    queue<Node *> Q;
    Q.push(root);
    vector<int> ans;
    deque<Node *> deq;
    bool isL2R = false;
    while (!Q.empty())
    {
        int n = Q.size();
        for (int i = 0; i < n; ++i)
        {
            auto p = Q.front();
            Q.pop();
            if (isL2R)
            {
                deq.push_back(p);
            }
            else
            {
                deq.push_front(p);
            }
            if (p->l)
                Q.push(p->l);
            if (p->r)
                Q.push(p->r);
        }
        for (auto node : deq)
        {
            ans.push_back(node->v);
        }
        deq.clear();
        isL2R = !isL2R;
    }
    cout << ans[0];
    for (int i = 1; i < ans.size(); ++i)
    {
        cout << " " << ans[i];
    }
}
int main()
{
    int x;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        in.push_back(x);
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        pos.push_back(x);
    }
    auto root = build(0, n - 1, 0, n - 1);
    zigzag(root);

    return 0;
}