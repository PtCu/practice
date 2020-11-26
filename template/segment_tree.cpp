#include <bits/stdc++.h>
using namespace std;
const int maxn = 10;
struct Node
{
    int l, r; //左右孩子指针
    int w;    //值
    int flag; //懒惰标记
} tree[maxn << 2]; //一般开节点数量的4倍空间
//https://bestsort.cn/2019/04/28/482/

//区间为[l,r]的结点，存储索引为k
void build(int k, int l, int r)
{
    tree[k].l = l, tree[k].r = r;
    //对于叶节点（单位长度为1的区间）
    if (tree[k].l == tree[k].r)
    {
        cin >> tree[k].w;
        return;
    }
    build(2 * k, l, (l + r) / 2);                   //左
    build(2 * k + 1, (l + r) / 2 + 1, r);           //右
    tree[k].w += tree[2 * k].w + tree[2 * k + 1].w; //求和
}

void down(int k)
{
    tree[k * 2].flag += tree[k].flag; //标记下传
    tree[k * 2 + 1].flag += tree[k].flag;

    tree[k * 2].w += tree[k].flag * (tree[k * 2].r - tree[k * 2].l + 1); //标记求和
    tree[k * 2 + 1].w += tree[k].flag * (tree[k * 2 + 1].r - tree[k * 2 + 1].l + 1);

    tree[k].flag = 0;
}

int sum = 0;
//区间查询，以给sum求和为例
void askInterval(int k, int x, int y)
{
    if (tree[k].l >= x && tree[k].r <= y)
    {
        sum += tree[k].w; //sum为全局变量，每次查询令sum=0
        return;
    }
    if (tree[k].flag)
        down(k);
    int mid = (tree[k].l + tree[k].r) / 2;
    if (x <= mid)
        askInterval(k * 2, x, y); //递归查询左子树
    if (y > mid)
        askInterval(k * 2 + 1, x, y); //递归查询右子树
}
//区间修改，以整体加z为例
void changeInterval(int k, int x, int y, int z)
{
    if (tree[k].l >= x && tree[k].r <= y)
    {
        tree[k].w += z * (tree[k].l - tree[k].r + 1);
        tree[k].flag += z;
        return;
    }
    if (tree[k].flag)
        down(k);
    //区间中点
    int mid = (tree[k].l + tree[k].r) / 2;
    if (x <= mid)
        changeInterval(k * 2, x, y, z);
    if (y > mid)
        changeInterval(k * 2 + 1, x, y, z);
    //更新过后回溯
    tree[k].w = tree[k * 2].w + tree[k * 2 + 1].w;
}

int ans = 0;
//单点查询
void askInterval(int k,int x){
    if(tree[k].l==x&&tree[k].r==x){
        ans = tree[k].w;
        return;
    }
    if(tree[k].flag)
        down(k);
    int mid = (tree[k].l + tree[k].r) / 2;
    if(x<=mid)
        askInterval(2 * k, x);
    if(x>mid)
        askInterval(k * 2 + 1, x);

}
//单点修改
void changeInterval(int k,int x,int z){
    if(tree[k].l==x&&tree[k].r==x){
        tree[k].w += z * (tree[k].r - tree[k].l + 1);
        tree[k].flag += z;
        return;
    }
    if(tree[k].flag)
        down(k);
    int mid = (tree[k].l + tree[k].r) / 2;
    if(x<=mid)
        changeInterval(2 * k, x, z);
    if(x>mid)
        changeInterval(2 * k + 1, x, z);
    tree[k].w = tree[2 * k].w + tree[2 * k + 1].w;
}