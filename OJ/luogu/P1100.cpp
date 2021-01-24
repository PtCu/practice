#include <bits/stdc++.h>
using namespace std;
int main()
{
    unsigned int n;
    cin >> n;
    n = (n >> 16) | (n << 16);
    cout << n;
}