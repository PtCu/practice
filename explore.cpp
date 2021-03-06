#include <bits/stdc++.h>
using namespace std;
int c[100];
int n;
int LowerBit(int x)
{
    return x & (-x);
}
//[1,x]
int getSum(int x)
{
    int sum = 0;
    while (x)
    {
        sum += c[x];
        x -= LowerBit(x);
    }
}
int update(int i, int x)
{
    while (i <= n)
    {
        c[i] = x;
        i += LowerBit(i);
    }
}
int main()
{
    for (int i = 1; i < 1; ++i)
    {
        cout << i << " ";
    }
}