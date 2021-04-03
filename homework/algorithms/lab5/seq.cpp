#include <bits/stdc++.h>
using namespace std;
int main()
{
    //判断S_是否为S的子序列
    cout << "输入原序列和子序列" << endl;
    string S, S_;
    cin >> S >> S_;
    size_t i = 0, j = 0;
    while (i < S.size() && j < S_.size())
    {
        if (S[i] == S_[j])
        {
            j++;
        }
        i++;
    }
    if (j == S_.size())
        cout << "是子序列" << endl;
    else
        cout << "不是" << endl;
}