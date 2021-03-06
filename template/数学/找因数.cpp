#include <bits/stdc++.h>

using namespace std;

set<int> S;
int n;

int main()
{
    cin >> n;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            S.insert(i);
            S.insert(n / i);
        }
    }
    for (set<int>::iterator it = S.begin(); it != S.end(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}