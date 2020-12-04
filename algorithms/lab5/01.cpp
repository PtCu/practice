#include <bits/stdc++.h>
using namespace std;
struct Stuff
{
    int v, w;
    Stuff(){};
    Stuff(const int &_v, const int &_w) : v(_v), w(_w) {}
};
int C, M; //背包的容量C和物品数M
vector<Stuff> stuffs;

int dp[100][100]; //dp[i][j] 前i个物品中挑选总重量不超过j的物品，每种物品最多挑一个，使总价值最大
                  //考虑第i个物品，无非两种情况：1）不选。背包容量不变，改变为问题dp[i-1][j]
                  //2）选。这个物品价值为v[i]，背包容量变小为j-w[i]，然后再从剩余的i-1个物品里选，
                  //即剩余的价值为dp[i-1][j-w[i]]。改变为问题dp[i-1][j-w[i]]+v[i]
void solve()
{

    for (int i = 0; i <= M; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= C; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            if (j < stuffs[i].w) //包装不进去
                dp[i][j] = dp[i - 1][j];
            else //能装进去的情况下看是装进去价值大还是不装
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stuffs[i].w] + stuffs[i].v);
        }
    }
    cout << dp[M][C];
}
int main()
{
    cout << "请输入背包容量和物品数目" << endl;
    cin >> C >> M;
    cout << "输入物品的重量、价值" << endl;
    stuffs.push_back({0, 0});
    int v, w;
    for (int i = 0; i < M; i++)
    {
        cin >> w >> v;
        stuffs.push_back(Stuff(v, w));
    }
    cout << "最大价值为" << endl;
    solve();
}