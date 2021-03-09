#include <bits/stdc++.h>
using namespace std;
const int maxn = 220;
int weight[maxn];
unordered_map<int, string> id2name;
unordered_map<string, int> name2id;
struct Edge
{
    int to, cost;
};
vector<Edge> G[maxn];
typedef pair<int, int> P; //第一个为距离，第二个为编号
int D[maxn];
vector<int> pre[maxn];
bool visited[maxn];
void Dijkstra(int s)
{
    memset(visited, 0, sizeof(visited));
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
                D[e.to] = D[cur.second] + e.cost;
                Q.push({D[e.to], e.to});
                //  dp[e.to] = dp[cur.second] + weight[e.to];
                pre[e.to].clear();
                pre[e.to].push_back(cur.second);
            }
            else if (D[e.to] == D[cur.second] + e.cost)
            {
                //dp[e.to] = max(dp[e.to], dp[cur.second] + weight[e.to]);
                pre[e.to].push_back(cur.second);
            }
        }
    }
}
vector<int> tmp, path;
int max_happiness;
double max_av_happiness;
int num ;
void dfs(int s)
{
    tmp.push_back(s);
    for (int i = 0; i < pre[s].size(); ++i)
    {
        dfs(pre[s][i]);
    }
    if (s == 0)
    {
        num++;
        int tmp_happiness = 0;
        for (int i = 0; i < tmp.size(); ++i)
        {
            tmp_happiness += weight[tmp[i]];
        }
        double tmp_av_happiness = 1.0 * tmp_happiness / (tmp.size() - 1);
        if (tmp_happiness > max_happiness)
        {
            max_happiness = tmp_happiness;
            max_av_happiness = tmp_av_happiness;
            path = tmp;
        }
        else if (tmp_happiness == max_happiness && tmp_av_happiness > max_av_happiness)
        {
            max_av_happiness = tmp_av_happiness;
            path = tmp;
        }
    }
    tmp.pop_back();
}
int main()
{
    int n, k;
    cin >> n >> k;
    string start, s;
    cin >> start;
    name2id[start] = 0;
    int w;
    int dest;
    weight[0] = 0;
    for (int i = 1; i < n; ++i)
    {
        cin >> s >> w;
        if (s == "ROM")
            dest = i;
        id2name[i] = s;
        name2id[s] = i;
        weight[i] = w;
    }
    string a, b;
    for (int i = 0; i < k; ++i)
    {
        cin >> a >> b >> w;
        G[name2id[a]].push_back({name2id[b], w});
        G[name2id[b]].push_back({name2id[a], w});
    }
    Dijkstra(0);
    dfs(dest);
    cout << num << " " << D[dest] << " " << max_happiness << " " << (int)max_av_happiness << endl;
    cout << start;
    for (int i = path.size() - 2; i >= 0; i--)
    {
        cout << "->" << id2name[path[i]];
    }
}