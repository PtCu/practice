#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4;
unordered_map<int, bool> M;
int main()
{
    int t;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        M.clear();
        int n, x;
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> x;
            if (!M.count(x))
            {
                cout << x << " ";
                M[x] = 1;
            }
        }
        cout << endl;
    }
}