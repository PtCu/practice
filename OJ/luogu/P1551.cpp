#include <bits/stdc++.h>
using namespace std;
int f[10001];
int getFather(int x)
{
    if (f[x] == x)
        return x;
    else
    {
        f[x] = getFather(f[x]);
        return f[x];
    }
    
}
void Union(int x, int y)
{
    int p1 = getFather(x);
    int p2 = getFather(y);
    f[p2] = p1;
}

int main()
{
    int n, m, p;
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++)
        f[i] = i;
    int m1, m2;
    for (int i = 1; i <= m; i++)
    {
        cin >> m1 >> m2;
        Union(m1, m2);
    }
    int p1, p2;
    for (int i = 1; i <= p; i++)
    {
        cin >> p1>>p2;
        int f1=getFather(p1);
        int f2=getFather(p2);
        if (f1 == f2)
            cout << "Yes" << endl;
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}
