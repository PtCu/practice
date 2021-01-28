//扩展欧几里得法
void exgcd(int a,int b,int &x,int &y){
    if(b==0){
        x = 1, y = 0;
        return;
    }
    exgcd(b, a % b, y, x);
    y -= a / b * x;
}

int p;
//快速幂法
int qpow(long long a,int b){
    int ans = 1;
    a = (a % p + p) % p;
    for (; b;b>>=1){
        if(b&1)
            ans = (ans * a) % p;
        a = (a * a) % p;
    }
    return ans;
}

//线性求逆元
//求出1，2，...n中每个数关于p的逆元
