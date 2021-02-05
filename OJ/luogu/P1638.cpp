#include <bits/stdc++.h>
using namespace std;
struct node
{
    int val, num;
};
deque<node> Q;
unordered_map<int, int> M;
int main()
{
    int a, b;
    int n, m;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int ans = INT_MAX;
    node x;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x.val;
        x.num = i;
        Q.push_back(x);
        if (!M.count(x.val))
        {
            M[x.val] = 1;
        }
        else
        {
            M[x.val]++;
        }
        while (M.size() == m)
        {
            if (ans > Q.back().num - Q.front().num)
            {
                a = Q.front().num;
                b = Q.back().num;
                ans = Q.back().num - Q.front().num;
            }
            if (--M[Q.front().val] == 0)
            {
                M.erase(Q.front().val);
            }
            Q.pop_front();
        }
    }
    cout << a << " " << b;
}