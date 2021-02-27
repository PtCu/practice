#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int sum[maxn];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> sum[i];
        sum[i] += sum[i - 1];
    }
    int cost = INT_MAX;
    for (int i = 1; i <= n; ++i)
    {
        int rank = lower_bound(sum + 1, sum + 1 + n, sum[i - 1] + m) - sum;
        //整个序列都不够
        if (rank == n + 1)
            break;
        if (sum[i - 1] + m == sum[rank])
        {
            cost = m;
            break;
        }
        cost = min(sum[rank] - sum[i - 1], cost);
    }
    for (int i = 1; i <= n; ++i)
    {
        int s = sum[i - 1] + cost;
        int j = lower_bound(sum + 1, sum + 1 + n, s) - sum;
        if (sum[j] == s)
        {
            cout << i << "-" << j << endl;
        }
    }
}