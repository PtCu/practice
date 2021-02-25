#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int A[maxn], B[maxn], C[maxn * 2];
int solve(int na, int nb)
{

    int mid = (na + nb - 1) / 2;
    for (int i = 0, j = 0, k = 0; k <= mid;)
    {
        if (i >= na)
        {
            C[k++] = B[j++];
        }
        else if (j >= nb)
        {
            C[k++] = A[i++];
        }
        else if (A[i] >= B[j])
        {
            C[k++] = B[j++];
        }

        else if (A[i] < B[j])
        {
            C[k++] = A[i++];
        }
    }
    return C[mid];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int na, nb;
    int x;
    cin >> na;
    for (int i = 0; i < na; ++i)
    {
        cin >> A[i];
    }
    cin >> nb;
    for (int i = 0; i < nb; ++i)
    {
        cin >> B[i];
    }
    x = solve(na, nb);
    cout << x;
}