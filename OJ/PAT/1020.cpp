#include <bits/stdc++.h>
using namespace std;
const int maxn = 40;
int in[maxn], post[maxn];
struct Node
{
    struct Node *l, *r;
    int x;
};
Node *solve(int in_start, int in_end, int post_start, int post_end)
{
    if (in_start > in_end || post_start > post_end)
        return NULL;
    int root = post[post_end];
    Node *node = new Node;
    node->x = root;
    int l_in_start, l_in_end, r_in_start, r_in_end;
    int l_post_start, l_post_end, r_post_start, r_post_end;
    //先在中序序列找左右子树
    l_in_start = in_start;
    for (l_in_end = in_start; l_in_end <= in_end; ++l_in_end)
    {
        if (in[l_in_end] == root)
        {
            break;
        }
    }
    r_in_start = l_in_end + 1;
    l_in_end--;
    r_in_end = in_end;

    l_post_start = post_start;
    l_post_end = l_in_end - l_in_start + l_post_start;
    r_post_start = l_post_end + 1;
    r_post_end = post_end - 1;

    node->l = solve(l_in_start, l_in_end, l_post_start, l_post_end);
    node->r = solve(r_in_start, r_in_end, r_post_start, r_post_end);
    return node;
}
void bfs(Node *root)
{
    queue<Node *> Q;
    Q.push(root);
    cout << root->x;
    while (!Q.empty())
    {
        Node *p = Q.front();
        if(p!=root)
        cout << " " << p->x;
        Q.pop();
        if (p->l != nullptr)
        {
            Q.push(p->l);
        }
        if (p->r != nullptr)
        {
            Q.push(p->r);
        }
    }
}
int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> post[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> in[i];
    }
    Node *root = solve(0, n - 1, 0, n - 1);
    bfs(root);
    return 0;
}