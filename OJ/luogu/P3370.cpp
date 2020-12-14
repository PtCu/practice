#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    unordered_set<string> m;
    string s;
    while (n--)
    {
        cin >> s;
        m.insert(s);
    }
    cout << m.size() << endl;
}