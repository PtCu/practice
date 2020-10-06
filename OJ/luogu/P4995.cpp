#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> sources(n);
    for (int i = 0; i < n; i++)
    {
        cin >> sources[i];
    }
    sort(sources.begin(), sources.end());
    long long sum = sources[n - 1] * sources[n - 1];
    for (int i = 0, j = n - 1, m = 0; i < j; m++)
    {
        sum += (sources[j] - sources[i]) * (sources[j] - sources[i]);
        if (m % 2)
            i++;
        else
            j--;
    }
    cout << sum;
}