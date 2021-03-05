#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
struct Node
{
    float price;
    float amount;
    float profit;
} nodes[maxn];
bool cmp(const Node &a, const Node &b)
{
    return a.profit > b.profit;
}
int main()
{
    int n, d;
    cin >> n >> d;
    for (int i = 0; i < n; ++i)
    {
        cin >> nodes[i].amount;
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> nodes[i].price;
        nodes[i].profit = nodes[i].price / nodes[i].amount;
    }
    sort(nodes, nodes + n, cmp);
    float ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (d > nodes[i].amount)
        {
            d -= nodes[i].amount;
            ans += nodes[i].price;
        }
        else
        {
            ans += d * nodes[i].profit;
            break;
        }
    }
    printf("%.2f", ans);
}