#include <iostream>
const int MAX = 1e6;
typedef struct Arc
{
    int adjvex; //邻接的点的序号
    Arc *next;
    Arc(int adj) : adjvex(adj), next(NULL){}
} Arc;

typedef struct Node
{
    int indegree;
    int cur_len;
    Arc *firstArc;
} Nodelist[MAX];

Nodelist nodelist;
int n, m;
int maxLen=0;
int stack[MAX];
int top = 0;    //top为0时栈为空
void topo() {
    for (int i = 0; i < n;i++)
    {
        if(!nodelist[i].indegree)
            stack[++top] = i;
    }
    while (top)
    {
        int u = stack[top--];
        for (Arc *v = nodelist[u].firstArc; v;v=v->next)
        {
            nodelist[v->adjvex].cur_len = std::max(nodelist[v->adjvex].cur_len, nodelist[u].cur_len + 1);
            maxLen = std::max(maxLen, nodelist[v->adjvex].cur_len);
            if (!--nodelist[v->adjvex].indegree)
                stack[++top] = v->adjvex;
        }
    }
    
}
int main() {
    scanf("%d %d", &n, &m);
    int a, b;
    while (m--)
    {
        scanf("%d %d", &a, &b);
        a--;
        b--;
        Arc* B = new Arc(b);
        B->next = nodelist[a].firstArc;
        nodelist[a].firstArc = B;
        nodelist[b].indegree++;
    }
    topo();
    printf("%d", maxLen + 1);
}