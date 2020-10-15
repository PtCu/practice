#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 1;
const int INF = 0x3f3f3f3f;
//EdmondsKarp算法
struct Edge
{
    int from, to, cap, flow;
    Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
};
struct EdmondsKarp
{
    int n, m;   //n为点数，m为边数
    vector<Edge> edges;  //边数的两倍
    vector<int> G[maxn]; //邻接表，G[i][j]表示结点i的第j条边在e数组中的序号
    int a[maxn];         //当起点到i的可改进量
    int p[maxn];         //最短路树上p的入弧编号

    void init(int n)    //n为顶点数
    {
        for (int i = 0; i < n; i++)
            G[i].clear();
        edges.clear();
    }

    void addEdge(int from, int to, int cap)
    {
        edges.push_back(Edge(from, to, cap, 0)); //正向边
        edges.push_back(Edge(to, from, 0, 0));   //反向边
        m = edges.size();
        G[from].push_back(m - 2); //G[i][j]表示结点i的第j个边在Edges中的序号
        G[to].push_back(m - 1);
    }

    int Maxflow(int s, int t)
    {
        int flow = 0;
        for (;;)
        {   //每次计算残余时，先清空，并重新申请队列
            memset(a, 0, sizeof(a));
            queue<int> Q; //BFS
            Q.push(s);
            a[s] = INF;
            while (!Q.empty())
            {
                int x = Q.front(); //当前节点x
                Q.pop();
                for (int i = 0; i < G[x].size(); i++) //取x的第i条边
                {
                    Edge &e = edges[G[x][i]]; //取出
                    if (!a[e.to] && e.cap > e.flow) //如果第i条边还没计算并且有残余值
                    {
                        p[e.to] = G[x][i];  //保存入弧编号，即对于边[i,j]保存j的起始点i的编号
                        a[e.to] = min(a[x], e.cap - e.flow);    //计算残量。取路径上的最小值为残量
                        Q.push(e.to);   
                    }
                }
                if (a[t])   //不为0则说明已经计算出了到汇点t的残余量
                    break;
            }
            if (!a[t])  //退出条件:到t的残余量为0，说明已经无法继续优化了
                break;
            //assert:此时a[t]不为0.即a[t]此时为该路径上可增加的残余量。所以以下从t到s将沿途的边加上a[t]即可
            for (int u = t; u != s; u = edges[p[u]].from)   
            {
                edges[p[u]].flow += a[t];       //根据残量来增加流量
                edges[p[u] ^ 1].flow -= a[t];   //反向边    异或后，偶数加一，奇数减一。由于保存编号时，正向边的编号都是偶数，对应的反向边为正向边+1，所以异或后可得到对应的反向边
            }
            flow += a[t];
        }
        return flow;
    }
};

int main() {
    EdmondsKarp E;
    E.init(6);
    E.addEdge(0, 1, 16);
    E.addEdge(0, 2, 13);
    E.addEdge(1, 2, 10);
    E.addEdge(2, 1, 4);
    E.addEdge(1, 3, 12);
    E.addEdge(2, 4, 14);
    E.addEdge(3, 2, 9);
    E.addEdge(4, 3, 7);
    E.addEdge(3, 5, 20);
    E.addEdge(4, 5, 4);

    cout<<E.Maxflow(0, 5);
}