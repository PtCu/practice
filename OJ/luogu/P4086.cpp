#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];
int k[maxn];
int sum;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    int min_n = a[n];
    sum = a[n];
    float ans = 0;
    int cnt = 0;
    for (int i = n - 1; i >= 2; --i)
    {
        sum += a[i];
        min_n = min(a[i], min_n);
        if ((float)(sum - min_n) / (n - i) > ans)
        {
            cnt = 1;
            k[cnt] = i - 1;
            ans = (float)(sum - min_n) / (n - i);
        }
        else if ((float)(sum - min_n) / (n - i) == ans)
        {
            k[++cnt] = i - 1;
        }
    }
    for (int i = cnt; i >= 1; --i)
    {
        cout << k[i] << endl;
    }
}