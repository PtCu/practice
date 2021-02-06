#include <bits/stdc++.h>
using namespace std;
deque<int> Q;
const int maxn = 1e5+10;
double a[maxn], sum[maxn];
double L, R;
int n;
int s, t;
bool check(double x)
{
    sum[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        sum[i] = sum[i - 1] + a[i] - x;
    }
    Q.clear();
    for (int i = s; i <= n; ++i)
    {
        while (!Q.empty() && sum[i - s] < sum[Q.back()]) //保证前缀和单调递增
        {
            Q.pop_back();
        }
        Q.push_back(i - s);
        while (!Q.empty() && Q.front() < i - t)
        {
            Q.pop_front();
        }
        if (sum[i] - sum[Q.front()] >= 0)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s >> t;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    R = *max_element(a + 1, a + n + 1);
    L = *min_element(a + 1, a + 1 + n);
    double mid, ans;
    while (R - L > 1e-5)
    {
        mid = (R + L) / 2;
        if (check(mid))
        {
            L = ans = mid;
        }
        else
            R = mid;
    }
    printf("%.3lf", ans);
}