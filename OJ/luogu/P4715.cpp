#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int x;
    queue<pair<int, int> > Q;
    for (size_t i = 1; i <= (1 << n); ++i)
    {
        cin >> x;
        Q.push(make_pair(i, x));
    }
    pair<int, int> first_p, second_p;
    while (Q.size() > 2)
    {
        first_p = Q.front();
        Q.pop();
        second_p = Q.front();
        Q.pop();
        if (second_p.second > first_p.second)
            Q.push(second_p);
        else
            Q.push(first_p);
    }

    first_p = Q.front();
    Q.pop();
    second_p = Q.front();
    Q.pop();
    if (first_p.second > second_p.second)
    {
        cout << second_p.first<<endl;
    }
    else
    {
        cout << first_p.first<<endl;
    }
}