#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
unordered_map<string, string> f;

string Find(const string &a)
{
    if (a == f[a])
        return a;
    return f[a] = Find(f[a]);
}
void Union(const string &a, const string &b)
{
    f[Find(a)] = f[b];
}

int main()
{
    char c;
    string father_name;
    string child_name;
    while (cin >> c)
    {
        if (c == '$')
        {
            break;
        }
        else if (c == '#')
        {
            cin >> father_name;
            if (!f.count(father_name))
                f[father_name] = father_name;
        }
        else if (c == '+')
        {
            cin >> child_name;
            if (!f.count(child_name))
                f[child_name] = child_name;
            Union(child_name, father_name);
        }
        else if (c == '?')
        {
            cin >> child_name;
            cout << child_name << " " << Find(child_name) << endl;
        }
    }
    return 0;
}