#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
string a[maxn];
bool cmp(const string &a, const string &b)
{
    return a + b < b + a; //拼接后字典序较小的字符串的第一个子字符串排在前面
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n;++i){
        cin >> a[i];
    }
    sort(a, a + n, cmp);
    string ans;
    for (int i = 0; i < n;++i){
        ans += a[i];
    }
    while (ans[0]=='0')
    {
        ans.erase(ans.begin());
    }
    if(ans.size()>0){
        cout << ans;
    }
    else{
        cout << "0";
    }
    
}