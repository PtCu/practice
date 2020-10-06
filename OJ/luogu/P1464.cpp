#include <bits/stdc++.h>
using namespace std;
long long dp[25][25][25];
long long w(long long a, long long b, long long c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    else if (a > 20 || b > 20 || c > 20)
        return w(20, 20, 20);
    //全局变量默认为0.如果不是0则说明该记录已经算过了，直接返回就行。
    else if (dp[a][b][c] != 0)
        return dp[a][b][c];
   
    else if (a < b && b < c)
        dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    else
        dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    return dp[a][b][c];
}
int main(int argc, char const *argv[])
{
    long long a, b, c;
    while (1)
    {
        cin >> a >> b >> c;
        if(a==-1&&b==-1&&c==-1) break;
        cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<w(a,b,c)<<endl;
    }
    return 0;
}
