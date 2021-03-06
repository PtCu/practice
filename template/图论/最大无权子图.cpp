//模板，最大权闭合子图
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 5;
const int INF = 0x3f3f3f;
struct Edge
{
    int from, to, cap, flow;
    Edge(int f, int t, int c, int fl) : from(f), to(t), cap(c), flow(fl) {}
};
struct Edm
{
    int n, m;
    vector<Edge> edges;  //记录边
    vector<int> G[maxn]; //G[i][j]表示i的第j条边在edges中的编号
    int a[maxn];         //残余量
    int p[maxn];         //记录入弧

    void init(int n)
    {
        for (int i = 0; i < n; i++)
        {
            G[i].clear();
        }
        edges.clear();
    }

    void addEdge(int from, int to, int cap)
    {
        edges.push_back(Edge(from, to, cap, 0)); //正向边
        edges.push_back(Edge(to, from, 0, 0));   //反向边
        m = edges.size();
        G[from].push_back(m - 2); //m-2为编号
        G[to].push_back(m - 1);
    }

    int maxFlow(int s, int t)
    {
        int flow = 0;
        for (;;)
        {
            //每次计算残余时，先将a清空，并重新申请队列
            memset(a, 0, sizeof(a));
            queue<int> Q;
            Q.push(s);
            a[s] = INF;
            while (!Q.empty())
            {
                int x = Q.front();
                Q.pop();
                for (int i = 0; i < G[x].size(); i++)
                {
                    Edge &e = edges[G[x][i]];
                    if (!a[e.to] && e.cap > e.flow) //不能取等号。如果反向边的话，cap==flow，会通过
                    {
                        p[e.to] = G[x][i];
                        a[e.to] = min(a[x], e.cap - e.flow);
                        Q.push(e.to);
                    }
                }
                if (a[t])
                    break;
            }
            if (!a[t])
                break;
            //assert:以下a[t]不为0。a[t]为路径上可增加最大量，所以以下从t到s加上a[t]即可
            for (int u = t; u != s; u = edges[p[u]].from) //p[u]是
            {
                edges[p[u]].flow += a[t];
                edges[p[u] ^ 1].flow -= a[t];
            }
            flow += a[t]; //增加最大流
        }
        return flow;
    }
};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    Edm E;
    E.init(n);
    int sum = 0;
    //连边。如果是正权值，则与源点s连接，否则与汇点t连接
    //并且记录正权值的和
    for (int i = 1; i <= n; i++)
    {
        int val;
        cin >> val;
        if (val < 0)
        {
            E.addEdge(i, n + 1, -val);
        }
        else
        {
            E.addEdge(0, i, val);
            sum += val;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        E.addEdge(a, b, INF);
    }
    cout << sum - E.maxFlow(0, n + 1);
}