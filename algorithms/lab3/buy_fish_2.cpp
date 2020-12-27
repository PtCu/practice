#include <iostream>
using namespace std;

const int MAXSIZE = 31;        // 鱼的最大种类数
int m, n;                      // 输入的钱数和鱼种类数
bool attack[MAXSIZE][MAXSIZE]; // 鱼之间的攻击性
int fish[MAXSIZE];             // 鱼的价格
int p[MAXSIZE];                // 买鱼的策略
int pbest[MAXSIZE];            // 买鱼的最佳策略
int cone, best;                // 买鱼的数目，最优数目
int sum, sumbest;              // 买鱼的花费，最优花费

void Solve(int t)
{
    bool bb;
    int i;
    p[t] = -1;
    do
    {
        p[t] = p[t] + 1;
        if (p[t] == 1)
        { // 买下这种鱼
            ++cone;
            sum += fish[t];
        }
        // 钱还有剩余
        if (sum <= m)
        {
            bb = true;
        }
        else
            bb = false;
        if (bb == true && p[t] == 1)
        {
            for (i = n; i > t; --i)
            {
                // 判断当前鱼与前面选择的是否互相攻击
                if (p[i] == 1 && attack[i][t] == true)
                {
                    bb = false;
                    break;
                }
            }
        }
        if (bb == true)
        {
            if (t == 1)
            { // 到最后一种鱼了
                if (cone > best || (cone == best && sum > sumbest))
                { // 找到一个更优解
                    best = cone;
                    sumbest = sum;
                    for (i = 1; i < MAXSIZE; ++i)
                    {
                        pbest[i] = p[i];
                    }
                }
            }
            else
            { // 继续向下搜索
                Solve(t - 1);
            }
        }

        if (p[t] == 1)
        { // 恢复到不买这种鱼的状态
            --cone;
            sum -= fish[t];
        }
    } while (p[t] != 1);
}

void Output()
{ // 输出最优解
    cout << best << "   " << sumbest << endl;
    for (int i = 1; i <= n; ++i)
    {
        if (pbest[i] == 1)
        {
            cout << i << endl;
        }
    }
}
int main()
{
    int i, nId, nPrice, s, t;
    cin >> m >> n;
    // 各种鱼的价格
    for (i = 0; i < n; ++i)
    {
        cin >> nId >> nPrice;
        fish[nId] = nPrice;
    }
    // 鱼之间互相攻击对方的关系
    while (cin >> s >> t && (s != 0 && t != 0))
    {
        attack[s][t] = true;
        attack[t][s] = true;
    }
    best = 0;    // 鱼的最优数目
    sumbest = 0; // 鱼的最优花费
    Solve(n);
    Output();
    system(" pause ");
    return 0;
}