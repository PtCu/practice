//P1950
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
        //首先定义一个栈（先进后出）栈中存的是目前还没有答案的数，，
        //对于每一次要将元素压入栈，先将栈顶所有大于它的元素记录答案（就是要压入的元素）并弹出，
        //因为我们要求左边第一个，所以以从右向左的顺序入栈（因为是先入栈再记录答案，所以要从元素从答案入栈）
        stack<int>().swap(s);
        for (int j = m; j >= 1; j--)
        {
            //单调栈，找到j左边第一个小于h[j]的数并记录
            //当前的小于顶端的时便直接记录答案
            while (!s.empty() && h[j] <= h[s.top()]) 
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