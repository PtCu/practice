#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
struct Node
{
    int add, data, next;
} nodes[maxn];
int main()
{
    int start, n, k;
    cin >> start >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        nodes[x].add = x;
        cin >> nodes[x].data >> nodes[x].next;
    }
    int p = start;
    vector<Node> vec;
    int cnt = 0;
    while (p != -1)
    {
        vec.push_back(nodes[p]);
        ++cnt;
        if (cnt % k == 0)
        {
            reverse(vec.begin() + cnt - k, vec.begin() + cnt);
        }
        // else if (cnt == n)
        // {
        //     reverse(vec.end() - cnt % k, vec.end());
        // }
        p = nodes[p].next;
    }
    cout << setw(5) << setfill('0') << vec[0].add << " " << vec[0].data << " ";
    for (int i = 1; i < vec.size(); ++i)
    {
        cout << setw(5) << setfill('0')
             << vec[i].add << endl
             << setw(5) << setfill('0')
             << vec[i].add << " " << vec[i].data << " ";
    }
    cout << -1;
    return 0;
}