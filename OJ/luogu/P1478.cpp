#include <bits/stdc++.h>
using namespace std;
struct Apple
{
    int cost;
    int height;
    Apple(int c, int h) : cost(c), height(h) {}
};
bool cmp(Apple a, Apple b)
{
    return a.cost < b.cost; //a<b时为true不交换，a>b时为false交换
}
int main()
{
    int n, s;
    cin >> n >> s;
    int a, b;
    cin >> a >> b;
    vector<Apple> apples;
    int x, y;
    for (int i = 3; i <= 2 + n; i++)
    {
        cin >> x >> y;
        apples.push_back(Apple(y, x));
    }
    int h = a + b;
    sort(apples.begin(), apples.end(), cmp);
    
    int sum = 0;
    for (auto it = apples.begin(); it != apples.end();it++)
    {
        if (h >= it->height && s >= it->cost)
        {
            s -= it->cost;
            sum++;
        }
        if(s<it->cost)
            break;
    }
    cout << sum;
}