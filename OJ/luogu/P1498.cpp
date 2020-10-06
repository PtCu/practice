#include<bits/stdc++.h>
using namespace std;
char a[1024][2048];
int main(){
    ios::sync_with_stdio(0); //取消cin,cout的缓存
    cin.tie(0);
    cout.tie(0);    //解绑
    int n;
    cin>>n;
    memset(a,' ',sizeof(a));
    a[0][0]=a[1][1]='/';
    a[0][1]=a[0][2]='_';
    a[0][3]=a[1][2]='\\';
    int t=1;
    int length=4;
    while(t<n){
        for(int i=0;i<length/2;i++){
            for(int j=0;j<length;j++){
                a[length/2+i][length/2+j]=a[i][j];
                a[i][length+j]=a[i][j];
            }
        }
        length*=2;
        t++;
    }
    for(int i=length/2-1;i>=0;i--){
        for(int j=0;j<=length;j++){
            cout<<a[i][j];
        }
        cout<<endl;
    }
}