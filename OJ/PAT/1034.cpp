#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
struct Edge
{
    int to;
};
vector<int> G[maxn];
unordered_map<string, int> M;
unordered_map<int, string> M2;
int degree[maxn];
int n, k;
map<string, int> gang;
bool visited[maxn];
void bfs(int x)
{
    int weight = degree[x];
    int mem = 1;
    queue<int> Q;
    Q.push(x);
    visited[x] = 1;
    int maxP = degree[x];
    int maxP_i = x;
    while (!Q.empty())
    {
        int p = Q.front();
        Q.pop();
        for (int i = 0; i < G[p].size(); ++i)
        {
            if (!visited[G[p][i]])
            {
                visited[G[p][i]] = 1;
                mem++;
                weight += degree[G[p][i]];
                if (degree[G[p][i]] > maxP)
                {
                    maxP = degree[G[p][i]];
                    maxP_i = G[p][i];
                }
                Q.push(G[p][i]);
            }
        }
    }
    if (weight / 2 > k && mem > 2)
    {
        gang[M2[maxP_i]] = mem;
    }
}
int main()
{
    cin >> n >> k;
    string a, b;
    int w;
    int cnt = 0;
    memset(visited, 1, sizeof(visited));
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b >> w;
        if (!M.count(a))
        {
            M[a] = cnt;
            M2[cnt] = a;
            visited[cnt++] = 0;
        }
        if (!M.count(b))
        {
            M[b] = cnt;
            M2[cnt] = b;
            visited[cnt++] = 0;
        }
        G[M[a]].push_back(M[b]);
        G[M[b]].push_back(M[a]);
        degree[M[a]] += w;
        degree[M[b]] += w;
    }
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            bfs(i);
        }
    }
    cout << gang.size() << endl;
    if (gang.size() != 0)
        for (auto iter = gang.begin(); iter != gang.end(); ++iter)
        {
            cout << iter->first << " " << iter->second << endl;
        }
}