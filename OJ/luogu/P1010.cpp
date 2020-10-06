#include <bits/stdc++.h> //万能头文件
using namespace std;
// string recur(int x,int i,string s){
//     if(x==0)
//     return "0";
//     while(x){
//         if(x&1){    //判断最后一位是不是1
//             s=(i==1?"2":"2("+recur(i,0,"")+")")+(s==""?"":"+")+s;     //2(1)写作2，所以指数i=1时特殊处理
//         }
//         x>>=1;
//         ++i;
//     }
//     return s;

// }

// int main(int argc, char const *argv[])
// {
//     int x;
//     cin >> x;
//     cout<<recur(x,0,"")<<endl;
//     return 0;
// }

void recur(int n){
    if(n==0) return;
    double acV=log2(n);
    int max=(int)acV;
    if(max==0) cout<<"2(0)";
    else if(max==1)cout<<"2";
    else if(max>1){
        cout<<"2(";
        recur(max);
        cout<<")";
    }
    if(acV!=max){
        cout<<"+";
        int remain=1<<max;
        recur(n-remain);
    }
}
int main(){
    int n; cin>>n;
    recur(n);
}
