#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
unordered_map<string, set<string>> title2id;
unordered_map<string, set<string>> author2id;
unordered_map<string, set<string>> key2id;
unordered_map<string, set<string>> pub2id;
unordered_map<string, set<string>> year2id;
int main()
{
    int n;
    cin >> n;
    string id, title, author, keywords, pub, year, keyword;
    stringstream ss;
    for (int i = 0; i < n; ++i)
    {
        cin >> id;
        getline(cin, title);
        getline(cin, title);
        getline(cin, author);
        title2id[title].insert(id);
        author2id[author].insert(id);
        getline(cin, keywords);
        ss.clear();
        ss.str(keywords);
        while (getline(ss, keyword, ' '))
        {
            key2id[keyword].insert(id);
        }
        getline(cin, pub);
        cin >> year;
        pub2id[pub].insert(id);
        year2id[year].insert(id);
       
        
    }
    int m;
    cin >> m;
    char tmp[80];
    int mode;
    string s;
    set<string> p;
    for (int i = 0; i < m; ++i)
    {
        cin >> mode;
        getline(cin, s);
        s = s.substr(2, s.size() - 2);
        if (mode == 1)
        {
            p = title2id[s];
        }
        else if (mode == 2)
        {
            p = author2id[s];
        }
        else if (mode == 3)
        {
            p = key2id[s];
        }
        else if (mode == 4)
        {
            p = pub2id[s];
        }
        else if (mode == 5)
        {
            p = year2id[s];
        }
        cout << mode << ": " << s << endl;
        if (!p.empty())
            for (auto iter = p.begin(); iter != p.end(); ++iter)
            {
                cout << *iter << endl;
            }
        else
            cout << "Not Found" << endl;
    }
}