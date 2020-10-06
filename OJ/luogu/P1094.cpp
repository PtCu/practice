#include <bits/stdc++.h>
using namespace std;
int main()
{
    int w;
    cin >> w;
    int n;
    cin >> n;
    vector<int> sources;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        sources.push_back(x);
    }
    sort(sources.begin(), sources.end());
    int i = 0;
    int j = sources.size()-1;
    int ans = 0;
    while (i <= j)
    {
        if (sources[i] + sources[j] > w)
        {
            j--;
            ans++;
        }
        else
        {
            i++;
            j--;
            ans++;
        }
    }
    cout << ans;
    return 0;
}