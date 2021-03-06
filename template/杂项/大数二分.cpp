//PAT 1010
//https://zhuanlan.zhihu.com/p/136807797
#include <bits/stdc++.h>
using namespace std;
string n1, n2;
long long ten_1, ten_2;
int tag, radix;
long long to_ten(string source, int radix)
{
    int n = source.size();
    long long ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (source[i] >= 'a' && source[i] <= 'z')
        {
            ans += (long long)(source[i] - 'a' + 10) * pow(radix, n - 1 - i);
        }
        else
            ans += (long long)(source[i] - '0') * pow(radix, n - 1 - i);
        if (ans < 0)
            return -1;
    }
    return ans;
}
int find_min(string &s)
{
    char c = *max_element(s.begin(), s.end());
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 11;
    if (c >= '0' && c <= '9')
        return c - '0' + 1;
}
long long binary(long long lo, long long hi)
{
    long long mi;
    long long ten_2;
    while (lo <= hi)
    {
        mi = (lo + hi) >> 1;
        ten_2 = to_ten(n2, mi);
        if (ten_1 == ten_2)
        {
            return mi;
        }
        else if (ten_2 == -1 || ten_2 > ten_1)
        {
            hi = mi - 1;
        }
        else
        {
            lo = mi + 1;
        }
    }
    return -1;
}
int main()
{

    cin >> n1 >> n2 >> tag >> radix;

    if (tag == 2)
    {
        n1.swap(n2);
    }
    ten_1 = to_ten(n1, radix);
    long long lo = find_min(n2);
    long long hi = ten_1 + 1;
    long long rad_2 = binary(lo, hi);
    if (rad_2 == -1)
        cout << "Impossible";
    else
        cout << rad_2;
    return 0;
}