#include <algorithm>
#include <cstdio>
//https://oi-wiki.org/dp/tree/ https://www.luogu.com.cn/problem/P1352
using namespace std;
//前向星
struct edge
{
    int v, next;
} e[6005];  //e[i].v表示第i条边指向的节点,e[i].next表示第i条边的下一个指针
int head[6005], n, cnt, f[6005][2], ans, is_h[6005], vis[6005]; //head[i]表示第i个节点的边集所对应的链表的头指针
void addedge(int u, int v)  //u是v的父亲
{
    e[++cnt].v = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}
void calc(int k)
{
    vis[k] = 1;
    for (int i = head[k]; i; i = e[i].next)
    { // 枚举该结点的每个子结点
        if (vis[e[i].v])
            continue;
        calc(e[i].v);
        f[k][1] += f[e[i].v][0];
        f[k][0] += max(f[e[i].v][0], f[e[i].v][1]);
    }
    return;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &f[i][1]);
    for (int i = 1; i < n; i++)
    {
        int l, k;
        scanf("%d%d", &l, &k);
        is_h[l] = 1;    //是下属为1
        addedge(k, l);  //k是l的直接上司
    }
    for (int i = 1; i <= n; i++)
        if (!is_h[i])
        { // 从根结点开始DFS
            calc(i);
            printf("%d", max(f[i][1], f[i][0]));
            return 0;
        }
}