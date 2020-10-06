#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> cases(n);
        for (auto &it : cases)
            cin >> it;
        int sum = 0;
        sum += cases[0] == 1;
        for (int i = 1; i < n; i++)
        {
            if (cases[i] == 0)
                continue;
            int j = i;
            while (j < n && cases[j])
            {
                j++;
            }
            sum += (j - i) / 3;
            i = j - 1;
        }
        cout << sum << endl;
    }
    return 0;
}