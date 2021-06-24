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
        // 考虑一般情况（这里是DP思想）：我们要得到将a[1..i]经过最少次数的操作就转化为b[1..j]，那么我们就必须在此之前以最少次数（假设为k次）的操作,使现在的a和b只需再做一次操作或者不做操作就可以使a[1..i]转化到b[1..j]。而“之前”有三种情况：
        // ①将a[1…i]转化为b[1…j-1]
        // ②将a[1..i-1]转化为b[1..j]
        // ③将a[1…i-1]转化为b[1…j-1]
        // 第①种情况，在字符串A末添加字符串B的第j个字符，操作次数加一
        // 第②种情况，只需要在最后将a[i]删除，总共需要k+1个操作。
        // 第③种情况，只需要在最后将a[i]替换为b[j]，总共需要k+1个操作。但如果a[i]刚好等于b[j]，就不用再替换了，那就只需要k个操作。
        // 为了得到最小值，将以上三种情况的最小值作为f[i][j]的值（我前面不是说了f[i][j]表示串a[1…i]转换为串b[1…j]所需的最少操作次数嘛）,最后答案在f[n][m]中。
            int k = 1;
            if (A[i] == B[j])
                k = 0;
            f[i][j] = min(min(f[i - 1][j] + 1, f[i][j - 1] + 1), f[i - 1][j - 1] + k);
        }
    }
    cout << f[a_len][b_len];
}