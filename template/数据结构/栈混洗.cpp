//PAT 1051
#include <bits/stdc++.h>
using namespace std;
vector<int> A, B;
int n, m, k;
bool isValid()
{
    stack<int> C;
    int cnt = 0;
    for (int i = 0; i < A.size(); ++i)
    {
        if (C.size() < m)
            C.push(A[i]);
        while (!C.empty() && C.top() == B[cnt])
        {
            C.pop();
            cnt++;
        }
    }
    if (C.empty() && cnt == B.size())
        return true;
    else
        return false;
}
bool isValid2() {
    int iA = 0, iB = 0;
    stack<int>S;

    while (iA < A.size())
    {
        while (S.empty() || S.top() != B[iB])
        {
            S.push(A[iA++]);
        }
        ++iB;
        S.pop();
    }

    while (!S.empty())
    {
        if (S.top() != B[iB++]) {
            return false;
        }
        S.pop();
    }
    return true;







}
int main()
{

    cin >> m >> n >> k;

    for (int i = 1; i <= n; ++i)
    {
        A.push_back(i);
    }
    int x;
    for (int i = 0; i < k; ++i)
    {
        B.clear();
        for (int j = 0; j < n; ++j)
        {
            cin >> x;
            B.push_back(x);
        }
        if (isValid())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}