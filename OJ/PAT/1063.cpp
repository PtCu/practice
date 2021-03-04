#include <bits/stdc++.h>
using namespace std;

set<int> s[51];

float query(int a, int b)
{
    int cnt = 0;
    for (auto iter = s[a].begin(); iter != s[a].end(); ++iter)
    {
        if (s[b].count(*iter))
        {
            cnt++;
        }
    }
    return (float)cnt / (s[a].size() + s[b].size() - cnt);
}
int main()
{
    int n, m, x;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> m;
        for (int j = 0; j < m; ++j)
        {
            cin >> x;
            s[i].insert(x);
        }
    }
    int k, a, b;
    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        cin >> a >> b;
        float p = query(a, b) * 100;
        printf("%.1f%\n", p);
    }
}