// #include <bits/stdc++.h>
// using namespace std;
// const int M = 998244353;
// string s0 = "1";
// string expand(string S)
// {
//     string new_S = "";
//     for (int i = 0; i < S.length(); i++)
//     {
//         switch (S[i])
//         {
//         case '1':
//             new_S += "2";
//             break;
//         case '2':
//             new_S += "4";
//             break;
//         case '4':
//             new_S += "16";
//             break;
//         case '6':
//             new_S += "64";
//             break;
//         default:
//             break;
//         }
//     }
//     return new_S;
// }
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int n;
//     string S;
//     cin >> n >> S;

//     while (n--)
//     {
//         s0 = expand(s0);
//     }
//     int ans = 0;
//     for (int i = 0; (i = s0.find(S, i)) != string::npos; (++ans) %= M, i++)
//         ;
//     cout << ans << endl;
// }

#include <bits/stdc++.h>
using namespace std;
const int M = 998244353;

int baseEle[] = {1, 2, 4, 6, 16, 26, 41, 42, 44, 46, 61, 62, 64, 66};
vector<vector<int>> convert = {{2}, {4}, {1, 6, 16}, {6, 4, 64}, {26}, {46}, {62}, {64}, {61}, {66}, {42}, {44}, {41}, {46}};
int val2id[67];
void init()
{
    memset(val2id, -1, sizeof(val2id));
    for (int i = 0; i < sizeof(baseEle) / sizeof(baseEle[0]); i++)
        val2id[baseEle[i]] = i;
}

void mul(vector<vector<int>> &a, vector<vector<int>> b)
{ //利用cache加速
    int n = a.size(), m = a[0].size(), l = b[0].size();
    vector<vector<int>> c(n, vector<int>(l));
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < m; k++)
        {
            int r = a[i][k];
            for (int j = 0; j < l; j++)
            {
                c[i][j] += r * b[k][j] % M;
            }
        }
    }
    a.assign(c.begin(), c.end());
}
int solveBase(int id, int n) //矩阵快速幂
{
    vector<vector<int>> I(1, vector<int>(14));
    I[0][0] = 1;
    vector<vector<int>> mat(14, vector<int>(14));
    for (int from = 0; from < 14; from++) //生成转移矩阵
        for (int to : convert[from])
            mat[from][val2id[to]]++;
    while (n > 0)
    {
        if ((n & 1))
            mul(I, mat); //mat作为第二个矩阵
        mul(mat, mat);
        n >>= 1;
    }
    return I[0][id];
}

int main()
{
    init();
    int n, m;
    cin >> n >> m;
    cout << solveBase(val2id[m], n);
}