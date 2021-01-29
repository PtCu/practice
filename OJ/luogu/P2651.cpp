#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
int a[maxn];
int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        for (int i = 1; i <= n;++i){
            cin >> a[i];
        }
        a[2] /= __gcd(a[1], a[2]);
        for (int i = 3; i <= n;++i){
            a[2] /= __gcd(a[2], a[i]);
        }
        if(a[2]==1)
            cout << "Yes" << endl;
        else{
            cout << "No" << endl;
        }
    }
    
}