#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

int n, m;

int res[3] = {1, 1, 1};
int A[3][3] = {
    {0, 1, 0},
    {1, 1, 1},
    {0, 0, 1}
};

void mul(int c[3], int a[3], int b[][3]) {
    
    int tmp[3] = {0};
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            tmp[i] = (tmp[i] + (LL)a[j] * b[j][i]) % m;
    
    memcpy(c, tmp, sizeof tmp);
}

void mul(int c[][3], int a[][3], int b[][3]) {
    
    int tmp[3][3] = {0};
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                tmp[i][j] = (tmp[i][j] + (LL)a[i][k] * b[k][j]) % m;
                
    memcpy(c, tmp, sizeof tmp);
}
 
int main() {
    
    scanf("%d%d", &n, &m);
    
    n--;
    while (n) {
        if (n & 1) mul(res, res, A);
        mul(A, A, A);
        n >>= 1;
    }
    
    printf("%d", res[2]);
    
    return 0;
}
