#include <bits/stdc++.h>
using namespace std;
double a[3];
char s[3] = {'W', 'T', 'L'};
int main()
{
    double ans = 1.0;
    int idx;
    for (int i = 0; i < 3; ++i)
    {
        cin >> a[0] >> a[1] >> a[2];
        idx = (max_element(a, a + 3) - a);
        ans *= a[idx];
        cout << s[idx]<<" ";
    }
    cout << setiosflags(ios::fixed) << setprecision(2) << (ans * 0.65 - 1) * 2;
}