#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> M;
int main()
{
    int n, opt, score;
    string name;
    cin >> n;
    while (n--)
    {
        cin >> opt;
        if (opt == 1)
        {
            cin >> name >> score;
            M[name] = score;
            cout << "OK" << endl;
        }
        else if (opt == 2)
        {
            cin >> name;
            if (!M.count(name))
            {
                cout << "Not found" << endl;
            }
            else
            {
                cout << M[name] << endl;
            }
        }
        else if (opt == 3)
        {
            cin >> name;
            if (!M.count(name))
            {
                cout << "Not found" << endl;
            }
            else
            {
                M.erase(name);
                cout << "Deleted successfully" << endl;
            }
        }
        else if (opt == 4)
        {
            cout << M.size()<<endl;
        }
    }
}