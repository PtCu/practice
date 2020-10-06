#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    queue< pair<int, int> > q;
    for (int i = 1; i <= (1 << n); i++)
    {
        int x;
        cin >> x;
        q.push(make_pair(i, x));
    }
    //queue的pop()并不返回任何值
    while (q.size() > 2)
    {
        pair<int, int> a, b;
        a = q.front();
        q.pop();
        b = q.front();
        q.pop();
        if (a.second > b.second)
            q.push(a);
        else
            q.push(b);
    }
    pair<int, int> a, b;
    a = q.front();
    q.pop();
    b = q.front();
    if (a.second > b.second)
        cout << b.first;
    else
        cout << a.first;

    return 0;
}
