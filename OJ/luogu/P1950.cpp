#include <bits/stdc++.h>
using namespace std;
int h[1020];
stack<int> s;
int d[1020][1020];
int l[1020], r[1020];
long long ans;
int main()
{
    int n, m;
    char a;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> a;
            if (a == '*')
                d[i][j] = 1;
        }
    }
    //对每一行
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            h[j]++;
            if (d[i][j])
                h[j] = 0;
        }

        //找l
        stack<int>().swap(s);
        for (int j = m; j >= 1; j--)
        {
            while (!s.empty() && h[j] <= h[s.top()]) //单调栈，找到j向左最小的数
            {
                l[s.top()] = j;
                s.pop();
            }
            s.push(j);
        }
        while (!s.empty())
        {
            l[s.top()] = 0;
            s.pop();
        }

        //找r
        stack<int>().swap(s);
        for (int j = 1; j <= m; j++)
        {
            while (!s.empty() && h[j] < h[s.top()]) //单调栈，找到j向右最小的数
            {
                r[s.top()] = j;
                s.pop();
            }
            s.push(j);
        }
        while (!s.empty())
        {
            r[s.top()] = m+1;
            s.pop();
        }


        for (int j = 1; j <= m; ++j)
        {
            ans += (j - l[j]) * (r[j] - j) * h[j];
        }
    }
    cout << ans;
}