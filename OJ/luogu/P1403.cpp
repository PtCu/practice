#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, ans;
    cin >> n;
    ans = 0;
    for (int i = 1; i <= n;++i){
        ans += n / i;
    }
    cout << ans;
}