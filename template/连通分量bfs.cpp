#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
vector<int> G[maxn];
bool visited[maxn];
void bfs(int x)
{
    queue<int> Q;
    Q.push(x);
    visited[x] = true;
    while (!Q.empty())
    {
        int p = Q.front();

        Q.pop();
        for (int i = 0; i < G[p].size(); ++i)
        {
            if (!visited[G[p][i]])
            {
                Q.push(G[p][i]);
                visited[G[p][i]] = true;
            }
        }
    }
}
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int a, b;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int city;
    for (int i = 0; i < k; ++i)
    {
        int count1 = 0;
        cin >> city;
        memset(visited, 0, sizeof(visited));
        visited[city] = 1;
        for (int i = 1; i <= n; ++i)
        {
            if (!visited[i])
            {
                bfs(i);
                count1++;
            }
        }
        cout << count1 - 1 << endl;
    }
}