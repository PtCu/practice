#include <bits/stdc++.h>
using namespace std;
const int maxn = 510;
int G[2][maxn][maxn];
vector<int> pre[2][maxn];
int D[2][maxn];
bool visited[maxn];
typedef pair<int, int> P; //第一个为距离，第二个为编号
int n, m;
void Dijkstra(int s, int k)
{
    fill(D[k], D[k] + maxn, INT_MAX);
    memset(visited, 0, sizeof(visited));
    D[k][s] = 0;
    priority_queue<P, vector<P>, greater<P>> Q;
    Q.push({0, s});
    while (!Q.empty())
    {
        P cur = Q.top();
        Q.pop();
        if (visited[cur.second])
            continue;
        visited[cur.second] = 1;
        for (int i = 1; i <= n; ++i)
        {
            int cost = G[k][cur.second][i];
            if (cost == 0)
                continue;
            if (D[k][i] > D[k][cur.second] + cost)
            {
                D[k][i] = D[k][cur.second] + cost;
                Q.push({D[k][i], i});
                pre[k][i].clear();
                pre[k][i].push_back(cur.second);
            }
            else if (D[k][i] == D[k][cur.second] + cost)
            {
                pre[k][i].push_back(cur.second);
            }
        }
    }
}
vector<int> tmp;
vector<int> path1, path2;
int s, t;
int min_time = INT_MAX;
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
        dfs1(pre[0][d][i], cur_time + G[1][pre[0][d][i]][d]);
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

    cin >> n >> m;
    int a, b, one_way, len, time;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b >> one_way >> len >> time;
        if (one_way)
        {
            G[0][a][b] = len;
            G[1][a][b] = time;
        }
        else
        {
            G[0][a][b] = G[0][b][a] = len;
            G[1][a][b] = G[1][b][a] = time;
        }
    }

    cin >> s >> t;
    Dijkstra(s, 0);
    Dijkstra(s, 1);

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