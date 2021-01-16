#include <bits/stdc++.h>
using namespace std;
//把州和城市的前两位做映射
unordered_map<string, int> M;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    int ans = 0;
    cin >> N;
    string a, b;
    while (N--)
    {
        cin >> a >> b;
        a = a.substr(0, 2);
        if (a != b)
            ans += M[b + a];
        M[a + b]++;
    }
    cout << ans;
}