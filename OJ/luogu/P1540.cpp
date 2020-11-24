#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, n, x, cnt = 0;
    cin >> m >> n;
    vector<int> source;
    for (size_t i = 0; i < n; ++i)
    {
        cin >> x;
        //没有找到
        if (find(source.begin(), source.end(), x) == source.end())
        {
            if (source.size() >= m)
                source.erase(source.begin());   
            source.push_back(x);
            ++cnt;
        }
    }
    cout << cnt;
}