#include <bits/stdc++.h>
using namespace std;
const int maxn = 120;
struct node
{
    int layer;
    vector<int> child;
} tree[maxn];
int num_count[maxn];
unordered_map<int, int> leaf;
int layer;
void bfs()
{
    queue<node> Q;
    Q.push(tree[1]);
    while (!Q.empty())
    {
        node p = Q.front();
        Q.pop();
        layer = max(layer, p.layer);
        if (p.child.size() == 0)
        {
            leaf[p.layer]++;
        }
        for (int i = 0; i < p.child.size(); ++i)
        {
            tree[p.child[i]].layer = p.layer + 1;
            Q.push(tree[p.child[i]]);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    int f, son, k;
    for (int i = 0; i < m; ++i)
    {
        cin >> f >> k;
        for (int j = 0; j < k; ++j)
        {
            cin >> son;
            tree[f].child.push_back(son);
        }
    }
    tree[1].layer = 1;
    bfs();
    if (leaf.count(1))
        cout << leaf[1];
    else
        cout << 0;
    for (int i = 2; i <= layer; ++i)
    {
        if (leaf.count(i))
            cout << " " << leaf[i];
        else
            cout << " " << 0;
    }
}