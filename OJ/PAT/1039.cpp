#include <bits/stdc++.h>
using namespace std;
unordered_map<string, set<int>> M;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    string name;
    int course, num;
    for (int i = 0; i < k; ++i)
    {
        cin >> course >> num;
        for (int j = 0; j < num; ++j)
        {
            cin >> name;
            M[name].insert(course);
        }
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> name;
        cout << name ;
        cout << " "<<M[name].size();
        if (M[name].size() != 0)
            for (auto iter = M[name].begin(); iter != M[name].end(); ++iter)
            {
                cout <<" "<< *iter;
            }
        cout << endl;
    }
}