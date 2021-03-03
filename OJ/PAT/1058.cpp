#include <bits/stdc++.h>
using namespace std;

int A[3], B[3], C[3];
int main()
{
    scanf("%d.%d.%d", &A[2], &A[1], &A[0]);
    scanf("%d.%d.%d", &B[2], &B[1], &B[0]);
    int carry = 0;
    for (int i = 0; i <= 2; ++i)
    {
        C[i] = carry + A[i] + B[i];
        if (i == 0)
        {
            carry = C[i] / 29;
            C[i] %= 29;
        }
        else if (i == 1)
        {
            carry = C[i] / 17;
            C[i] %= 17;
        }
    }
    cout << C[2] << "." << C[1] << "." << C[0];
}