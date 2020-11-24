#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    queue<int> Q;
    for (int i = 1; i <= n; ++i)
    {
        Q.emplace(i);
    }
    int out = 0;
    int cur = 0;
    //模拟环：报完数的就去队尾
    while (!Q.empty())
    {
        if (++cur == m)
        {
            cout << Q.front() << " ";
            Q.pop();
            cur = 0;
        }
        else
        {
            Q.push(Q.front());
            Q.pop();
        }
    }
}