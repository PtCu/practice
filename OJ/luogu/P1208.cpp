#include <bits/stdc++.h>
using namespace std;
struct Farmer
{
    int cost;
    int quantity;
    Farmer(int c, int q) : cost(c), quantity(q) {}
    Farmer() {}
};
bool cmp(Farmer a, Farmer b)
{
    return a.cost < b.cost; //a<b时为true不交换，a>b时为false交换
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<Farmer> sources;
    int p, q;
    for (int i = 0; i < m; i++)
    {
        cin >> p >> q;
        sources.push_back(Farmer(p, q));
    }
    sort(sources.begin(), sources.end(), cmp);
    int sum = 0;
    for (int i = 0; i < m; i++)
    {

        if (n >= sources[i].quantity)
        {
            sum += sources[i].cost * sources[i].quantity;
            n -= sources[i].quantity;
        }
        else if (n >= 0)
        {
            sum += n * sources[i].cost;
            n = 0;
            break;
        }
    }
    cout << sum;
}