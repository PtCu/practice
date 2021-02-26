#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];
unordered_map<int, int> M;
int main()
{
    int n, x;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        M[a[i]]++;
    }
    for (int i = 0; i < n; ++i)
    {
        if (M[a[i]] == 1)
        {
            cout << a[i];
            return 0;
        }
    }
    cout << "None";
}