#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 10;
vector<int> G[maxn];
int chains[maxn];   //chains[i]表示第i个节点的食物链数
int indegree[maxn]; //顶点i的入度
const int P = 80112002;
int main()
{
    int n, m;
    cin >> n >> m;
    int a, b;
    for (size_t i = 0; i < m; i++)
    {
        cin >> a >> b; //a->b, a eats b
        G[a].push_back(b);
        ++indegree[b];
    }

    queue<int> Q;
    for (size_t i = 1; i <= n; ++i)
    {
        if (!indegree[i])
        {
            Q.push(i);
            chains[i] = 1;
        }
    }
    int ans = 0;

    while (!Q.empty())
    {
        int p = Q.front();
        Q.pop();
        //出度为0
        if (!G[p].size())
        {
            ans = (ans + chains[p]) % P;
        }
        for (size_t i = 0; i < G[p].size(); ++i)
        {
            if (--indegree[G[p][i]] == 0)
                Q.push(G[p][i]);

            chains[G[p][i]] = (chains[G[p][i]] + chains[p]) % P;
        }
    }
    cout << ans;
}