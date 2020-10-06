#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
vector<string> filenames;
const int maxcol = 60;
void print(string s, int len, char extra) {
    cout << s;
    for (int i = 0; i < len - s.length();i++)
    {
        cout << extra;
    }
}
int main()
{
    int n;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int maxLength = 0;
    while (n--)
    {
        string s;
        cin >> s;
        filenames.push_back(s);
        maxLength = max(maxLength, (int)s.length());
    }
    int cols = (maxcol - maxLength) / (maxLength + 2) + 1;
    int rows = (n - 1) / cols + 1;
    for (int i = 0; i < rows;i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int idx = j * rows + i;
            if (idx < n)
            {
                print(filenames[idx], j == cols - 1 ? maxLength : maxLength + 2, ' ');
            }
        }
        cout << endl;
    }
}