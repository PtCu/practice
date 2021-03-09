#include <bits/stdc++.h>
#define INF 100000005
#define MAX 100006
using namespace std;

typedef pair<int, int> P;
// 使用pair记录当前搜索的点，pair<int,int>对：
// 　　　　first记录最小距离，用以在优先队列中实现类似'最小堆优化'；
// 　　　　second记录该最小距离对应的点；
//结点信息是算法运算过程中变化的

struct edge
{
    int to;
    int cost;
    edge(int t, int c) : to(t), cost(c)
    {
    }
};
//边的信息是建好图之后就固定的

const int N = 100006;
vector<edge> g[N];
int D[N]; //s到各点的距离
int n, m; //n个点 m条边
bool used[N];
void Dijkstra(int s)
{
    memset(used, 0, sizeof(used));
    priority_queue<P, vector<P>, greater<P>> que; //小端优先队列 greater说明是小顶堆
    fill(D, D + MAX, INF);                        //注意必须初始化为最大
    D[s] = 0;
    que.push(P(0, s)); //P(0,s)第一位表示最小距离，第二位表示最小距离对应的点
    while (!que.empty())
    {
        P p = que.top();
        que.pop();
        int v = p.second; //v是已知阵营的点，作为当前节点；
        if (used[v])
            continue;
        used[v] = 1;
        for (int i = 0; i < g[v].size(); i++)
        {
            //遍历所有后续边,算出距离最小的边并放入队列。队列自动从小到大排序，将最小的放在最前
            edge e = g[v][i];
            int to = e.to;
            int cost = e.cost;
            if (D[to] > D[v] + cost)
            { //比较s直接到to的距离 和s经过v到to的距离
                D[to] = D[v] + cost;
                que.push(P(D[to], to)); //将更小的放进队列
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    int a, b, d;
    //Vector<edge> g[MAX]的初始化
    for (int i = 0; i < MAX; i++)
    {
        g[i].clear();
    }
    //距离D的初始化
    //fill(D,D+MAX,INF) ;//等Dijkstra时再初始化也行
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> d; //d是权值
        g[a].push_back(edge(b, d));
        g[b].push_back(edge(a, d));
    }
    int s, t; //起点 终点
    s = 1;
    t = n;
    Dijkstra(s);
    cout << D[n] << endl;
    return 0;
}