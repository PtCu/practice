//luogu 1241
#include <bits/stdc++.h>
using namespace std;
bool pat[200]; //匹配
//存索引更方便
int main()
{
    //存的是索引
    stack<size_t> S;
    string str;
    cin >> str;
    memset(pat, false, S.size());
    for (size_t i = 0; i < str.length(); ++i)
    {
        if (str[i] == ')')
        {
            if (S.empty())
                continue;
            if (str[S.top()]=='(')
            {
                pat[S.top()] = pat[i] = true;
                S.pop();
            }
        }
        else if (str[i] == ']')
        {
            if (S.empty())
                continue;
            if (str[S.top()]=='[')
            {
                pat[S.top()] = pat[i] = true;
                S.pop();
            }
        }
        else
        {
            S.push(i);
        }
    }

    for (size_t i = 0; i < str.length(); ++i)
    {
        if (pat[i])
        {
            cout << str[i];
        }
        else
        {
            if (str[i] == '(' || str[i] == ')')
                cout << "()";
            else
                cout << "[]";
        }
    }
}