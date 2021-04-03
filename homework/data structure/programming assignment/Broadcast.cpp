#include <iostream>
using namespace std;
const int maxn = 1e4 + 1;
typedef struct Arc
{
    int adjvex;
    Arc *nextArc;
    Arc(int adj) : adjvex(adj), nextArc(NULL) {}
} Arc;
typedef struct Node
{
    int color;
    Arc *first;
    Node() : color(0), first(NULL) {}
} NodeList[maxn];
NodeList nodelist;
int queue[maxn];
int rear, front;
int n, m;
bool bfs(int v)
{
    queue[rear++] = v;
    rear %= maxn; //入队
    nodelist[v].color = 1;
    while (front < rear)
    {
        v = queue[front];
        front = (front + 1) % maxn; //出队
        for (Arc *u = nodelist[v].first; u; u = u->nextArc)
        {
            if (nodelist[u->adjvex].color == nodelist[v].color)
            {
                return false;
            }
            else if (nodelist[u->adjvex].color == 0)
            {
                nodelist[u->adjvex].color = -nodelist[v].color;
                queue[rear++] = u->adjvex;
            }
        }
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    while (m--)
    {
        int i, j;
        cin >> i >> j;
        Arc* a = new Arc(i);    //必须new一个节点，不然循环结束后就没了
        Arc* b = new Arc(j);
        a->nextArc = nodelist[j].first;
        nodelist[j].first = a;
        b->nextArc = nodelist[i].first;
        nodelist[i].first = b;
    }
    for (int i = 1; i <= n; i++)
    {
        if (nodelist[i].color == 0) //尚未遍历到的
        {
            if (!bfs(i))
            {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << 1 << endl;
    return 0;
}