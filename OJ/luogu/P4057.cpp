#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main()
{
    long long a, b, c;
    cin >> a >> b >> c;
    long long gcd1 = __gcd(a, b);
    long long lcm1 = a * b / gcd1;
    long long gcd2 = __gcd(lcm1, c);
    long long lcm2 = lcm1 * c / gcd2;

    cout << lcm2;
}