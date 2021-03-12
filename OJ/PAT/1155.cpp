#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
int a[maxn];
vector<int> v;
int n;
void dfs(int x)
{
    if (2 * x + 1 > n && 2 * x > n)
    {
        if (x <= n)
        {
            cout << v[0];
            for (int i = 1; i < v.size(); ++i)
            {
                cout << " " << v[i];
            }
            cout << endl;
        }
        return;
    }
    v.push_back(a[2 * x + 1]);
    dfs(2 * x + 1);
    v.pop_back();
    v.push_back(a[2 * x]);
    dfs(2 * x);
    v.pop_back();
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    v.push_back(a[1]);
    dfs(1);
    bool max = 1, min = 1;
    for (int i = 1; i < n / 2; ++i)
    {
        if (a[i] > a[2 * i + 1] || a[i] > a[2 * i])
            min = false;
        if (a[i] < a[2 * i + 1] || a[i] < a[2 * i])
            max = false;
    }
    if (max)
        cout << "Max Heap" << endl;
    else if (min)
        cout << "Min Heap" << endl;
    else
        cout << "Not Heap" << endl;
}