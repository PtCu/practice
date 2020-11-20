#include <bits/stdc++.h>
using namespace std;
//字符串分割函数
void split(std::string str, std::string pattern, std::vector<std::string> &result)
{
    std::string::size_type pos;

    str += pattern; //扩展字符串以方便操作
    int size = str.size();

    for (int i = 0; i < size; i++)
    {
        pos = str.find(pattern, i);
        if (pos < size)
        {
            std::string s = str.substr(i, pos - i);
            result.push_back(s);
            i = pos + pattern.size() - 1;
        }
    }
}
int main()
{
    string s;
    vector<string> result;
    string left;
    vector<string> right;
    ifstream f("test.txt");
    stringstream ss;
    while (getline(f, s))
    {
        split(s, "->", result);
        left = result[0];
        cout << left << endl;
        split(result[1], "|", right);
        result.clear();
        for (auto i : right)
        {
            cout << i << endl;
        }
        right.clear();
    }
}