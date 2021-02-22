#include <bits/stdc++.h>
using namespace std;
map<int, double, greater<int>> A, C;
int main()
{
    int k;
    cin >> k;
    int n;
    double a_n;
    for (int i = 0; i < k; ++i)
    {
        cin >> n >> a_n;
        A[n] = a_n;
    }
    cin >> k;
    int tmp;
    for (int i = 0; i < k; ++i)
    {
        cin >> n >> a_n;
        for (auto iter = A.begin(); iter != A.end(); ++iter)
        {
            tmp = (*iter).first + n;
            if (C.count(tmp))
                C[tmp] += a_n * (*iter).second;
            else
                C[tmp] = a_n * (*iter).second;
        }
    }
    for(auto a:C){
        if(a.second==0)
            C.erase(a.first);
    }
    cout << C.size();
    for (auto a : C)
    {
        cout << " " << a.first << " " << setiosflags(ios::fixed) << setprecision(1) << a.second;
    }
}