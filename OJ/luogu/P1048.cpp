#include <bits/stdc++.h>
using namespace std;
const int maxT = 1000 + 5;
const int maxn = 100 + 5;
struct Herb
{
    int val;
    int cost;
    Herb(int c, int v) : val(v), cost(c) {}
};
int T, M;
//maxn最大物品数目，maxT最大容量
int dp[maxn][maxT]; //dp[i][j] 前i个物品中挑选总重量不超过j的物品，每种物品最多挑一个，使总价值最大
                    //考虑第i个物品，无非两种情况：1）不选。背包容量不变，改变为问题dp[i-1][j]
                    //2）选。这个物品价值为v[i]，背包容量变小为j-w[i]，然后再从剩余的i-1个物品里选，
                    //即剩余的价值为dp[i-1][j-w[i]]。改变为问题dp[i-1][j-w[i]]+v[i]
int main()
{
    cin >> T >> M;
    vector<Herb> herbs;
    herbs.push_back(Herb(0, 0));
    for (int i = 0; i < M; i++)
    {
        int v, c;
        cin >> c >> v;
        herbs.push_back(Herb(c, v));
    }
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= T; j++)
        {

            j >= herbs[i].cost ? dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - herbs[i].cost] + herbs[i].val) : dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[M][T];
}