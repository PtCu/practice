#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> ans;
void dfs(int sum, int head) //head表示当前开头的元素
{

    if (sum == n)
    {
        auto it = ans.begin();
        cout << *it;
        for (it++; it != ans.end(); it++)
        {
            cout << '+' << *it;
        }
        cout << endl;
        return;
    }

    for (int i = head; i < n; i++)
    {
        if (sum + i <= n)
        {
            ans.push_back(i);
            dfs(sum + i, i);
            ans.pop_back();
        }
    }
}
int main()
{
    cin >> n;
    dfs(0, 1);
}