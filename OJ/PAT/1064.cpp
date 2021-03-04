#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
int input[maxn];
int output[maxn];
int n;
int cnt = 0;
void inorder(int x)
{
    if (x > n)
        return;
    inorder(x << 1);
    output[x] = input[++cnt];
    inorder(x << 1 | 1);
}
int main()
{

    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> input[i];
    }
    sort(input + 1, input + n + 1);
    inorder(1);
    for (int i = 1; i <= n; ++i)
    {
        if (i == n)
            cout << output[i];
        else
            cout << output[i] << " ";
    }
}