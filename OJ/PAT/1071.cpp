#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> M;
bool isValid(char c)
{
    return '0' <= c && c <= '9' || 'a' <= c && c <= 'z' || 'A' <= c && c <= 'Z';
}
void toLower(char &c)
{
    if (c <= 'Z' && c >= 'A')
    {
        c = c - 'A' + 'a';
    }
}
int main()
{
    string total;
    getline(cin, total);
    string s;
    for (int i = 0; i < total.size(); ++i)
    {
        if (isValid(total[i]))
        {
            toLower(total[i]);
            s.push_back(total[i]);
        }
        else
        {
            if (!s.empty())
            {
                M[s]++;
                s.clear();
            }
        }
    }
    if (!s.empty())
    {
        M[s]++;
        s.clear();
    }
    string ans;
    int max_times = 0;
    for (auto iter = M.begin(); iter != M.end(); ++iter)
    {
        if (iter->second > max_times)
        {
            max_times = iter->second;
            ans = iter->first;
        }
    }
    cout << ans << " " << max_times;
    return 0;
}