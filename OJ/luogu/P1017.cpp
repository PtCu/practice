#include <bits/stdc++.h>
using namespace std;
void solve(int n, int r)
{
    if (!n)
        return;
    int m = n % r;
    //r<0
    if (m < 0)
        m -= r, n += r;
    if (m >= 10)
        m += 'A' - 10;
    else
        m += '0';
    solve(n / r, r);
    cout << (char)m; //余数倒序
    return;
}
int main()
{
    int n, r;
    cin >> n >> r;
    cout << n << "=";
    solve(n, r);
    cout<< "(base" << r << ")";
}