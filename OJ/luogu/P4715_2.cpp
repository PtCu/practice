#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int l, r;
    int w;
    int id;
} tree[600];

void build(int k, int l, int r)
{
    tree[k].l = l;
    tree[k].r = r;
    if (tree[k].l == tree[k].r)
    {
        cin >> tree[k].w;
        tree[k].id = l;
        return;
    }
    build(2 * k, l, (l + r) / 2);         //左子树
    build(2 * k + 1, (l + r) / 2 + 1, r); //右子树
    if(tree[2*k].w>tree[2*k+1].w){
        tree[k].w = tree[2 * k].w;
        tree[k].id = tree[2 * k].id;
    }
    else{
        tree[k].w = tree[2 * k + 1].w;
        tree[k].id = tree[2 * k + 1].id;
    }
   
}

int main()
{
    int n;
    cin >> n;
    build(1, 1, (1 << n));
    if (tree[2].w < tree[3].w)
        cout << tree[2].id;
    else
        cout << tree[3].id;
}