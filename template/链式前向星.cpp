/*
前向星是存储有向图的一种数据结构。
它不同于邻接矩阵和邻接表，利用图的端点进行边的扫描，
而是一个基于边链表的数据结构，
在给定入口顶点时可顺边链表顺序访问边，
而无需关心顶点的信息（所有顶点可以借助边来访问，与邻接表和邻接矩阵相反）。
因此只需要构建一个链表(next)，链表的每一个节点代表一条边；
同时为每一个顶点设置一个入口(head)，指向该顶点的第一条出边；
为每条边设置一个终点(to)，至此前向星数据结构就构建完成。

如果顶点少的话适合用链式前向星。复杂度
由前向星数据结构的设计思路可以看出，从某个顶点开始遍历边到遍历结束恰好走完一条完整的路径，很像DFS的情形。
*/
const int maxm = 10;
const int maxn = 5;
struct E
{
    //to为指向的结点，w为边权，next为下一个结点
    int to, w, next;
} Edges[maxm*3]; //Edge存的是所有边数(边的连接信息,终点,权值,下条边都在这里),无向图是2倍

//Head:每个顶点(从i出发)的第一条边(相当于头指针,指向首元结点)
int Head[maxn];
//计数器变量，指向最近的没有被使用的结点，以它为空节点
int tot;

//增加从u到v的边，权值为w
inline void AddEdge(int u, int v, int w)
{
    //头插法
    Edges[tot].to = v;
    Edges[tot].w = w;
    Edges[tot].next = Head[u];
    Head[u] = tot++; //先赋值再自增
}

void traverse(int x){
    //这里定义空节点为-1
    for (int i = Head[x]; ~i;i=Edges[i].next){
        int v = Edges[i].to, w = Edges[i].w;
        //To do something...
    }
}