#include <bits/stdc++.h>
using namespace std;
const int MAX = 5e3 + 10;
const int P = 80112002;
vector<int> G[MAX];
int dp[MAX];
int inDegree[MAX];
queue<int> q;

int main()
{
    ios::sync_with_stdio(0); //取消cin,cout的缓存
    cin.tie(0);
    cout.tie(0); //解绑
    int n, m;
    int ans = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        inDegree[v]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
            dp[i] = 1;
        }
    }
    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        if (G[p].size() == 0)
            ans = (ans += dp[p]) % P;
        for (int i = 0; i < G[p].size(); i++)
        {
            dp[G[p][i]] = (dp[G[p][i]] + dp[p]) % P;
            inDegree[G[p][i]]--;
            if (inDegree[G[p][i]] == 0)
            {
                q.push(G[p][i]);
            }
        }
    }
    cout << ans;
}