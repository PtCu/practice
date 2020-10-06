#include <bits/stdc++.h>
using namespace std;
struct Point
{
    int x;
    int y;
    Point(int a, int b) : x(a), y(b) {}
    bool operator<(const Point &rhs) const
    {
        if (x == rhs.x)
            return y < rhs.y;
        return x < rhs.x;
    }
};
set<Point> pts;
bool find(int x, int y)
{
    if (pts.find(Point(x, y)) != pts.end())
        return true;
    return false;
}
int main()
{

    int n;
    cin >> n;
    int x, y;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        pts.insert(Point(x, y));
    }
    int ans[5];
    memset(ans, 0, sizeof(ans));
    set<Point>::iterator it; //set用迭代器遍历
    for (it = pts.begin(); it != pts.end(); it++)
    {
        x = (*it).x;
        y = (*it).y;
        if (find(x, y + 1) && find(x, y-1) && find(x + 1, y) && find(x-1, y))
        {
            int cnt = 0;
            if (find(x - 1, y - 1))
                cnt++;
            if (find(x + 1, y - 1))
                cnt++;
            if (find(x - 1, y + 1))
                cnt++;
            if (find(x + 1, y + 1))
                cnt++;
            ans[cnt]++;
        }
    }
    for (int i = 0; i < 5; i++)
        cout << ans[i] << endl;
    return 0;
}

