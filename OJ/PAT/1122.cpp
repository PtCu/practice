#include <bits/stdc++.h>
using namespace std;
const int maxn = 120;
bool G[maxn][maxn];
vector<int> nodes;
int n, m;
unordered_set<int> S;
bool isValid()
{
    if (nodes.size() != n + 1)
        return false;
    int cur = nodes[0];
    if (cur != nodes.back())
        return false;
    S.clear();
    for (int i = 1; i < nodes.size(); ++i)
    {
        if (!G[cur][nodes[i]])
            return false;
        S.insert(cur);
        cur = nodes[i];
    }
    if (S.size() != n)
        return false;
    return true;
}
int main()
{

    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        G[a][b] = 1;
        G[b][a] = 1;
    }
    int k;
    cin >> k;
    int kn, x;
    for (int i = 0; i < k; ++i)
    {
        cin >> kn;
        nodes.clear();
        for (int j = 0; j < kn; ++j)
        {
            cin >> x;
            nodes.push_back(x);
        }
        if (isValid())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}