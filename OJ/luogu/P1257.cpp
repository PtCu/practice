#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 5;
struct Point
{
    double x, y;
    Point(const double &a, const double &b) : x(a), y(b) {}
};
vector<Point> source;
double dis(const vector<Point>::iterator &left, const vector<Point>::iterator &right)
{
    return sqrt((right->x - left->x) * (right->x - left->x) + (right->y - left->y) * (right->y - left->y));
}
//[left,right]
vector<Point>::iterator mid_points[maxn];
double solve(vector<Point>::iterator left, vector<Point>::iterator right)
{
    if (left == right)
        return numeric_limits<double>::infinity();
    if (left + 1 == right)
    {
        return dis(left, right);
    }
    vector<Point>::iterator mid = left + (right - left) / 2;
    double d = min(solve(left, mid), solve(mid + 1, right));
    double L = mid->x;
    //分离出宽度为d的区间
    int k = 0;
    for (auto iter = left; iter <= right; ++iter)
    {
        if (fabs(iter->x - L) < d)
        {
            mid_points[k++] = iter;
        }
    }
    sort(mid_points, mid_points + k, [](const vector<Point>::iterator &a, const vector<Point>::iterator &b) { return a->y < b->y; });
    for (int i = 0; i < k; ++i)
    {
        for (int j = i + 1; j < k && j <= i + 11; ++j)
        {
            d = min(d, dis(mid_points[i], mid_points[j]));
        }
    }
    return d;
}
int main()
{
    int n;
    cin >> n;
    double x, y;
    for (int i = 0; i < n; ++i)
    {
        cin >> x >> y;
        source.push_back({x, y});
    }
    sort(source.begin(), source.end(), [](const Point &a, const Point &b) -> bool { return a.x < b.x; });
    cout<<setiosflags(ios::fixed)<<setprecision(4)<<solve(source.begin(), source.end() - 1);

}