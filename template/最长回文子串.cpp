//https://leetcode-cn.com/problems/longest-palindromic-substring/solution/zui-chang-hui-wen-zi-chuan-by-leetcode-solution/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
int dp[maxn][maxn]; //dp[i][j]为1表示[i,j]为回文串，否则不是
int main()
{
    string s, ans;
    cin >> s;
    int n = s.size();
    //l为子串长度
    for (int l = 0; l < n; ++l)
    {
        for (int i = 0; i + l < n; ++i)
        {
            int j = i + l;
            if (l == 0)
            {
                //单个字符一定是回文
                dp[i][j] = 1;
            }
            else if (l == 1)
            {
                //两个字符
                dp[i][j] = (s[i] == s[j]);
            }
            else
            {
                //当且仅当两端字符相等且中间部分为回文串时，此串为回文串
                dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
            }
            if (l + 1 > ans.size())
            {
                ans = s.substr(i, l + 1);
            }
        }
    }
    cout << ans;
}