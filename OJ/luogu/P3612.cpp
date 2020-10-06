#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0); //取消cin,cout的缓存
    cin.tie(0);
    std::cout.tie(0); //解绑
    string raw;
    cin >> raw;
    ll N;
    cin >> N;
    int len = raw.length();

    while (len < N)
    {
        ll i = len;
        int num = log2(N / len);
        i <<= num;
        if (N == i)
        {
            i /= 2;
            N -= (i + 1);
        }
        else if (N == i + 1)
            N = i;
        else
            N -= (i + 1);
    }
    cout << raw[N - 1];
}