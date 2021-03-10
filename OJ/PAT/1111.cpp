#include <bits/stdc++.h>
using namespace std;
const int maxn = 520;
struct Edge
{
    int to, cost;
};
vector<Edge> G[2][maxn];
vector<int> pre[2][maxn];
int D[2][maxn];
bool visited[maxn];
typedef pair<int, int> P; //第一个为距离，第二个为编号

void Dijkstra(vector<Edge> G[], int D[], int s, vector<int>pre[])
{
    fill(D, D + maxn, INT_MAX);
    memset(visited, 0, sizeof(visited));
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
vector<int> tmp;
vector<int> path1, path2;
int s, t;
int min_time=INT_MAX;
int cur_time;
void dfs1(int d, int cur_time)
{
    tmp.push_back(d);
    if (d == s)
    {
        if (cur_time < min_time)
        {
            path1 = tmp;
            min_time = cur_time;
        }
    }
    for (int i = 0; i < pre[0][d].size(); ++i)
    {
        for (int j = 0; j < G[1][pre[0][d][i]].size(); ++j)
        {
            if (G[1][pre[0][d][i]][j].to == d)
            {
                dfs1(pre[0][d][i], cur_time + G[1][pre[0][d][i]][j].cost);
            }
        }
    }
    tmp.pop_back();
}
int min_inter = INT_MAX;
void dfs2(int d)
{
    tmp.push_back(d);

    if (d == s)
    {
        int cur_inter = tmp.size();
        if (cur_inter < min_inter)
        {
            path2 = tmp;
            min_inter = cur_inter;
        }
    }
    for (int i = 0; i < pre[1][d].size(); ++i)
    {
        dfs2(pre[1][d][i]);
    }
    tmp.pop_back();
}

int main()
{
    int n, m;
    cin >> n >> m;
    int a, b, one_way, len, time;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b >> one_way >> len >> time;
        if (one_way)
        {
            G[0][a].push_back({b, len});
            G[1][a].push_back({b, time});
        }
        else
        {
            G[0][a].push_back({b, len});
            G[1][a].push_back({b, time});
            G[0][b].push_back({a, len});
            G[1][b].push_back({a, time});
        }
    }

    cin >> s >> t;
    Dijkstra(G[0], D[0], s, pre[0]);
    Dijkstra(G[1], D[1], s, pre[1]);
    dfs1(t, 0);
    tmp.clear();
    dfs2(t);
    if (path1 != path2)
    {
        cout << "Distance = " << D[0][t] << ": " << path1[path1.size() - 1];
        for (int i = path1.size() - 2; i >= 0; --i)
        {
            cout << " -> " << path1[i];
        }
        cout << endl;
        cout << "Time = " << D[1][t] << ": " << path2[path2.size() - 1];
        for (int i = path2.size() - 2; i >= 0; --i)
        {
            cout << " -> " << path2[i];
        }
    }
    else
    {
        cout << "Distance = " << D[0][t] << "; ";
        cout << "Time = " << D[1][t] << ": " << path2[path2.size() - 1];
        for (int i = path2.size() - 2; i >= 0; --i)
        {
            cout << " -> " << path2[i];
        }
    }
}