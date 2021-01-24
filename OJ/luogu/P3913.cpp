#include <bits/stdc++.h>
using namespace std;
unordered_set<int> x, y;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n, k;
    cin >> n >> k;

    int r, c;
    for (int i = 1; i <= k; ++i)
    {
        cin >> r >> c;
        x.insert(r);
        y.insert(c);
    }
    cout << n * n - (n - x.size()) * (n - y.size());
}