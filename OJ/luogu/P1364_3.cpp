#include <bits/stdc++.h>
#define MAX 1e8
using namespace std;
const int maxn = 100;
int G[maxn + 5][maxn + 5];
int nodes[maxn + 5];
int N;
void floyd()
{
    for (size_t k = 1; k <= N; ++k)
    {
        for (size_t i = 1; i <= N; ++i)
        {
            for (size_t j = 1; j <= N; ++j)
            {
                int temp = (G[i][k] == MAX || G[k][j] == MAX) ? MAX : G[i][k] + G[k][j];
                if (temp < G[i][j])
                {
                    G[i][j] = temp;
                }
            }
        }
    }
}
int main()
{
    cin >> N;
    int x, y, z;
    for (size_t i = 1; i <= N; ++i)
    {
        for (size_t j = 1; j <= N; ++j)
            G[i][j] = MAX;
    }
    for (size_t i = 1; i <= N; ++i)
    {
        G[i][i] = 0;
        cin >> x >> y >> z;
        if (y > 0)
            G[i][y] = G[y][i] = 1;
        if (z > 0)
            G[i][z] = G[z][i] = 1;
        nodes[i] = x;
    }
    floyd();
    int _min = MAX;
    int sum;
    for (size_t i = 1; i <= N; ++i)
    {
        sum = 0;
        for (size_t j = 1; j <= N; ++j)
        {
            sum += G[i][j] * nodes[j];
        }
        _min = min(_min, sum);
    }
    cout << _min;
    return 0;
}