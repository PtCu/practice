#include <bits/stdc++.h>
using namespace std;
vector<int> neg_coup, pos_coup, neg_pro, pos_pro;
int main()
{
    int n;
    cin >> n;
    int x;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        x > 0 ? pos_coup.push_back(x) : neg_coup.push_back(x);
    }
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        x > 0 ? pos_pro.push_back(x) : neg_pro.push_back(x);
    }
    sort(neg_coup.begin(), neg_coup.end());
    sort(pos_coup.begin(), pos_coup.end(), greater<int>());
    sort(neg_pro.begin(), neg_pro.end());
    sort(pos_pro.begin(), pos_pro.end(), greater<int>());
    int ans = 0;
    if (neg_coup.size() < neg_pro.size())
    {
        for (int i = 0; i < neg_coup.size(); ++i)
        {
            ans += neg_coup[i] * neg_pro[i];
        }
    }
    else
    {
        for (int i = 0; i < neg_pro.size(); ++i)
        {
            ans += neg_coup[i] * neg_pro[i];
        }
    }
    if (pos_coup.size() < pos_pro.size())
    {
        for (int i = 0; i < pos_coup.size(); ++i)
        {
            ans += pos_coup[i] * pos_pro[i];
        }
    }
    else
    {
        for (int i = 0; i < pos_pro.size(); ++i)
        {
            ans += pos_coup[i] * pos_pro[i];
        }
    }
    cout << ans;
}