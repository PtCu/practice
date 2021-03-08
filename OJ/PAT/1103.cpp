#include <bits/stdc++.h>
using namespace std;
int n, p, k;
vector<int> powValue;
int maxFacSum = 0;
//算小于n的所有幂次为p的数
void init()
{
    powValue.push_back(0);
    while (powValue.back() < n)
    {
        powValue.push_back(pow(powValue.size(), p));
    }
}
vector<int> tmp, ans;
//start指向powValue的特定位置 dep深度 facSum因子之和 powSum指数之和
void dfs(int start, int dep, int facSum, int powSum)
{
    if (dep >= k || powSum >= n)
    {
        if (dep == k && powSum == n && facSum > maxFacSum)
        {
            maxFacSum = facSum;
            ans = tmp;
        }
        return;
    }
    if (start >= 1)
    {
        tmp.push_back(start);
        //powValue[start]即start的P次方
        dfs(start, dep + 1, facSum + start, powSum + powValue[start]);
        tmp.pop_back();
        //未选择当前的start 而是选择更小的数
        dfs(start - 1, dep, facSum, powSum);
    }
}
int main()
{
    cin >> n >> k >> p;
    init();
    dfs(powValue.size() - 1, 0, 0, 0); //从大到小开始选择
    if (ans.size() == k)
    {
        printf("%d = %d^%d", n, ans[0], p);
        for (int i = 1; i < ans.size(); i++)
            printf(" + %d^%d", ans[i], p);
    }
    else
        printf("Impossible");
    return 0;
}