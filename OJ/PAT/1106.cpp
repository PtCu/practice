#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
vector<int> G[maxn];
struct Node
{
    int id;
    int layer;
} nodes[maxn];
int n;
double price, r;
double min_price =numeric_limits<double>::max();
int num;
void bfs(Node root)
{
    queue<Node> Q;
    Q.push(root);
    double cur_price = 0;
    while (!Q.empty())
    {
        Node p = Q.front();
        Q.pop();
        if (G[p.id].size() == 0)
        {
            cur_price = pow(1 + r, p.layer) * price;
            if (cur_price < min_price)
            {
                min_price = cur_price;
                num = 1;
            }
            else if (cur_price == min_price)
            {
                num++;
            }
            continue;
        }
        for (int i = 0; i < G[p.id].size(); ++i)
        {
            Q.push({G[p.id][i], p.layer + 1});
        }
    }
}
int main()
{

    cin >> n >> price >> r;
    int k, x;
    r *= 0.01;
    for (int i = 0; i < n; ++i)
    {
        cin >> k;
        for (int j = 0; j < k; ++j)
        {
            cin >> x;
            G[i].push_back(x);
        }
    }
    bfs({0, 0});
    printf("%.4lf %d", min_price, num);
    // cout << setiosflags(ios::fixed) << setprecision(4) << min_price << " " << num;
}