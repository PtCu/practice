#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> students;
vector<int> schools;

int binary(int x) //[0,m)
{
    int l = 0;
    int r = m;
    while (l < r)
    {
        int m = (l + r) >> 1;
        (x < schools[m]) ? r = m : l = m + 1;
    } //结束时，l为大于x的元素的最小秩
    if (l > 0)
        return min(abs(schools[l] - x), abs(x - schools[l - 1]));
    else
    {
        return abs(schools[l] - x);
    }
}
int main()
{

    cin >> m >> n;
    int sum = 0;
    students.resize(n);
    schools.resize(m);
    for (int i = 0; i < m; i++)
    {
        cin >> schools[i];
    }
    sort(schools.begin(), schools.end());
    for (int i = 0; i < n; i++)
    {
        cin >> students[i];
        sum += binary(students[i]);
    }
    cout << sum;
}