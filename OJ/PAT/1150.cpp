#include <bits/stdc++.h>
using namespace std;
const int maxn = 220;
int G[maxn][maxn];
int n;
vector<int> source;
int min_dis = INT_MAX;
int min_k;
void query(int k)
{
    int type;
    unordered_set<int> S;
    bool reachable = true;
    int cur_dis = 0;
    S.insert(source[0]);
    string wo;

    for (int i = 1; i < source.size(); ++i)
    {
        if (G[source[i - 1]][source[i]] == 0)
            reachable = false;
        cur_dis += G[source[i - 1]][source[i]];
        S.insert(source[i]);
    }
    if (S.size() != n || source.back() != source.front()||!reachable)
    {
        type = -1;
        //不是TS
        wo = "(Not a TS cycle)";
    }
    else if (source.size() == n+1)
    {
        type = 1;
        //simple TS
        wo = "(TS simple cycle)";
    }
    else
    {
        type = 0;
        //TS
        wo = "(TS cycle)";
    }
    if (reachable)
    {
        cout << "Path " << k << ": " << cur_dis << " "
             << wo << endl;
        if (cur_dis < min_dis&&type!=-1)
        {
            min_dis = cur_dis;
            min_k = k;
        }
    }

    else
    {
        cout << "Path " << k << ": "
             << "NA"
             << " "
             << wo << endl;
    }
}
int main()
{
    int m;
    cin >> n >> m;
    int a, b, w;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b >> w;
        G[a][b] = G[b][a] = w;
    }
    int k, nu, x;
    cin >> k;
    for (int i = 1; i <= k; ++i)
    {
        cin >> nu;
        source.clear();
        for (int i = 0; i < nu; ++i)
        {
            cin >> x;
            source.push_back(x);
        }
        query(i);
    }
    cout << "Shortest Dist(" << min_k << ") = " << min_dis;
}