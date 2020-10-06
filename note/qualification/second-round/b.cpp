#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
#define Inf 1e9
const int maxn=1500000;
int n,Q;
int a[maxn];
int Gcd(int x,int y){
    if(x==0) return y;
    if(y==0) return x;
    int r=x%y;
    while(r){
        x=y;y=r;r=x%y;
    }
    return y;
}
void Init();
signed main(){
    Init();
    return 0;
}
void Init(){
    scanf("%lld%lld",&n,&Q);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(i>=2) a[i]-=a[1];
    }
    int gcd=abs(a[2]);
    for(int i=2;i<=n;i++){
    	gcd=Gcd(gcd,abs(a[i]));	
	}
        
    for(int i=1;i<=Q;i++){
        int d;scanf("%lld",&d);
        a[1]+=d;Gcd(abs(a[1]),gcd);
//        printf("i=%lld ",i);
        printf("%lld\n",Gcd(abs(a[1]),gcd));
    }
}
