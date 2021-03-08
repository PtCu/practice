#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
vector<int> G[maxn];
struct Node
{
    int id;
    int layer;
};
int amount[maxn];
double price, r;

double bfs(Node root)
{
    queue<Node> Q;
    Q.push(root);
    double ans = 0;
    while (!Q.empty())
    {
        Node p = Q.front();
        Q.pop();
        if (G[p.id].size() == 0)
        {
            ans += pow((1 + r), p.layer) * price * amount[p.id];
            continue;
        }
        for (int i = 0; i < G[p.id].size(); ++i)
        {
            Node pc;
            pc.id = G[p.id][i];
            pc.layer = p.layer + 1;
            Q.push(pc);
        }
    }
    return ans;
}
int main()
{
    int n;

    cin >> n >> price >> r;
    r *= 0.01;
    int root = 0;
    for (int i = 0; i < n; ++i)
    {
        int m, x;
        cin >> m;
        if (m == 0)
        {
            cin >> x;
            amount[i] = x;
        }
        else
        {
            for (int j = 1; j <= m; ++j)
            {
                cin >> x;
                G[i].push_back(x);
            }
        }
    }
    double ans=bfs({0, 0});
    printf("%.1lf", ans);
}