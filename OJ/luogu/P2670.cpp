#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int m, n; //n是行数，m是列数
    cin >> n >> m;
    char origin[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> origin[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int num = 0;
            if (origin[i][j] == '?')
            {
                if (j > 0 && origin[i][j - 1] == '*')
                    num++;
                if (i > 0 && origin[i - 1][j] == '*')
                    num++;
                if (i > 0 && j > 0 && origin[i - 1][j - 1] == '*')
                    num++;
                if (j < m - 1 && origin[i][j + 1] == '*')
                    num++;
                if (i < n - 1 && origin[i + 1][j] == '*')
                    num++;
                if (i < n - 1 && j < m - 1 && origin[i + 1][j + 1] == '*')
                    num++;
                if (i < n - 1 && j > 0 && origin[i + 1][j - 1] == '*')
                    num++;
                if (i > 0 && j < m - 1 && origin[i - 1][j + 1] == '*')
                    num++;
                    origin[i][j] = '0' + num;
            }
            
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << origin[i][j];
        }
        cout<<endl;
    }
    return 0;
}
