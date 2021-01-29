#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 4;
int c[maxn]; //c[i]为i作为因子的次数
int main()
{
    int n, max_factor = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        max_factor = max(max_factor, x);
        for (int j = 1; j * j <= x; ++j)
        {
            if (x % j == 0)
            {
                c[j]++;
                if (j * j != x)
                {
                    c[x / j]++;
                }
            }
        }
    }
    //从最大因子开始
    int k = max_factor; 
    // 每个数分解因数，c[i]表示i作为因子的次数。 
    // 对于答案i，c[k]>i的k可以作为答案。
    // 可以发现i的答案一定大于等于i+1的答案。
    //所以从1到n，从最大因子开始找。找到存在一个因子k，使得出现次数大于等于i即可
    for (int i = 1; i <= n; ++i)
    {
        //k的出现次数
        while (c[k] < i)
        {
            k--;
        }
        cout << k << endl;
    }
    return 0;
}