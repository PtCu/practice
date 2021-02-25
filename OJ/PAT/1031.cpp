#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
string s;
int main()
{
    cin >> s;
    int n = s.size();
    int n1, n2;
    n1 = (n + 2) / 3;
    n2 = n + 2 - 2 * n1;
    int cnt_f = 0;
    int cnt_b = n - 1;
    for (int i = 0; i < n1 - 1; ++i)
    {
        for (int j = 0; j < n2; ++j)
        {
            if (j == 0)
            {
                cout << s[cnt_f++];
            }
            else if (j == n2 - 1)
            {
                cout << s[cnt_b--] << endl;
            }
            else
            {
                cout << " ";
            }
        }
    }
    for (int i = cnt_f; i <= cnt_b; ++i)
    {
        cout << s[i];
    }
}