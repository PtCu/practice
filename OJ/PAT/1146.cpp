#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
int indegree[maxn];
int tmp[maxn];
vector<int> G[maxn];
int n;
vector<int> source;
bool isValid()
{
    memcpy(tmp, indegree, sizeof(indegree));
    for (int i = 0; i < n; ++i)
    {
        if (tmp[source[i]] != 0)
        {
            return false;
        }
        for (int j = 0; j < G[source[i]].size(); ++j)
        {
            tmp[G[source[i]][j]]--;
        }
    }
    return true;
}
int ans[maxn];
int main()
{
    int m;
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        G[a].push_back(b);
        indegree[b]++;
    }
    int k, x;
    cin >> k;
    int cnt = 0;
    for (int i = 0; i < k; ++i)
    {
        source.clear();
        for (int j = 0; j < n; ++j)
        {
            cin >> x;
            source.push_back(x);
        }
        if (!isValid())
        {
            ans[cnt++] = i;
        }
    }
    cout << ans[0];
    for (int i = 1; i < cnt; ++i)
    {
        cout << " "<<ans[i] ;
    }
}