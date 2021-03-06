#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    float pre_sign;
    if (s[0] == '-')
        pre_sign = -1;
    else
        pre_sign = 1;
    float pos_sign;
    string pre, pos;
    for (int i = 1; i < s.size(); ++i)
    {
        if (s[i] == 'E')
        {
            pre.assign(s.begin() + 1, s.begin() + i);
            pre.erase(pre.begin() + 1);
            if (s[i + 1] == '-')
            {
                pos_sign = -1;
                pos.assign(s.begin() + i + 2, s.end());
            }
            else
            {
                pos_sign = 1;
                pos.assign(s.begin() + i + 1, s.end());
            }
        }
    }

    int pos_n;
    pos_n = abs(stoi(pos));
    if (pos_sign < 0)
    {
        if (pre_sign < 0)
            printf("-");
        printf("0.");
        for (int i = 0; i < pos_n - 1; ++i)
        {
            printf("0");
        }
        cout << pre;
        return 0;
    }
    else
    {
        if (pos_n > pre.size() - 1)
        {
            for (int i = pre.size() - 1; i < pos_n; ++i)
            {
                pre.push_back('0');
            }
            if (pre_sign < 0)
                printf("-");
            cout << pre;
            return 0;
        }
        else
        {
            if (pre.begin() + pos_n + 1 != pre.end())
            {
                pre.insert(pre.begin() + pos_n + 1, '.');
            }

            if (pre_sign < 0)
                printf("-");
            cout << pre;
            return 0;
        }
    }
    

    return 0;
}