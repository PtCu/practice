#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
struct Node
{
    int next;
    char c;
} nodes[maxn]; //以下标作为实际地址
int main()
{
    int start1, start2, n;
    cin >> start1 >> start2 >> n;
    int x;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        cin >> nodes[x].c >> nodes[x].next;
    }
    //令两个指针同时开始走这两条路，以相同的速度遍历链表中的结点，若两条链表不相交，则两个指针同时到达链表的终点时将会重合，因为它们此时都指向空结点null。
    // 若两条链表相交，设链表A长度为a，链表B长度为b，相交部分链表长度为i，则两个指针不用等到终点就能提前重合。当一个指针走过的路程为a+b-i，另一个指针走过的路程为b+a-i时，双指针的下一步就会重合，它们都指向相交部分首结点。
    // 综上，若双指针重合结点为null，则两链表不相交；若双指针重合结点不为null，则两链表相交。
    int i = start1, j = start2;
    while (i != j)
    {
        //遍历完a，从第二个开始遍历
        if (i == -1)
            i=start2;
        else
            i = nodes[i].next;
        if (j == -1)
            j=start1;
        else
            j = nodes[j].next;
    }
    if (i == -1)
        cout << -1;
    else
        printf("%05d", i);
}