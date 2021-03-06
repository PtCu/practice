//luogu2822
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
bool A[maxn], B[maxn];
int main()
{
    int n;
    cin >> n;
    char ch;
    for (int i = 1; i <= n; ++i)
    {
        cin >> ch;
        ch == 'B' ? A[i] = 0 : A[i] = 1;
    }
    int min_cnt = numeric_limits<int>::max(), ans_len;
    for (int len = 1; len <= n; ++len)
    {
        bool flag = 1;
        memset(B, 0, sizeof(B));
        int cnt = 0;
        bool cur_ins = 0; //这一小区间内当前指令。1为反转，0为不动。初始为0，表示不动
        //B[i]为差分数组，记录了区间节点处的动作。初始为0，表示不动。
        //0或1与0异或为本身; 0或1与1异或为相反
        //相当于cur_ins作用于A[i]，如果cur_ins为0则保证不动，为1则反转
        for (int i = 1; i <= n; ++i)
        {
            cur_ins ^= B[i];
            if ((cur_ins ^ A[i]) == 0) //与A[i]异或，相当于施加动作于A[i].
            {
                if (i + len - 1 > n)
                {
                    flag = 0;
                    break;
                }
                cur_ins ^= 1, B[i + len] ^= 1; //B[i+len]^1表示B[i]到B[i+len]区间内的动作反转
                cnt++;
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
   cout << ans_len << " "<<min_cnt;
}