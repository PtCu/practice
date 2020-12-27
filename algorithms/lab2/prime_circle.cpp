//素数环
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
int a[maxn];
int n;
bool isValid(int pos, int x)
{
    for (size_t i = 0; i < pos; ++i)
    {
        if (a[i] == x)
            return false;
    }
    bool flag = isPrime(a[pos - 1] + x);
    if (flag && pos == n - 1)
    {
        flag = isPrime(x + a[0]);
    }
    return flag;
}
bool isPrime(int x)
{
    int n = (int)sqrt(x);
    for (int i = 2; i <= n; ++i)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}
//位置i放置x
void place(int pos, int x)
{
    
    if (pos== n - 1)
    {
        //do something
        return;
    }
    for (int j = 1; j <= n; ++j)
    {
        a[pos] = j;
        if (isValid(pos, j))
            place(pos + 1, j); //符合要求就确定下一个位置
        a[pos] = -1;
    }
}

int main()
{
    place(0, 1);
}