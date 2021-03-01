#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
vector<int> G[maxn];
int node[maxn];
int sum[maxn];
int pre[maxn];
vector<int> sat_leaf;
int n, m, s;
void bfs()
{
    queue<int> Q;
    Q.push(0);
    sum[0] = node[0];
    while (!Q.empty())
    {
        int p = Q.front();
        Q.pop();
        //有可能只有一个根节点的情况，所以要在这里记录路径
        if(sum[p]==s&&G[p].size()==0){
            sat_leaf.push_back(p);
        }
        for (int i = 0; i < G[p].size(); ++i)
        {
            Q.push(G[p][i]);
            sum[G[p][i]] = sum[p] + node[G[p][i]];
        }
    }
}
vector<vector<int>> path;
void getPath(int x)
{
    path.push_back(vector<int>());
    int p = x;
    while (p != 0)
    {
        path.back().push_back(p);
        p = pre[p];
    }
    path.back().push_back(0);
    reverse(path.back().begin(), path.back().end());
    for (int i = 0; i < path.back().size(); ++i)
    {
        path.back()[i] = node[path.back()[i]];
    }
}
bool cmp(const vector<int> &a, const vector<int> &b)
{
    int p = 0;
    for (int p = 0; p < min(a.size(), b.size()); p++)
    {
        if (a[p] < b[p])
            return 0;
        else if (a[p] > b[p])
            return 1;
    }
    return 0;
}
void print()
{
    sort(path.begin(), path.end(), cmp);
    for (int i = 0; i < path.size(); ++i)
    {
        for (int j = 0; j < path[i].size(); ++j)
        {
            if (j == 0)
                cout << path[i][j];
            else
                cout << " " << path[i][j];
        }
        cout << endl;
    }
}
int main()
{
    cin >> n >> m >> s;
    for (int i = 0; i < n; ++i)
    {
        cin >> node[i];
    }
    for (int i = 0; i < m; ++i)
    {
        int k, id, x;
        cin >> id >> k;
        for (int j = 0; j < k; ++j)
        {
            cin >> x;
            G[id].push_back(x);
            pre[x] = id;
        }
    }
    bfs();
    for (int i = 0; i < sat_leaf.size(); ++i)
    {
        getPath(sat_leaf[i]);
    }
    print();
}