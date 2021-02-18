#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
const int maxn = 1e4;
using namespace std;
int p;

void init(){
    scanf("%d",&p);
    printf("%d\n",(int)(p*(log(2))/log(10)+1));
}

struct BigInt{
    int len,a[maxn];
    void clear(){
        memset(a,0,sizeof(a));
    }
    void out(){
        int cnt = 0;
        for(int i = 500 ; i >= 1; i--){
            cnt++;
            if(i==1)  printf("%d",a[i]-1);
            else
            printf("%d",a[i]);
            if(cnt % 50 == 0)   printf("\n");
        }
    }
}A,B;

BigInt Mul(BigInt AA,BigInt BB){
    BigInt C;C.clear();C.len=AA.len+BB.len;
    for(int i = 1; i <= AA.len;i++)
        for(int j = 1; j <= BB.len ;j++){
            if(i+j-1 > 505) continue;
            C.a[i+j-1]+=AA.a[i]*BB.a[j];
           // printf("C.%d   =%d\n",i+j-1,C.a[i+j-1]);
        }
    for(int i = 1; i <= 505; i++){
        C.a[i+1]+=C.a[i]/10,C.a[i]%=10;
    }
    C.a[501] = 0;
    while(C.len > 0 && C.a[C.len] == 0) C.len--;
    return C;
}

void quickpow(){
    A.clear();
    B.clear();
    A.a[1] =1;A.len = 1;
    B.a[1] =2;B.len = 1;
    while(p > 0){
        if(p&1) A = Mul(A,B);
        B = Mul(B,B);
        p >>= 1;
    }
    A.out();
}

int main(){
    init();
    quickpow();
}