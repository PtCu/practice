#include <bits/stdc++.h>
using namespace std;
const int maxn = 50;
unordered_map<int, int> A, B;
struct BigN
{
    int len, a[maxn];
    string s;
    BigN() { clear(); };
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
        for (int i = len - 1; i >= 0; --i)
        {
            putchar(a[i] + '0');
        }
    }
    BigN operator*(int b)
    {
        BigN c;
        int c_len = 0;
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
        c.len = c_len;
        return c;
    }
};
void breakDown(BigN a, unordered_map<int, int> &A)
{
    for (int i = 0; i < a.len; ++i)
    {
        A[a.a[i]]++;
    }
}
int main()
{
    BigN a, b;
    a.read();
    b = a * 2;
    breakDown(a, A);
    breakDown(b, B);
    bool flag = true;
    if(A.size()!=B.size())
        flag = false;
    for (auto iter = A.begin(); iter != A.end(); ++iter)
    {
        if (iter->second != B[iter->first])
        {
            flag = false;
            break;
        }
    }
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    b.print();
}
