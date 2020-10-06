#include <bits/stdc++.h>
using namespace std;
const int XN = 1e4 + 10;
int cost[XN];
int res;
vector<int> G[XN];
int inDegree[XN];
int ansForEachNode[XN];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int id, pre;
        cin >> id >> cost[id];
        while (cin >> pre)
        {
            if (pre == 0)
                break;
            inDegree[id]++;
            G[pre].push_back(id);
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
            ansForEachNode[i] = cost[i];
        }
    }
    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        for (int i = 0; i < G[p].size(); i++)
        {
                inDegree[G[p][i]]--;
                if (inDegree[G[p][i]] == 0)
                    q.push(G[p][i]);
                ansForEachNode[G[p][i]] = max(ansForEachNode[G[p][i]], ansForEachNode[p] + cost[G[p][i]]);
                res = max(res, ansForEachNode[G[p][i]]);
            
        }
    }
    cout << res;
}