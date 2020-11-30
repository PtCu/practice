#include <bits/stdc++.h>
#define MAX 1e9+10
using namespace std;
const int maxn = 505;
const int maxm = 10005;

int n, m; //n个点，m条边
int dis[maxn][maxn];
void Floyed()
{
    int temp;
    for (size_t k = 1; k <= n; ++k)
    {
        for (size_t i = 1; i <= n; ++i)
        {
            if(i!=k)
            for (size_t j = 1; j <= n; ++j)
            {
                int temp = (dis[i][k] == MAX || dis[k][j] == MAX) ? MAX : (dis[i][k] % 998244354 + dis[k][j] % 998244354) % 998244354;
                if (i!=j&&k!=j&&dis[i][j] > temp)
                {
                    dis[i][j] = temp;
                }
            }
        }
    }
}
 int main()
{
    cin >> n >> m;
    // memset是按照字节进行赋值，即对每一个字节赋相同值，可以对数组进行整体赋值。每个字节赋值为127即为最大
    // memset(dis, 127, sizeof(dis));

    for (size_t i = 1; i <= n; ++i)
    {
        for (size_t j = 1; j <= n; ++j)
        {
            if (i == j)
                dis[i][j] = 0;
            else
                dis[i][j] = MAX;
        }
    }

    int x, y;
    int l;
    while (m--)
    {
        cin >> x >> y >> l;
        dis[x][y] = l;
        dis[y][x] = l;
    }
    Floyed();
    int sum;
    for (size_t i = 1; i <= n; ++i)
    {
        sum = 0;
        for (size_t j = 1; j <= n; ++j)
        {
            if (i == j)
                continue;
            sum = (sum + dis[i][j]) % 998244354;
        }
        cout << sum % 998244354 << endl;
    }
}