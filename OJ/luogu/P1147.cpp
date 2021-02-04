#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, k1, k2;
    cin >> m;
    for (k1 = sqrt(2 * m); k1 > 1; --k1)
    {
        if (2 * m % k1 == 0 && (k1 + 2 * m / k1) % 2)
        {
            k2 = 2 * m / k1;
            cout << (k2 - k1 + 1) / 2 <<" " << (k1 + k2 - 1) / 2 << endl;
        }
    }
}