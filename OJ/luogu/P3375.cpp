#include <bits/stdc++.h>
using namespace std;
int *buildNext(const string &P)
{
    int m = P.length(), j = 0; //主串指针
    int *N = new int[m];
    N[0] = 0;
    for (int i = 1, k = 0; i < m; i++)
    {
        while (k > 0 && P[k] != P[i])
        {
            k = N[k - 1];
        }
        if (P[k] == P[i])
            k++;
        N[i] = k;
    }
    return N;
}
int *buildNext1(const string &P)
{
    size_t m = P.length(), j = 0; //“主”串指针
    int *N = new int[m];          //next表
    int t = N[0] = -1;            //模式串指针
    while (j < m - 1)
        if (0 > t || P[j] == P[t])
        { //匹配
              N[j] = (P[++j] != P[++t] ? t : N[t]);
        }
        else //失配
            t = N[t];

    return N;
}

void match(const string &P, const string &T)
{
    int *next = buildNext1(P);
    int n = T.length(), i = 0;
    int m = P.length(), j = 0;
    for (;;)
    {
        while (j < m && i < n)
        {
            if (j < 0 || P[j] == T[i])
            {
                i++;
                j++;
            }
            else
            {
                j = next[j];
            }
        }
        if (i - j <= n - m)
        {
            cout << i - j + 1 << endl;
            i = i - j + 1;
            j = 0;
        }
        else
        {
            break;
        }
    }
    //delete next;
    next = buildNext(P);
    for (size_t i = 0; i < P.length(); ++i)
    {
        cout << next[i] << " ";
    }
    delete[] next;
}
int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    string s1, s2;
    cin >> s1 >> s2;
    match(s2, s1);
}
