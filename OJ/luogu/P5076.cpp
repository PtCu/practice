/*
iterator lower_bound( const T & val);	查找一个最大的位置 it，使得 [begin(), it) 中所有的元素者比 val 小
iterator upper_bound( const T & val);	查找一个最小的位置 it，使得 [it, end()) 中所有的元素都比 val 大
*/
#include <bits/stdc++.h>
using namespace std;
multiset<int> S;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int opt, x, n;
    multiset<int>::iterator it;
    S.insert(-2147483647);
    S.insert(2147483647);
    int cnt = 0;
    cin >> n;
    while (n--)
    {
        cin >> opt >> x;
        switch (opt)
        {
        case 1:
            /* code */
            it = S.lower_bound(x);
            cnt = 0;
            for (auto i = S.begin(); i != it; ++i)
                ++cnt;
            cout << cnt << endl;
            break;
        case 2:
            it = S.begin();
            it++;
            while (--x)
            {
                ++it;
            }
            cout << *it << endl;
            break;
        case 3:
            it = S.lower_bound(x);
            cout << *(--it) << endl;
            break;
        case 4:
            it = S.upper_bound(x);
            cout << *(it) << endl;
            break;
        case 5:
            S.insert(x);
            break;
        }
    }
}