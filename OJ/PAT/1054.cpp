#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> M;
int main()
{
    int m, n;
    cin >> m >> n;
    int x;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> x;
            M[x]++;
        }
    }
    int max_a = 0;
    int ans;
    for (auto iter = M.begin(); iter != M.end(); ++iter)
    {
        if (iter->second > max_a)
        {
            max_a = iter->second;
            ans = iter->first;
        }
    }
    cout << ans;
}