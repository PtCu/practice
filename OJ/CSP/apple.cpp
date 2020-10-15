#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m; //棵树、操作轮数
    cin >> n >> m;
    int maxS = 0;
    int max_ = 0;
    int a;
    int max_to = 0;
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        int total;
        cin >> total;
        for (int j = 1; j <= m; j++)
        {
            cin >> a;
            sum -= a;
        }
        if (sum > max_to)
        {
            max_ = i;
            max_to = sum;
        }
        maxS += total - sum;
    }
    cout << maxS << " " << max_ << " " << max_to;
}