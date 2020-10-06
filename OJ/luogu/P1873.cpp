#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n, need;
    cin >> n >> need;
    vector<ll> source;
    ll maxLength = 0;
    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        source.push_back(a);
        maxLength = max(maxLength, a);
    }
    ll l = 0;
    ll r = maxLength;
    while (l <= r)
    {
        ll m = (l + r) / 2;
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (source[i] > m)
            {
                sum += (source[i] - m);
            }
        }
        if (sum < need)
        {
             r = m -1;
            
        }
        else if(sum>=need)  //最后必须保障sum>=need
        {
           l = m + 1;
        }
       
    }
    cout << l-1;
}