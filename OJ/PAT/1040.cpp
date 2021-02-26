#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
int dp[maxn][maxn];
int main()
{
    string s;
    getline(cin, s);
    int n = s.size();
    string ans;
    for (int l = 0; l < n; ++l)
    {
        for (int i = 0; i + l < n; ++i)
        {
            int j = i + l;
            if (l == 0)
            {
                dp[i][j] = 1;
            }
            else if (l == 1)
            {
                dp[i][j] = (s[i] == s[j]);
            }
            else
            {
                dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
            }
            if (dp[i][j] && l + 1 > ans.size())
            {
                ans = s.substr(i, l + 1);
            }
        }
    }
    cout << ans.size();
}