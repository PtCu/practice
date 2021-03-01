#include <bits/stdc++.h>
using namespace std;
const int maxn = 10;
struct Node
{
    int l, r;      //左右孩子指针
    int w;         //值
    int flag;      //懒惰标记
} tree[maxn << 2]; //一般开节点数量的4倍空间
void build(int k, int l, int r)
{
    tree[k].l = l, tree[k].r = r;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(k << 1, l, mid);
    build(k << 1 | 1, mid + 1, r);
}
int sum;
void askInterval(int k, int l, int r)
{
    if (tree[k].l >= l && tree[k].r <= r)
    {
        sum += tree[k].w;
    }
    int mid = (tree[k].l + tree[k].r) >> 1;
    if (mid >= l)
        askInterval(k << 1, l, mid);
    if (mid < r)
        askInterval(k << 1 | 1, mid + 1, r);
}

void changeInterval(int k, int l, int r, int x)
{
    if (tree[k].l >= l && tree[k].r <= r)
    {
        tree[k].w += (tree[k].r - tree[k].l + 1) * x;
    }
    int mid = (tree[k].l + tree[k].r) >> 1;
    if (mid >= l)
        changeInterval(k << 1, l, mid, x);
    if (mid < r)
        changeInterval(k << 1 | 1, mid + 1, r, x);

    tree[k].w = tree[k << 1].w + tree[k << 1 + 1].w;
}


