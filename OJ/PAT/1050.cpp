#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
char s[maxn], a[maxn];
string str_a, str_s;
unordered_set<char> cst;
int main()
{
    getline(cin, str_s);
    getline(cin, str_a);
    for (int i = 0; i < str_a.size(); ++i)
    {
        cst.insert(str_a[i]);
    }
    for (int i = 0; i < str_s.size(); ++i)
    {
        if (!cst.count(str_s[i]))
            printf("%c", str_s[i]);
    }
}