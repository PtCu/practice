#include <bits/stdc++.h>
using namespace std;
//求一个最长单调不升子序列和一个最长单调上升子序列。
//lower_bound会找出序列中第一个大于等于x的数
//upper_bound会找出序列中第一个大于x的数

vector<int> source;
vector<int> desc;
vector<int> asc;
int main()
{
    int x;
    while (cin >> x)
    {
        source.push_back(x);
    }
    desc.push_back(source[0]);

    asc.push_back(source[0]);
    for (size_t i = 1; i < source.size(); ++i)
    {
        if (desc.back() >= source[i])
        {
            desc.push_back(source[i]); //如果不上升，就直接加入desc
        }
        else
        {
            //第一个小于source[i]的数
            auto p1 = upper_bound(desc.begin(), desc.end(), source[i], greater<int>());
            *p1 = source[i];
        }
        if (asc.back() < source[i])
        {
            asc.push_back(source[i]);
        }
        else
        {
            auto p2 = lower_bound(asc.begin(), asc.end(), source[i]);
            *p2 = source[i];
        }
    }

    cout << desc.size() << endl
         << asc.size() << endl;
    return 0;

    // int max_ans = -1;
    // for (size_t i = 1; i < source.size(); ++i)
    // {
    //     int max_s = -1;
    //     for (size_t j = 0; j < i; ++j)
    //     {
    //         if (source[j] >= source[i])
    //             max_s = max(max_s, desc[j]);
    //     }
    //     desc[i] = max_s + 1;
    //     max_ans = max(max_ans, desc[i]);
    // }
    // cout << max_ans;
}