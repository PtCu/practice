#include <bits/stdc++.h>
using namespace std;
const int maxn = 15;
struct Node
{
    int l, r;
    int v;
    Node() { l = r = -1; }
};
Node nodes[maxn];
bool show[maxn];
int _root;
void reverse(int root)
{
    if (root == -1)
        return;
    swap(nodes[root].l, nodes[root].r);
    reverse(nodes[root].l);
    reverse(nodes[root].r);
}
vector<int> ans;
void inorder(int root)
{
    if (root == -1)
        return;
    inorder(nodes[root].l);
    ans.push_back(nodes[root].v);
    inorder(nodes[root].r);
}
void levelorder(int root)
{
    queue<int> Q;
    Q.push(root);
    while (!Q.empty())
    {
        int p = Q.front();
        Q.pop();
        if (p == _root)
            cout << nodes[p].v;
        else
            cout << " " << nodes[p].v;
        if (nodes[p].l != -1)
            Q.push(nodes[p].l);
        if (nodes[p].r != -1)
            Q.push(nodes[p].r);
    }
}

int main()
{
    int n;
    cin >> n;
    char a, b;
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        nodes[i].v = i;
        if (a >= '0' && a <= '9')
        {
            nodes[i].l = a - '0';
            show[a - '0'] = true;
        }

        if (b >= '0' && b <= '9')
        {
            nodes[i].r = b - '0';
            show[b - '0'] = true;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (!show[i])
        {
            _root = i;
            break;
        }
    }
    reverse(_root);
    levelorder(_root);
    cout << endl;
    inorder(_root);
    cout << ans[0];
    for (int i = 1; i < ans.size(); ++i)
    {
        cout << " " << ans[i];
    }
}