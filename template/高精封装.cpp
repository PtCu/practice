#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn = 1e4;

struct BigN

{
    int len, a[maxn];
    string s;
    BigN(){};
    void clear()
    {
        memset(a, 0, sizeof(a));
        s.clear();
        len = 0;
    }
    void read()
    {
        cin >> s;
        for (int i = 0; i < s.size(); ++i)
        {
            a[s.size() - i - 1] = s[i] - '0';
        }
        len = s.size();
    }
    void print()
    {
        int i;
        for (i = len - 1; i >= 1; --i)
        {
            if (a[i])
                break;
        }
        for (; i >= 0; --i)
        {
            putchar(a[i] + '0');
        }
    }
    BigN operator*(int b)
    {
        BigN c;
        int c_len;
        int carry = 0;
        int temp = 0;
        for (int i = 0; i < len; ++i)
        {
            temp = b * a[i] + carry;
            c.a[c_len++] = temp % 10;
            carry = temp / 10;
        }
        while (carry)
        {
            c.a[c_len++] = carry % 10;
            carry /= 10;
        }
        return c;
    }
        BigN operator+(const BigN &e)
    {
        BigN c;
        int carry = 0;
        int temp = 0;
        int i;
        for (int i = 0; i <= len - 1 || i <= e.len - 1; ++i)
        {
            temp = e.a[i] + a[i] + carry;
            c.a[c.len++] = temp % 10;
            carry = temp / 10;
        }
        if (carry)
        {
            c.a[c.len++] = carry;
        }
        // while (carry)
        // {
        //     c.a[c.len++] = carry % 10;
        //     carry /= 10;
        // }

        return c;
    }
};