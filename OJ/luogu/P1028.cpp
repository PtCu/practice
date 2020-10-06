#include<bits/stdc++.h>//万能头文件
using namespace std;
int  main(int argc, const char** argv) {
    int n;
    cin>>n;
    int f[1001]={1,1};
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i/2;j++){
            f[i]+=f[j];
        }
        f[i]++;
    }
    cout<<f[n];
    return 0;
}
