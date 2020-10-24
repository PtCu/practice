#include <bits/stdc++.h>
using namespace std;
set<string> repeat; //判重

queue<string> Q;
int main()
{
    string A, B, x, y;
    unordered_map<string, string> transform;
    // int k = 0;
    cin >> A >> B;
    while (cin >> x >> y)
    {
        // k++;
        transform[x] = y;
    }
    // A = "abcd";
    // B = "xyz";
    // transform["abc"] = "xu";
    // transform["ud"] = "y";
    // transform["y"] = "yz";

    Q.push(A);
    int steps = 0;
    while (!Q.empty() && steps <= 10)
    {
        string p = Q.front();
        Q.pop();
        ++steps;
        for (auto i : transform)
        {
            string tmp(p);
            for (;;)
            {
                //找到第一个匹配的
                int pos = tmp.find(i.first);
                if (pos == tmp.npos)
                    break;
                tmp.replace(pos, i.first.length(), i.second);
                if (tmp == B)
                {
                    cout << steps;
                    return 0;
                }
                if (!repeat.count(tmp))
                {
                    Q.push(tmp);
                    repeat.insert(tmp);
                }
            }
        }
    }
    cout << "NO ANSWER";
}