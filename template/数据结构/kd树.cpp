#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n, op, xl, xr, yl, yr, lstans;
struct Node
{
    //左右孩子即节点的值
    int x, y, v;
} s[maxn];

bool cmp1(int a, int b)
{
    return s[a].x < s[b].x;
}
bool cmp2(int a, int b)
{
    return s[a].y < s[b].y;
}
//重构常数
double a = 0.725;
int rt, cur, d[maxn], lc[maxn], rc[maxn];
int L[maxn], R[maxn], D[maxn], U[maxn];
//子树节点个数，子树节点权值和
int siz[maxn], sum[maxn];
//中序遍历序列和其下标
int g[maxn], t;
//中序遍历序列
void print(int x)
{
    if (!x)
        return;
    print(lc[x]);
    g[++t] = x;
    print(rc[x]);
}

void maintain(int x)
{
    siz[x] = siz[lc[x]] + siz[rc[x]] + 1;
    sum[x] = sum[lc[x]] + sum[rc[x]] + s[x].v;

    //左右边界为x坐标，上下边界为y坐标
    L[x] = R[x] = s[x].x;
    D[x] = U[x] = s[x].y;
    //expand 边界
    if (lc[x])
    {
        L[x] = min(L[x], L[lc[x]]);
        R[x] = max(R[x], R[lc[x]]);
        D[x] = min(D[x], D[lc[x]]);
        U[x] = max(U[x], U[lc[x]]);
    }
    if (rc[x])
    {
        L[x] = min(L[x], L[rc[x]]);
        R[x] = max(R[x], R[rc[x]]);
        D[x] = min(D[x], D[rc[x]]);
        U[x] = max(U[x], U[rc[x]]);
    }
}

//将k维空间中n个点建成一个树
int build(int l, int r)
{
    if (l > r)
        return 0;
    int mid = (l + r) >> 1;
    //计算均值
    double av1 = 0, av2 = 0, va1 = 0, va2 = 0;
    for (int i = l; i <= r; ++i)
    {
        av1 += s[g[i]].x;
        av2 += s[g[i]].y;
    }
    av1 /= (r - l + 1);
    av2 /= (r - l + 1);
    //计算方差
    for (int i = l; i <= r; ++i)
    {
        va1 += (av1 - s[g[i]].x) * (av1 - s[g[i]].x);
        va2 += (av2 - s[g[i]].y) * (av2 - s[g[i]].y);
    }
    //对方差较大的进行分割
    if (va1 > va2)
    {
        //取中位数
        nth_element(g + l, g + mid, g + r + 1, cmp1);
        d[g[mid]] = 1;
    }
    else
    {
        nth_element(g + l, g + mid, g + r + 1, cmp2);
        d[g[mid]] = 2;
    }
    //左右子树
    lc[g[mid]] = build(l, mid - 1);
    rc[g[mid]] = build(mid + 1, r);

    //维护相关信息
    maintain(g[mid]);
    return g[mid];
}

void rebuild(int &x)
{
    t = 0;
    //获得中序遍历序列g[]
    print(x);
    //在g[]上面建树
    x = build(1, t);
}

bool bad(int x)
{
    //若其中有一个子树的结点数在以x为根的子树的结点数中的占比大于a,
    //则认为以x为根的子树是不平衡的，需要重构
    return a * siz[x] <= (double)max(siz[lc[x]], siz[rc[x]]);
}

void insert(int &x, int v)
{
    if (!x)
    {
        x = v;
        maintain(x);
        return;
    }
    if (d[x] == 1)
    {
        if (s[v].x <= s[x].x)
            insert(lc[x], v);
        else
            insert(rc[x], v);
    }
    else
    {
        if (s[v].y <= s[x].y)
            insert(lc[x], v);
        else
            insert(rc[x], v);
    }
    maintain(x);
    if (bad(x))
        rebuild(x);
}

int query(int x)
{
    //不在所要查询矩形内
    if (!x || xr < L[x] || xl > R[x] || yr < D[x] || yl > U[x])
        return 0;
    if (xl <= L[x] && R[x] <= xr && yl <= D[x] && U[x] <= yr)
        return sum[x];
    int ret = 0;
    if (xl <= s[x].x && s[x].x <= xr && yl <= s[x].y && s[x].y <= yr)
        ret += s[x].v;
    return query(lc[x]) + query(rc[x]) + ret;
}

int main()
{
    scanf("%d", &n);
    while (~scanf("%d", &op))
    {
        if (op == 1)
        {
            cur++;
            scanf("%d%d%d", &s[cur].x, &s[cur].y, &s[cur].v);
            s[cur].x ^= lstans;
            s[cur].y ^= lstans;
            s[cur].v ^= lstans;
            insert(rt, cur);
        }
        if (op == 2)
        {
            scanf("%d%d%d%d", &xl, &yl, &xr, &yr);
            xl ^= lstans;
            yl ^= lstans;
            xr ^= lstans;
            yr ^= lstans;
            printf("%d\n", lstans = query(rt));
        }
        if(op==3)
            return 0;
    }
}