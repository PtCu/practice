#include <bits/stdc++.h>
using namespace std;
#define l(x) x << 1 | 1
#define r(x) (x + 1) << 1
#define f(x) (x - 1) >> 1
const int maxn = 30;
struct Node
{
    int v;
    int l, r;
    Node()
    {
        v = -1;
        l = r = -1;
    }
} nodes[maxn];
vector<int> ans;
bool isComp(int root)
{
    queue<int> Q;
    Q.push(root);
    while (Q.front() != -1)
    {
        auto p = Q.front();
        ans.push_back(p);
        Q.pop();
        Q.push(nodes[p].l);
        Q.push(nodes[p].r);
    }
    while (!Q.empty())
    {
        if (Q.front() != -1)
            return false;
        Q.pop();
    }
    return true;
}
bool isRoot[maxn];
int main()
{
    int n;
    cin >> n;
    string a, b;
    int ia, ib;
    int root = 0;
    memset(isRoot, true, sizeof(isRoot));
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        nodes[i].v = 1;
        if (a[0] != '-')
        {
            ia = stoi(a);
            nodes[i].l = ia;
            isRoot[ia] = false;
        }
        if (b[0] != '-')
        {
            ib = stoi(b);
            nodes[i].r = ib;
            isRoot[ib] = false;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (isRoot[i])
        {
            root = i;
            break;
        }
    }
    if (isComp(root))
        cout << "YES " << ans.back();
    else
    {
        cout << "NO " << root;
    }
}