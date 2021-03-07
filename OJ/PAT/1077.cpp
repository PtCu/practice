#include <bits/stdc++.h>
using namespace std;
string lines[110];
int main()
{
    int n;
    cin >> n;
    string air;
    getline(cin, air);
    for (int i = 1; i <= n; ++i)
    {
        getline(cin, lines[i]);
    }
    sort(lines + 1, lines + n, [](string a, string b) { return a.size() < b.size(); });
    string ans;
    bool exist = false;
    for (int j = lines[1].size() - 1; j >= 0; --j)
    {
        char cur = lines[1][j];
        bool isOk = true;
        for (int i = 2; i <= n; ++i)
        {
            if (cur == lines[i].back())
            {
                lines[i].erase(prev(lines[i].end()));
            }
            else
            {
                isOk = false;
                break;
            }
        }
        if (isOk)
        {
            exist = true;
            ans.push_back(cur);
            lines[1].erase(prev(lines[1].end()));
        }
    }
    if (exist)
    {
        reverse(ans.begin(), ans.end());
        cout << ans;
    }
    else{
        cout << "nai";
    }
}