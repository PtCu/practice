#include <bits/stdc++.h>
using namespace std;
//朴素解法O(n^2)
int longestCommonSubsequence(string text1, string text2)
{
    int m = text1.length(); //行
    int n = text2.length(); //列

    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 0; i < m + 1; i++)
        dp[i][0] = 0;
    for (int i = 0; i < n + 1; i++)
        dp[0][i] = 0;

    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[m][n];
}