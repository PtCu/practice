#include <bits/stdc++.h>
using namespace std;
int main()
{
    string source;
    cin >> source;
    int i = 0;
    long long a1 = 0, b1 = 0, a2 = 0, b2 = 0;
    int state = 0;
    bool isAdd = false;
    bool isFinish = false;
    while (i < source.size() && !isFinish)
    {
        if (state == 0)
        {
            while (source[i] != '/')
            {
                a1 = a1 * 10 + source[i] - '0';
                ++i;
            }
            state = 1;
            ++i; // 分数线
        }
        if (state == 1)
        {
            while (source[i] != '+' && source[i] != '-')
            {
                b1 = b1 * 10 + source[i] - '0';
                ++i;
            }
            state = 2;
            if (source[i] == '+')
                isAdd = true;
            else
                isAdd = false;
            ++i;
        }
        if (state == 2)
        {
            while (source[i] != '/')
            {
                a2 = a2 * 10 + source[i] - '0';
                ++i;
            }
            state = 3;
            ++i;
        }
        if (state == 3)
        {
            while (i < source.size() && source[i] != '+' && source[i] != '-')
            {
                b2 = b2 * 10 + source[i] - '0';
                ++i;
            }
            long long gcd = __gcd(b1, b2);
            a1 *= b2 / gcd;
            a2 *= b1 / gcd;
            if (isAdd)
                a1 += a2;
            else
                a1 -= a2;
            b1 *= b2 / gcd;
            long long gcd2 = __gcd(a1, b1);
            a1 /= gcd2;
            b1 /= gcd2;
            if (i == source.size())
            {
                isFinish == true;
                break;
            }
            state = 2;
            a2 = 0;
            b2 = 0;
            if (source[i] == '+')
                isAdd = true;
            else
                isAdd = false;
            ++i;
        }
    }
    if (b1 == 1)
        cout << a1;
    else if (b1 < 0)
    {
        b1 = -b1;
        a1 = -a1;
        cout << a1 << "/" << b1;
    }
    else
    {
        cout << a1 << "/" << b1;
    }
}