#include <bits/stdc++.h>
using namespace std;
int s[4];
int ans = INT32_MAX;

void dfs(vector<int> &time, int i, int left, int right)
{
    if (i >= time.size())
    {
        ans = min(ans, max(left, right));
        return;
    }
    dfs(time, i + 1, left + time[i], right);
    dfs(time, i + 1, left, right + time[i]);
}
int main()
{
    for (int i = 0; i < 4; i++)
    {
        cin >> s[i];
    }
    vector<int> time;
    int x;
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        time.clear();
        ans = INT32_MAX;
        for (int j = 0; j < s[i]; j++)
        {
            cin >> x;
            time.push_back(x);
        }
        dfs(time, 0, 0, 0);
        sum += ans;
    }
    cout << sum;
}