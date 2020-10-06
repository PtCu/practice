#include <bits/stdc++.h>
using namespace std;
int a[200000];
int main()
{
    ios::sync_with_stdio(0); //取消cin,cout的缓存
    cin.tie(0);
    cout.tie(0); //解绑
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int sum=0,ans=-10000;
    for(int i=0;i<n;i++){
       sum+=a[i];
       ans=max(ans,sum);
       if(sum<0) sum=0;
    }
    cout<<ans;
}