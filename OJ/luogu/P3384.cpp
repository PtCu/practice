#include <bits/stdc++.h>
using namespace std;
typedef struct
{
    int depth, father;
} node;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int depth = 1;
    vector<node> tree(n + 1);
    vector<int> width(n, 0); //记录每层宽度
    tree[1].depth = 1;
    width[1] = 1;
    for (int i = 0; i < n - 1; i++)
    {
        int s, t;
        cin >> s >> t;
        tree[t].father = s;
        tree[t].depth = tree[s].depth + 1;
        if (tree[t].depth > depth)
            depth = tree[t].depth;
        width[tree[t].depth]++; //这一深度对应的数量加一
    }
    int maxWidth = *max_element(width.begin(), width.end());
    cout << depth << endl
         << maxWidth << endl;
    int u, v;
    cin >> u >> v;
    int up1 = 0;
    int up2 = 0;

    //使两个节点处于同一高度
    if (tree[u].depth > tree[v].depth)
    {
        while (tree[u].depth != tree[v].depth)
        {
            u = tree[u].father;
            up1++;
        }
        //同一分支的情况
        if (u == v)
        {
            cout << up1*2;
            return 0;
        }
    }

    else if (tree[u].depth < tree[v].depth)
    {
        while (tree[u].depth != tree[v].depth)
        {
            v = tree[v].father;
            up2++;
        }
        //同一分支的情况
        if (u == v)
        {
            cout << up2;
            return 0;
        }
    }

    //不同分支的情况
    while (tree[u].father != tree[v].father)
    {
        u = tree[u].father;
        v = tree[v].father;
        up1++;
        up2++;
    }
    up1++;
    up2++;
    cout << up1 * 2 + up2;

    return 0;
}
