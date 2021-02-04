#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
struct node
{
    int val;
    int num;
};
deque<node> Q;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    node x;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x.val;
        x.num = i;
        while (!Q.empty() && x.val > Q.back().val)
        {
            Q.pop_back();
        }
        Q.push_back(x);
        while (i - Q.front().num >= k)
        {
            Q.pop_front();
        }

        if (i >= k)
        {
            cout << Q.front().val << endl;
        }
    }
}