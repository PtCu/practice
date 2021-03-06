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
        if (cnt % k || cnt == n)
        {
            reverse(vec.begin() + cnt - k, vec.begin() + cnt);
        }
        p = nodes[p].next;
    }
    for (int i = 0; i < vec.size();++i){
        
    }
    return 0;
}