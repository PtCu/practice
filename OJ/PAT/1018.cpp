#include <bits/stdc++.h>
using namespace std;
const int maxn = 510;
int p[maxn];
struct Edge
{
    int to, cost;
};
vector<Edge> G[maxn];
vector<int> pre[maxn]; //前驱结点数组，存放每个节点的前驱结点
int c, n, s, m;
using P = pair<int, int>; //第一个为距离，第二个为编号
int D[maxn];
bool visited[maxn];
void Dijkstra(int s)
{
    fill(D, D + maxn, INT_MAX);
    D[s] = 0;
    priority_queue<P, vector<P>, greater<P>> Q;
    Q.push({0, s});
    while (!Q.empty())
    {
        P cur = Q.top();
        Q.pop();
        if (visited[cur.second])
            continue;
        visited[cur.second] = 1;
        for (int i = 0; i < G[cur.second].size(); ++i)
        {
            Edge e = G[cur.second][i];
            if (D[e.to] > D[cur.second] + e.cost)
            {
                //记录沿途路径
                D[e.to] = D[cur.second] + e.cost;
                Q.push({D[e.to], e.to});
                pre[e.to].clear();
                pre[e.to].push_back(cur.second);
            }
            else if (D[e.to] == D[cur.second] + e.cost)
            {
                pre[e.to].push_back(cur.second);
            }
        }
    }
}
int minNeed = INT_MAX, minBack = INT_MAX; //分别为从管理中心带出的最小自行车数和带回到管理中心的最小自行车数
vector<int> path, temp;                   //path存放最优路径，temp为当前临时路径
void dfs(int d)
{
    //保存路径结点。逆序
    temp.push_back(d);
    //从后至前依次遍历所有前驱结点。
    for (int i = 0; i < pre[d].size(); ++i)
    {
        dfs(pre[d][i]);
    }
    //遍历完一条最短路径
    if (d == 0)
    {
        int need = 0, extra = 0; //分别为需要带出的自行车数和带回的自行车数
        for (int i = temp.size() - 2; i >= 0; i--)
        {
            //逆序循环，从起点即管理中心开始至终点访问每个顶点
            int v = temp[i];
            if (p[v] > 0.5 * c)
            {
                extra += (p[v] - 0.5 * c);
            }
            //小于等于
            else if (extra >= 0.5 * c - p[v])
            {
                extra -= (0.5 * c - p[v]);
            }
            else
            {
                need += (0.5 * c - p[v] - extra);
                extra = 0;
            }
        }
        if (need < minNeed)
        {
            minNeed = need;
            minBack = extra;
            path = temp;
        }
        else if (need == minNeed && extra < minBack)
        {
            minBack = extra;
            path = temp;
        }
    }
    temp.pop_back(); //dfs完某个顶点后要弹出
}
int main()
{
    cin >> c >> n >> s >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> p[i];
    }
    int x, y, z;
    for (int i = 0; i < m; ++i)
    {
        cin >> x >> y >> z;
        G[x].push_back({y, z});
        G[y].push_back({x, z});
    }
    Dijkstra(0);
    dfs(s);
    cout << minNeed << " " << 0;
    for (int i = path.size() - 2; i >= 0;i--){
        cout << "->" << path[i];
    }
    cout << " " << minBack;
}