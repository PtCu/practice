#include <bits/stdc++.h>
using namespace std;
const int maxn = 30;
unsigned long long c[maxn][maxn];
void preProc()
{
    c[0][0] = c[1][0] = c[1][1] = 1;
    for (int i = 2; i <= maxn; ++i)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j)
        {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }
}
int main()
{
    string s;
    cin >> s;
    int ans = 0;
    preProc();
    for (int i = 1; i < s.size(); ++i)
    {
        if (s[i] <= s[i - 1])
        {
            cout << 0;
            exit(0);
        }
    }
    for (int i = 1; i < s.size(); ++i)
    {
        ans += c[26][i]; //计算出位数比它小的单词数
    }
    //计算位数和s相等的情况
    for (int i = 0; i < s.size(); ++i) //枚举每一位
    {

        for (char j = (i == 0 ? 'a' : s[i - 1] + 1); j < s[i]; ++j)
        {
            ans += c['z' - j][s.size() - i - 1]; //因为字符串下标从0开始，所以是n-i-1而不是n-i
        }
    }

    cout << ++ans;
    return 0;
}