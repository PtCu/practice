#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 20;
struct Node
{
    int v, depth;
    Node() {}
    Node(int _v, int _d) : v(_v), depth(_d) {}
} nodes[maxn];
vector<int> G[maxn];
int n, L;
bool visited[maxn];
int query(int s)
{
    queue<Node> Q;
    Q.push({s, 0});
    int cnt = -1;
    memset(visited, 0, sizeof(visited));
    while (!Q.empty())
    {
        Node p = Q.front();
        Q.pop();
        if (visited[p.v])
            continue;
        visited[p.v] = 1;
        if (p.depth <= L)
        {
            cnt++;
        }
        for (int i = 0; i < G[p.v].size(); ++i)
        {
            Q.push(Node(G[p.v][i], p.depth + 1));
        }
    }
    return cnt;
}
int main()
{
    int m, x;
    cin >> n >> L;
    for (int i = 1; i <= n; ++i)
    {
        cin >> m;
        for (int j = 1; j <= m; ++j)
        {
            cin >> x;
            G[x].push_back(i);
        }
    }
    int k;
    cin >> k;
    for (int i = 1; i <= k; ++i)
    {
        cin >> x;
        cout << query(x) << endl;
    }
}