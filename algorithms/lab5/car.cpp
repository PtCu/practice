#include <bits/stdc++.h>
using namespace std;
int n, k, a, b, c;
const int maxn = 100;
const int INF = 1000000;
int matrix[9][9] = {
    {0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 1, 1, 0, 0},
    {1, 0, 1, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 1, 0, 0, 1, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 1, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0}};

//dp[i][j][0]表示从(1,1)到(i,j)所需最少费用
//dp[i][j][1]表示从(1,1)到(i,j)还能行驶的网格边数
/*
dp[i][j][0]=min（上下左右四个方向到达（i，j）的费用）
            = min{dp[ i+s[k][0] ] [ j+s[k][1] ][0] + d[k][2]}
dp[i][j][1] = dp[ i+d[k][0] ][ j+d[k][1] ][1] - 1
dp[1][1][0] = 0
dp[1][1][1] = K
dp[i][j][0] = dp[i][j][0] + A , dp[i][j][1] = K , (i, j)是油库
dp[i][j][0] = dp[i][j][0] + C + A, dp[i][j][1] = K , (i, j)不是油库，且dp[i][j][1] = 0
*/
int dp[maxn][maxn][2]; //状态

void solve()
{

    //d[i][0]表示x的下一个方向，d[i][1]表示y的下一个方向，d[i][2]表示花费的费用
    int d[4][3] = {{-1, 0, 0},
                   {0, -1, 0},
                   {1, 0, b},
                   {0, 1, b}};
    for (size_t i = 1; i <= n; ++i)
    {
        for (size_t j = 1; j <= n; ++j)
        {
            if (i == 1 && j == 1) //跳过起点
                continue;
            int minCost = dp[i][j][0]; //当前坐标的花费
            int minStep = dp[i][j][1]; //当前坐标还能行走的步数
            for (size_t h = 0; h < 4; ++h)
            {
                //超界
                if (i + d[h][0] < 1 || i + d[h][0] > n || j + d[h][1] < 1 || j + d[h][1] > n)
                    continue;
                int t1 = dp[i + d[h][0]][j + d[h][1]][0] + d[h][2]; //从(i+d[h][0],j+d[h][1])到(i,j)的代价
                int t2 = dp[i + d[h][0]][j + d[h][1]][1] - 1;       //从(i+d[h][0],j+d[h][1])到(i,j)的剩余油量（步数）
                if (matrix[i][j] == 1)                              //遇到加油站
                {
                    t1 += a;
                    t2 = k;
                }
                if (matrix[i][j] == 0 && t2 == 0 && (i != n || j != n)) //没油了
                {
                    //增设油库
                    t1 += a + c;
                    t2 = k;
                }
                if (minCost > t1)
                {
                    minCost = t1;
                    minStep = t2;
                    // isFinish = false;
                }
            }
            //更新dp
            if (dp[i][j][0] > minCost)
            {
                dp[i][j][0] = minCost;
                dp[i][j][1] = minStep;
            }
        }
    }
}
int main()
{

    cin >> n >> k >> a >> b >> c;
    for (size_t i = 1; i <= n; ++i)
    {
        for (size_t j = 1; j <= n; ++j)
        {
            dp[i][j][0] = INF; //代价
            dp[i][j][1] = k;   //油量
        }
    }
    dp[1][1][0] = 0;
    dp[1][1][1] = k;

    for (size_t i = 1; i <= n; ++i)
    {
        for (size_t j = 1; j <= n; ++j)
        {
            cin >> matrix[i][j];
        }
    }
    solve();
    cout << dp[n][n][0] << endl;
    return 0;
}