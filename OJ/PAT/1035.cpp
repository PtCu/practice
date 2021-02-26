#include <bits/stdc++.h>
using namespace std;
bool solve(string &s)
{
    bool flag = false;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '1')
        {
            s[i] = '@';
            flag = 1;
        }
        else if (s[i] == '0')
        {
            s[i] = '%';
            flag = 1;
        }
        else if (s[i] == 'l')
        {
            s[i] = 'L';
            flag = 1;
        }
        else if (s[i] == 'O')
        {
            s[i] = 'o';
            flag = 1;
        }
    }
    return flag;
}
pair<string, string> ans[1010];
int main()
{
    int n;
    cin >> n;
    string acct, pwd;
    bool flag = false;
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> acct >> pwd;
        flag = solve(pwd);
        if (flag)
        {
            ans[++cnt] = make_pair(acct, pwd);
        }
    }
    if (flag)
    {
        cout << cnt << endl;
        for (int i = 1; i <= cnt; ++i)
        {
            cout << ans[i].first << " " << ans[i].second << endl;
        }
    }
    else if (n != 1)
    {
        cout << "There are " << n << " accounts and no account is modified";
    }
    else 
    {
        cout << "There is 1 account and no account is modified";
    }
    return 0;
}