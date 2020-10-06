#include <bits/stdc++.h>
using namespace std;
vector<int> sources;
int n, m;
inline int solve(int mid)
{
    int sum = 0;
    int partial = 0;
    for (int i = 0; i < n; i++)
    {
        if (partial + sources[i] <= mid)
            partial += sources[i];
        else
        {
            partial = sources[i];
            sum++;
        }
    }
    return sum + 1;
}
int main()
{

    cin >> n >> m;
    int x;
    int max_h = 0;
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        total += x;
        sources.push_back(x);
        max_h = max(x, max_h);
    }
    //最大的数和所有数之和之间二分
    int low = max_h;
    int high = total;
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        int num = solve(mid);
        num <= m ? (high = mid - 1) : (low = mid + 1);
    }
    cout << low;
}