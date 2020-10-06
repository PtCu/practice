#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x.begin())
using namespace std;
typedef set<int> Set;
map<Set, int> IDcache;  //用set找ID
vector<Set> Setcache;   //用ID找set
//每个集合都用一个唯一的ID来表示，
int findID(Set x)
{ //利用IDcache来找到对应的ID
    if (IDcache.count(x))
        return IDcache[x];
    Setcache.push_back(x);
    return IDcache[x] = Setcache.size() - 1;    //ID为在vector的坐标
}
int main()
{
    stack<int> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string op;
        cin >> op;
        if (op[0] == 'P')
            s.push(findID(Set())); //push:空集{}入栈
        else if (op[0] == 'D')
            s.push(s.top()); //把当前栈顶元素复制一部分然后入栈
        else
        {
            Set x1 = Setcache[s.top()];
            s.pop();
            Set x2 = Setcache[s.top()];
            s.pop();
            Set x;
            if (op[0] == 'A')
            {
                x = x2;
                x.insert(findID(x1));
            }
            else if (op[0] == 'U')
            {
                set_union(ALL(x1), ALL(x2), INS(x));
            }
            else if (op[0] == 'I')
            {
                set_intersection(ALL(x1), ALL(x2), INS(x));
            }
            s.push(findID(x));
        }
        cout << Setcache[s.top()].size() << '\n';
    }
}
