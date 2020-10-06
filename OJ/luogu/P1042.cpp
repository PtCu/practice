#include <iostream>
using namespace std;
#include<string>
#include <math.h>
int main(int argc, char const *argv[])
{
    string record;
    char c = 0;
    int j = 0;
    cin >> c;
    while (c != 'E')
    {
        record+=c;
        j++;
        cin >> c;
    }
    int sW = 0, sL = 0;
    for (int i = 0; 1; i++)
    {
        if (record[i] == 'W')
            sW++;
        else if (record[i] == 'L')
            sL++;

        if ((sW >= 11 || sL >= 11) && (abs(sW - sL) >= 2))
        {
            cout << sW << ":" << sL << endl;
            sW = sL = 0;
        }
        else
        {
            if (record[i] == '\0')
            {
                cout << sW << ":" << sL << endl;
                break;
            }
        }
    }
    cout << endl;
    sL = sW = 0;
    for (int i = 0; 1; i++)
    {
        if (record[i] == 'W')
            sW++;
        else if (record[i] == 'L')
            sL++;

        if ((sW >= 21 || sL >= 21) && (abs(sW - sL) >= 2))
        {
            cout << sW << ":" << sL << endl;
            sW = sL = 0;
        }
        else
        {
            if (record[i] == '\0')
            {
                cout << sW << ":" << sL << endl;
                break;
            }
        }
    }
    return 0;
}
