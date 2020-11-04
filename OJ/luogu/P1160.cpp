#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, p;
    cin >> n;
    list<int> L;
    L.push_back(1);
   
    for (int i = 2; i <= n; ++i)
    {
        cin >> k >> p;
        //插入k的右边
        if (p)
        {
            for (auto it = L.begin(); it != L.end(); ++it)
            {
                if (*it == k)
                {
                    ++it;
                    L.insert(it, i);
                    break;
                }
            }
        }
        //插入k的左边
        else
        {
            for (auto it = L.begin(); it != L.end(); ++it)
            {
                if (*it == k)
                {
                    L.insert(it, i);
                    break;
                }
            }
        }
    }

    int m, x;
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> x;
        for (auto it = L.begin(); it != L.end(); ++it)
        {
            if (*it == x)
            {
                L.erase(it);
                break;
            }
        }
    }

    for (auto it = L.begin(); it != L.end(); ++it)
    {
        cout << *it << " ";
    }
}