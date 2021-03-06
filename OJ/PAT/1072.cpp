#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
struct Edge
{
    int to, cost;
    Edge(int _t, int _c) : to(_t), cost(_c) {}
};
vector<Edge> G[maxn];
typedef pair<int, int> P; //第一个距离，第二个编号
bool visited[maxn];
int D[maxn];
int n, m, k, ds;

void Dijkstra(int s)
{
    fill(D, D + maxn, INT_MAX);
    memset(visited, 0, sizeof(visited));
    priority_queue<P, vector<P>, greater<P>> Q;
    D[s] = 0;
    Q.push({0, s});
    while (!Q.empty())
    {
        P p = Q.top();
        Q.pop();
        if (visited[p.second])
            continue;
        visited[p.second] = 1;
        for (int i = 0; i < G[p.second].size(); ++i)
        {
            Edge e = G[p.second][i];
            if (D[e.to] > D[p.second] + e.cost)
            {
                D[e.to] = D[p.second] + e.cost;
                Q.push({D[e.to], e.to});
            }
        }
    }
}
//s到社区点的距离
bool getData(float &mean, float &mini)
{
    float sum = 0;
    int tmp_min = INT_MAX;
    for (int i = 1; i <= n; ++i)
    {
        if (D[i] > ds)
            return false;
        sum += D[i];
        tmp_min = min(tmp_min, D[i]);
    }
    mean = sum / n;
    mini = (float)tmp_min;
    return true;
}

int main()
{

    cin >> n >> m >> k >> ds;
    string a, b;
    int i_a, i_b;
    int w;
    for (int i = 0; i < k; ++i)
    {
        cin >> a >> b >> w;
        if (a[0] == 'G')
        {
            a.erase(a.begin());
            i_a = stoi(a) + n;
        }
        else
        {
            i_a = stoi(a);
        }
        if (b[0] == 'G')
        {
            b.erase(b.begin());
            i_b = stoi(b) + n;
        }
        else
        {
            i_b = stoi(b);
        }

        G[i_a].push_back({i_b, w});
        G[i_b].push_back({i_a, w});
    }

    float ans_mean = 0;
    float ans_min = 0;
    int idx = -1;
    for (int i = 1 + n; i <= n + m; ++i)
    {
        float tmp_mean = 0, tmp_min = 0;
        Dijkstra(i);
        if (getData(tmp_mean, tmp_min))
        {
            if (tmp_min > ans_min)
            {
                ans_mean = tmp_mean;
                ans_min = tmp_min;
                idx = i;
            }
            else if (tmp_min == ans_min && tmp_mean < ans_mean)
            {
                idx = i;
                ans_mean = tmp_mean;
            }
        }
    }
    if (idx!=-1)
    {
        printf("G%d\n%.1f %.1f", idx-n, ans_min, ans_mean + 1e-8);
    }
    else
    {
        cout << "No Solution";
    }
}