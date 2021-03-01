#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
struct Node
{
    int address, data, next;
    int order = maxn;
} node[maxn];
bool cmp1(const Node &a, const Node &b)
{
    return a.order < b.order;
}
bool cmp2(const Node &a, const Node &b)
{
    return a.data < b.data;
}
int main()
{
    int n, begin;
    scanf("%d %d", &n, &begin);
    for (int i = 0; i < n; i++)
    {
        int add;
        scanf("%d", &add);
        node[add].address = add;
        scanf("%d %d", &node[add].data, &node[add].next);
    }
    //找链表的有效结点（即从给定头结点能链接到的结点）
    //将这些有效结点按照链表的指向顺序赋值到order，即链表的第i个结点order为i，i从0开始
    int p = begin, cnt = 0;
    while (p != -1)
    {
        node[p].order = cnt++;
        p = node[p].next;
    }
    sort(node, node + 100000, cmp1);
    //将有效结点按照存储的数据升序排列
    sort(node, node + cnt, cmp2);
    //输出
    //可能会出现没有有效结点的情况
    if (cnt == 0)
    {
        printf("0 -1");
        return 0;
    }
    printf("%d %05d\n", cnt, node[0].address);
    for (int i = 0; i < cnt; i++)
    {
        printf("%05d %d ", node[i].address, node[i].data);
        if (i == cnt - 1)
            printf("-1");
        else
            printf("%05d\n", node[i + 1].address);
    }
    return 0;
}