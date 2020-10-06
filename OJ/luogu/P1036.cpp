#include <bits/stdc++.h>
using namespace std;
int ans;
int n, k;
vector<int> source(1,0);
bool isPrime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void dfs(int first, int k, int sum)
{
    if (k == 0)
    {
        if (isPrime(sum))
            ans++;
        return;
    }
    for (int i = first; i <= n; i++)
    {
        dfs(i + 1, k - 1, sum + source[i]);
    }
}
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        source.push_back(a);
    }
    dfs(1,k,0);
    cout<<ans;
}