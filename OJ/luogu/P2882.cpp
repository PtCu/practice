#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 9;
bool A[maxn], B[maxn];
int main()
{
    int n;
    cin >> n;
    char h;
    for (int i = 1; i <= n; ++i)
    {
        cin >> h;
        A[i] = h == 'B' ? 0 : 1;
    }
    int min_cnt = numeric_limits<int>::max(), ans_len;
    for (int len = 1; len <= n; ++len)
    {
        memset(B, 0, sizeof(B));
        //先把b设为0，此时1或者0与b做异或都等于本身
        //1或者0与1做异或得到相反的数
        bool b = 0, flag = 1; 
        int cnt = 0;
        for (int i = 1; i <= n; ++i)
        {
            b ^= B[i]; //B为记录差分的数组。得到动作，1为反转，0为不反转
            if ((A[i] ^ b)==0) //当前位置为0,即A[i]为1时，b为1；或A[i]为0时，b为0
            {
                if (i + len - 1 > n)
                {
                    flag = 0;
                    break;
                }
                b ^= 1, B[i + len] ^= 1;
                ++cnt;
            }
        }
        if (flag)
        {
            if (cnt < min_cnt)
            {
                min_cnt = cnt;
                ans_len = len;
            }
        }
    }
    cout << ans_len << min_cnt;
}