//有n 个物品，它们有各自的重量和价值，现有给定容量的背包，如何让背包里装入的物品具有最大的价值总和？
#include <bits/stdc++.h>
using namespace std;
int const number = 10, capacity = 20;
vector<int> w = {1, 2, 3, 4, 5, 6, 1, 2, 3, 4}; //重量
vector<int> v = {2, 4, 6, 7, 1, 4, 6, 7, 8, 2}; //价值
vector<int> n = {3, 3, 4, 5, 6, 7, 3, 2, 4, 2}; //数量

void zeroOnePacksack()
{

    int dp[100][100]; //dp[i][j] 前i个物品中挑选总重量不超过j的物品，每种物品最多挑一个，使总价值最大
                      //考虑第i个物品，无非两种情况：1）不选。背包容量不变，改变为问题dp[i-1][j]
                      //2）选。这个物品价值为v[i]，背包容量变小为j-w[i]，然后再从剩余的i-1个物品里选，
                      //即剩余的价值为dp[i-1][j-w[i]]。改变为问题dp[i-1][j-w[i]]+v[i]
    for (int i = 0; i <= number; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= capacity; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= number; i++)
    {
        for (int j = 1; j <= capacity; j++)
        {
            if (j < w[i]) //包装不进去
                dp[i][j] = dp[i - 1][j];
            else //能装进去的情况下看是装进去价值大还是不装
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
        }
    }
    cout << dp[number][capacity];
}
//可以优化为一维数组。每次计算dp[i][j]时只用到了dp[i-1][j]和dp[i-1][j-w[i]]

//优化：从代码和状态转移公式都能看出来当前层的状态只与上一层状态有关，可以优化dp二维列表f为一维列表，
//从后往前更新确保更新第i层用的是第i-1层的状态值。
void zeroOnePacksack()
{
    int dp[100]; //dp[j]表示总容量为j时从前i个物体挑选所得的价值

    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= number; i++)
    {
        //一维数组后面的值需要前面的值进行运算再改动，
        //如果正序遍历，则前面的值将有可能被修改掉从而造成后面数据的错误；
        //相反如果逆序遍历，先修改后面的数据再修改前面的数据，此种情况就不会出错了
        for (int j = capacity; j >= w[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]); //max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
        }
    }
    cout << dp[capacity];
}
//完全背包朴素解法（必超时）
void completePacksack()
{
    int dp[100][100];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= number; i++)
    { //物品种类
        for (int j = 1; j <= capacity; j++)
        { //背包容量
            for (int k = 0; k * w[i] <= j; k++)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - k * w[i]] + k*v[i]);
        }
    }
    cout << dp[capacity];
}

//完全背包（时间优化）
//和01背包的区别是j顺着做就行
void completePacksack_opt_t()
{
    int dp[100][100];
    memset(dp, 0, sizeof(dp));
    for (size_t i = 1; i <= number; ++i)
    {
        for (size_t j = w[i]; j <= capacity; j++)
        {
            if (j >= w[i])
                dp[i][j] = max(dp[i - 1][j], dp[i][j - w[i]] + v[i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
}
//空间、时间优化版本
//i=1时，计算只放第一件物品的最大价值
//i=2时，计算加上第二件物品的最大价值（在只放第一件物品的前提下）
//dp[v]表示容量为v在前i种背包时所得的价值，这里我们要添加的不是前一个背包，而是当前背包，所以要考虑的是当前状态。
//直接把上面那个的第一维去掉就行
void completePacksack_opt()
{
    int dp[100];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= number; i++)
    {
        for (int j = w[i]; j <= capacity; j++)
        {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
}

//多重背包, 最多M[i]个
//朴素版
void multiPacksack(int M[])
{
    int dp[100][100];
    for (size_t i = 1; i <= number; ++i)
    {
        for (size_t j = 1; j <= capacity; ++j)
        {
            for (int k = 0; k <= M[i]; ++k)
            {
                if (j >= k * w[i])
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - w[i] * k] + k * v[i]);
                }
            }
        }
    }
}


//可以用二进制优化

int main(int argc, char const *argv[])
{
    zeroOnePacksack();
    cout << endl;
    zeroOnePacksack();
    return 0;
}
