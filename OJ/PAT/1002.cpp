#include <bits/stdc++.h>
using namespace std;
map<int, float, greater<int>> A;
int main()
{
    float a_n;
    int n;
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        cin >> n >> a_n;
        A[n] = a_n;
    }
    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        cin >> n >> a_n;
        if (A.count(n))
        {
            A[n] += a_n;
            if(A[n]==0)
                A.erase(n);
        }
        else
            A[n] = a_n;
    }
    cout << A.size();
    for (auto a : A)
    {
        cout << " " << a.first << " " << setiosflags(ios::fixed) << setprecision(1) << a.second;
        //cout << a.first << " " << a.second << " ";
    }
}