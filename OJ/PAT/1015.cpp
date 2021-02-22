#include <bits/stdc++.h>
using namespace std;
bool isPrime(int x)
{
    if (x < 2)
        return false;
    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}
string to_other(int x, int d)
{
    string ans;
    while (x)
    {
        ans.push_back(x % d + '0');
        x /= d;
    }
    return ans;
}
int to_ten(string x, int d)
{
    int ans = 0;
    for (int i = 0; i < x.size(); ++i)
    {
        ans += (x[i] - '0') * pow(d, x.size() - i - 1);
    }
    return ans;
}
int main()
{
    int n = 0, d;
    string other;
    int other_n;
    for (;;)
    {
        cin >> n;
        if (n < 0)
            break;
        cin >> d;
        other = to_other(n, d);
        other_n = to_ten(other, d);
        if (isPrime(other_n) && isPrime(n))
        {
            cout << "Yes" << endl;
        }
        else
            cout << "No" << endl;
    }
}