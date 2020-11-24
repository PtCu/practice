#include <bits/stdc++.h>
using namespace std;
struct Node
{
     int time, nation;
    Node(const  int &t, const int &n) : time(t), nation(n) {}
};
unordered_map< int,  int> n_num; //国籍，人数
queue<Node> Q;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    register int n, t, k, x;
    register int ans = 0;
    cin >> n;

    for (size_t i = 0; i < n; ++i)
    {
        cin >> t >> k;
        for (size_t j = 0; j < k; ++j)
        {
            cin >> x;
            if (!n_num.count(x))
            {
                ++ans;
                n_num[x] = 1;
            }
            else
            {
                ++n_num[x];
            }
            Q.push({t, x});
        }
        while (t - Q.front().time >= 86400)
        {
            --n_num[Q.front().nation];
            if (!n_num[Q.front().nation])
            {
                n_num.erase(Q.front().nation);
                ans--;
            }
            Q.pop();
        }
        cout << ans << endl;
    }
    return 0;
}
