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