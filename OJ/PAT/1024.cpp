#include <bits/stdc++.h>
using namespace std;
const int maxn = 200;
struct BigN
{
    int a[maxn];
    string s;
    int len;
    BigN() { clear(); }
    void read()
    {
        cin >> s;
        int n = s.size();
        for (int i = 0; i < n; ++i)
        {
            a[n - i - 1] = s[i] - '0';
        }
        len = n;
    }
    void clear()
    {
        memset(a, 0, sizeof(a));
        s.clear();
        len = 0;
    }
    void print()
    {
        for (int i = len - 1; i >= 0; i--)
        {
            putchar('0' + a[i]);
        }
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
bool isOk(BigN x)
{
    bool flag = true;
    for (int i = 0; i < x.len / 2; ++i)
    {
        if (x.a[i] != x.a[x.len - i - 1])
        {
            flag = false;
            break;
        }
    }
    return flag;
}
BigN revN(BigN x)
{
    BigN ans = x;
    reverse(ans.a, ans.a + x.len);
    return ans;
}
int main()
{
    int k;
    BigN n;
    n.read();
    cin >> k;
    int step = 0;
    while (!isOk(n))
    {
        if (step == k)
            break;
        BigN b = revN(n);
        n = n + b;
        step++;
    }
    n.print();
    cout << endl;
    cout << step;
}