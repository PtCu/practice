#include <bits/stdc++.h>
using namespace std;
unordered_map<long long, int> maps;
int main()
{
    int n, q;
    cin >> n >> q;
    int i, j, k;
    int x;
    while (q--)
    {
        cin >> x;
        if (x == 1)
        {
            cin >> i >> j >> k;
            maps[i * 1e5 + j] = k;
        }
        else if (x == 2)
        {
            cin >> i >> j;
            cout << maps[i * 1e5 + j]<<endl;
        }
    }
}