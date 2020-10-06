#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n;
    int sum = 0;
    priority_queue<int, vector<int>, greater<int> > fruits;
    for (int i = 0; i < n; i++)
    {
        cin >> x,fruits.push(x);
    }
    while(fruits.size()>=2)
    {
        int a = fruits.top();
        fruits.pop();
        int b = fruits.top();
        fruits.pop();
        sum += a + b;
        fruits.push(a + b);
    }

    cout << sum;
}