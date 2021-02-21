#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b;
    c = a + b;
    int l;
    string s = to_string(c);
    if (c < 0)
    {
        l = s.size() - 1;
    }
    else
    {
        l = s.size();
    }
    string ans;
    for (int i = s.size() - 1, j = 1; l >= 1; i--, j++,l--)
    {
        if ((j - 1) % 3 == 0&&j!=1)
            ans.push_back(',');
        ans.push_back(s[i]);
    }
    if(c<0)
        ans.push_back('-');
    for (int i = ans.size() - 1; i >= 0;i--){
        cout << ans[i];
    }
}