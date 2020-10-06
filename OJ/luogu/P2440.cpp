#include <bits/stdc++.h>
using namespace std;
vector<int> sources;
int n, k;
int getNum(int l)
{
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        num += (sources[i] / l);
    }
    return num;
}
int main()
{
    
    cin >> n >> k;

    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        sources.push_back(x);
    }
    sort(sources.begin(), sources.end());
    int high = sources[n - 1];
    int low = 1;
    int mid = 0, nums=0;
    while (low < high) //[low,high)
    {
        mid = (low + high) >> 1;
        nums = getNum(mid);
        nums < k ? high = mid : low = mid + 1;
    }
    cout << low - 1;
}