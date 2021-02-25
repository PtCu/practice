#include <bits/stdc++.h>
using namespace std;
string to_others(int a, int radix)
{
    string ans;
    int x;
    do
    {
        x = a % radix;
        if (x >= 10)
            ans.push_back(x - 10 + 'A');
        else
            ans.push_back(x + '0');
        a /= radix;
    } while (a);
    if (ans.size() == 1)
        ans.push_back('0');
    reverse(ans.begin(), ans.end());

    return ans;
}
int main()
{
    int r, g, b;
    cin >> r >> g >> b;
    string R, G, B;
    R = to_others(r, 13);
    G = to_others(g, 13);
    B = to_others(b, 13);
    cout << "#" << R << G << B;
}