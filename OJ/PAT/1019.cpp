#include <bits/stdc++.h>
using namespace std;
vector<int> to_other(int x, int b)
{
    vector<int> ans;
    //x为0的情况
    do
    {
        ans.push_back(x % b);
        x /= b;
    } while (x);
    reverse(ans.begin(), ans.end());
    return ans;
}
bool isRev(vector<int> s)
{
    vector<int> s_ = s;
    reverse(s_.begin(), s_.end());
    return s_ == s;
}
int main()
{
    int n, b;
    cin >> n >> b;
    vector<int> s = to_other(n, b);
    if (isRev(s))
    {
        cout << "Yes" << endl;
    }
    else
        cout << "No" << endl;
    cout << s[0];
    for (int i = 1; i < s.size(); ++i)
    {
        cout << " " << s[i];
    }
}