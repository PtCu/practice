#include <bits/stdc++.h>
using namespace std;
string solve()
{
    string s;
    string rear;
    char c;
    int nums;
    while (cin >> c)
    {
        switch (c)
        {
        case '[':
            cin >> nums; //读取次数
            rear = solve();
            while (nums--)
            {
                s += rear;
            }
            break;
        case ']':
            return s;
            break;
        default:
            s += c;
            break;
        }
    }
}

int main()
{
    string s = solve();
    cout << s;
}