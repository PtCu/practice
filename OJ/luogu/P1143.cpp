#include <bits/stdc++.h>
using namespace std;
char out[100];
int main()
{
    int n, m;
    string source;
    cin >> n >> source >> m;
    int sum = 0;
    for (int i = 0; i < source.size(); ++i)
    {
        if (source[i] >= 'A')
        {
            sum += (source[i] - 'A' + 10) * (int)pow(n, source.size() - i - 1);
        }
        else
        {
            sum += (source[i] - '0') *(int) pow(n, source.size() - i - 1);
        }
    }
    int s = 0;
    while (sum > 0)
    {
        out[s++] = sum % m;
        sum /= m;
    }
    for (int i = s - 1; i >= 0; --i)
    {
        if (out[i] >= 10)
            cout << (char)(out[i] + 'A' - 10);
        else
            cout << (int)out[i];
    }
    return 0;
}