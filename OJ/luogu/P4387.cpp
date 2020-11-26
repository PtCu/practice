#include <bits/stdc++.h>
using namespace std;
bool isValid(vector<int> &A, vector<int> &B)
{
    stack<int> S;
    size_t cnt = 0;
    for (size_t i = 0; i < A.size(); ++i)
    {
        S.push(A[i]);
        while (!S.empty()&&S.top() == B[cnt])
        {
            ++cnt;
            S.pop();
        }
    }
    if (S.empty() && cnt == B.size() )
        return true;
    else
        return false;
}
int main()
{
    int n, q, x;
    cin >> q;
    while (q--)
    {
        vector<int> A, B;
        cin >> n;
        for (size_t i = 0; i < n; ++i)
        {
            cin >> x;
            A.push_back(x);
        }
        for (size_t i = 0; i < n; ++i)
        {
            cin >> x;
            B.push_back(x);
        }
        isValid(A, B) ? cout << "Yes" << endl : cout << "No" << endl;
    }
}