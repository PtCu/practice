#include <bits/stdc++.h>
using namespace std;
int d[] = {0, 1, 2, 3, 4, 5, 6, 7, 10, 12, 14};
int main()
{
    int a = upper_bound(d + 1, d + 1 + 10, 20) - d;
    cout << a;
}