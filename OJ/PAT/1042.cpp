#include <bits/stdc++.h>
using namespace std;
vector<int> tf;
void transform(vector<int> &a)
{
    int b[55];
    for (int i = 0; i < tf.size(); ++i)
    {
        b[tf[i]] = a[i];
    }
    a.assign(b + 1, b + 55);
}
string output(int x)
{
    string ans;
    int t = (x - 1) / 13;
    if (t == 0)
    {
        ans.push_back('S');
    }
    else if (t == 1)
    {
        ans.push_back('H');
    }
    else if (t == 2)
    {
        ans.push_back('C');
    }
    else if (t == 3)
    {
        ans.push_back('D');
    }
    else if (t == 4)
    {
        ans.push_back('J');
    }
    int mod = x % 13;
    if (mod == 0)
        mod = 13;
    if (mod >= 10)
    {
        ans.push_back('1');
        ans.push_back(mod % 10 + '0');
    }
    else
    {
        ans.push_back(mod + '0');
    }

    return ans;
}
int main()
{
    int k, x;
    cin >> k;
    vector<int> a;
    for (int i = 1; i <= 54; ++i)
    {
        cin >> x;
        a.push_back(i);
        tf.push_back(x);
    }
    for (int i = 0; i < k; ++i)
    {
        transform(a);
    }
    cout << output(a[0]);
    for (int i = 1; i < 54; ++i)
    {
        cout <<" "<< output(a[i]) ;
    }
}