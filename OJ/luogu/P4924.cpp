#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    int matrix[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = j + n * i + 1;
        }
    }
    for (int k = 0; k < m; k++)
    {
        int x, y, r, z;
        cin >> x >> y >> r >> z;
        x -= 1;
        y -= 1;
        //顺时针：
        if (z == 0)
        {
            for (int i = x - 1; i >= x - r; i--)
            {
                for (int j = y - 1; j >= y - r; j--)
                {
                    swap(matrix[i][j], matrix[x - y + j][y + x - i]); 
                    swap(matrix[i][j], matrix[x * 2 - i][y * 2 - j]); 
                    swap(matrix[i][j], matrix[x + y - j][y - x + i]); 
                }
            }
            for (int j = y - 1; j >= y - r; j--)
            {
                swap(matrix[x][j], matrix[x - y + j][y]); 
                swap(matrix[x][j], matrix[x][y * 2 - j]); 
                swap(matrix[x][j], matrix[x + y - j][y]); 
            }
        }
        else

        {
            for (int i = x - 1; i >= x - r; i--)
            {
                for (int j = y - 1; j >= y - r; j--)
                {
                    swap(matrix[i][j], matrix[x + y - j][y - x + i]); 
                    swap(matrix[i][j], matrix[x * 2 - i][y * 2 - j]);
                    swap(matrix[i][j], matrix[x - y + j][y + x - i]); 
                }
            }
            for (int j = y - 1; j >= y - r; j--)
            {
                swap(matrix[x][j], matrix[x + y - j][y]); 
                swap(matrix[x][j], matrix[x][y * 2 - j]); 
                swap(matrix[x][j], matrix[x - y + j][y]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
