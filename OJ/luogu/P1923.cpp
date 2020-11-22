#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e7 + 3;
vector<int> source(maxn);
int ans, k;

//[lo,hi]
void partition(size_t lo, size_t hi)
{
    size_t i = lo, j = hi;
    int pivot = source[i];
    while (i < j)
    {
        while ((i < j) && pivot < source[j])
        {
            j--;
        }
        if (i < j)
        {
            source[i] = source[j];
        }
        while ((i < j) && pivot > source[i])
        {
            i++;
        }
        if (i < j)
        {
            source[j] = source[i];
        }
    }
    source[i] = pivot;
    if (i == k)
    {
        ans = source[i];
        return;
    }
    else if (i > k)
    {
        partition(lo, i - 1);
    }
    else
    {
        partition(i + 1, hi);
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n >> k;
    for (size_t i = 0; i < n; ++i)
    {
        cin >> source[i];
    }
    partition(0, n - 1);
    cout << ans;
}