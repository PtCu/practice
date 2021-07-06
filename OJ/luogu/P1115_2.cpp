#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
int dp[maxn]; //dp[i]表示从1到i最大和
int main(){
    int n,x;
    cin >> n;
    int ans = -99999;
    for (int i = 1; i <= n;++i){
        cin >> x;
         //dp[i-1]不小于0 or 小于0
         //也就是去除负前缀的意思。
        dp[i] = max(dp[i - 1] + x, x);
        ans = max(dp[i], ans);
    }
    cout << ans;
}