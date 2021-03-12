//luogu1983.cpp
//层级结构可以建图
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
unordered_set<int> G[maxn];
bool cache[maxn];
vector<int> stop;
int indgree[maxn];
int deep[maxn];
// dep[son]=dep[father]+1
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int s, x;
    for (size_t i = 0; i < m; ++i)
    {
        memset(cache, 0, sizeof(cache));
        stop.clear();
        cin >> s;
        for (size_t j = 1; j <= s; ++j)
        {
            cin >> x;
            stop.push_back(x);
            cache[x] = 1;
        }
        for (int j = stop[0] + 1; j <= stop[s - 1]; ++j)
        {
            if (!cache[j]) //没停下来
            {
                for (auto k : stop) //所有停下来的
                {
                    if (G[k].count(j))
                        continue;
                    G[k].insert(j); //k到j的连线，表示停下来的级别比没停下的高
                    indgree[j]++;
                }
            }
        }
    }
    queue<int> Q;
    for (size_t i = 1; i <= n; ++i)
    {
        if (indgree[i] == 0)
        {
            Q.push(i);
            deep[i] = 1;
        }
    }
    int ans = 0;
    while (!Q.empty())
    {
        int p = Q.front();
        Q.pop();
        for (int u : G[p])
        {
            deep[u] = deep[p] + 1;
            ans = max(ans, deep[u]);
            if (!--indgree[u])
            {
                Q.push(u);
            }
        }
    }
    cout << ans;
}