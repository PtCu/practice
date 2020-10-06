#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int M = 1e9 + 7;
struct Matrix
{
    int n, m;
    int v[maxn][maxn];
    Matrix(int n, int m) : n(n), m(m) {}
    void init()
    { //初始化矩阵
        memset(v, 0, sizeof(v));
    }
    Matrix operator*(const Matrix B) const
    {
        Matrix C(n, B.m); //用来存放答案
        C.init();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < B.m; j++)
                for (int k = 0; k < m; k++)
                    C.v[i][j] = (C.v[i][j] + v[i][k] * B.v[k][j] % M) % M;
        return C;
    }
    void print()
    { //输出该矩阵，用来测试
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << v[i][j] << " ";
            cout << endl;
        }
    }
};
Matrix q_pow(Matrix &A, int b, int M)
{
    Matrix C(A.n, A.m);
    C.init();
    for (int i = 0; i < C.n; i++)
        C.v[i][i] = 1;
    while (b)
    {
        if (b & 1)
            C = C * A;
        A = A * A;
        b >>= 1;
    }
    return C;
}