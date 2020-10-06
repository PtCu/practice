#include <bits/stdc++.h>
using namespace std;
int outcome[5][5] = {
    {0, -1, 1, 1, -1},
    {1, 0, -1, 1, -1},
    {-1, 1, 0, -1, 1},
    {-1, -1, 1, 0, 1},
    {1, 1, -1, -1, 0}};
int judge(int a, int b)
{
    return outcome[a][b];
}
int main()
{
    int n, na, nb;
    vector<int> A(na);
    vector<int> B(nb);
    // A.resize(na);
    // B.resize(nb);
    cin >> n >> na >> nb;
    for (int i = 0; i < na; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < nb; i++)
    {
        cin >> B[i];
    }

    int a_sum = 0;
    int b_sum = 0;
    for (int i = 0; i < n; i++)
    {
        int out = judge(A[i % na], B[i % nb]);
        if (out == 1)
            a_sum++;
        else if (out == -1)
            b_sum++;
    }
    cout << a_sum << " " << b_sum << endl;
    return 0;
}