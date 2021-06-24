#include <bits/stdc++.h>
using namespace std;
string A, B;
const int maxn = 2e3 + 10;
int f[maxn][maxn]; //f(i,j)表示将A串前i个字符改为B串前j个字符需要的步数
int a_len, b_len;
int main()
{
    cin >> A >> B;
    A.insert(A.begin(), '0');
    B.insert(B.begin(), '0');
    a_len = A.length();
    b_len = B.length();
    for (int i = 0; i <= a_len; ++i)
        f[i][0] = i;
    for (int i = 0; i <= b_len; ++i)
        f[0][i] = i;

    for (int i = 1; i <= a_len; ++i)
    {
        for (int j = 1; j <= b_len; ++j)
        {
            // 删：可以看做把A串最后一个字符删去后不再考虑这个字符 所以f(i,j)=min(f(i,j),f(i-1,j)+1);
            // 加：可以看做与B串最后一个字符抵消后不再考虑这个字符 所以f(i,j)=min(f(i,j),f(i,j-1)+1);
            // 改：可以看做删和加的集合 抵消了A、B串最后的两个字符 所以f(i,j)=min(f(i,j),f(i-1,j-1)+1); 当然若A、B串最后一个字符相同就可以不用操作了
            int k = 1;
            if (A[i] == B[j])
                k = 0;
            f[i][j] = min(min(f[i - 1][j] + 1, f[i][j - 1] + 1), f[i - 1][j - 1] + k);
        }
    }
    cout << f[a_len][b_len];
}