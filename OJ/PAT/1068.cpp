#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
const int maxm = 110;
int a[maxn];
int dp[maxn][maxm]; //前i个物体放入容量为j的背包
bool marked[maxn][maxm];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n, greater<int>());
    for (int i = 1; i <= n; ++i)
    {
        for (int j = a[i]; j <= m; ++j)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i]] + a[i]);
            if (dp[i - 1][j - a[i]] + a[i] >= dp[i - 1][j])
            {
                marked[i][j] = true;
            }
        }
    }
    if (dp[n][m] != m)
    {
        cout << "No Solution";
        return 0;
    }
    int left = m;
    vector<int> ans;
    for (int i = n; i >= 0; --i)
    {
        if (marked[i][left])
        {
            ans.push_back(a[i]);
            left -= a[i];
        }
    }
    cout << ans[0];
    for (int i = 1; i < ans.size(); i++)
        cout << " " << ans[i];
}