#include <bits/stdc++.h>

const int XN = 5e5 + 11;

struct Point
{
    int x, y;
} p[XN];

int Ans[XN];
struct Event
{
    int x, y1, y2, id, type;
} ev[XN * 2];

std::vector<int> dey;
int a[XN];
void Add(int pos, int v)
{
    for (; pos <= (int)dey.size(); pos += pos & -pos)
        a[pos] += v;
}

int Sum(int pos)
{
    int res = 0;
    for (; pos; pos -= pos & -pos)
        res += a[pos];
    return res;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        int x, y;
        std::cin >> x >> y;
        p[i] = {x + y, x - y};
        dey.push_back(p[i].y);
    }
    std::sort(dey.begin(), dey.end());
    dey.erase(std::unique(dey.begin(), dey.end()), dey.end());
    std::sort(p + 1, p + 1 + n, [](auto const &a, auto const &b) -> bool { return a.x < b.x; });
    for (int i = 1; i <= m; ++i)
    {
        int x, y, r;
        std::cin >> x >> y >> r;
        std::tie(x, y) = std::make_pair(x + y, x - y);
        ev[i] = {x - r - 1, y - r, y + r, i, -1};
        ev[i + m] = {x + r, y - r, y + r, i, 1};
    }
    std::sort(ev + 1, ev + 1 + m * 2, [](auto const &a, auto const &b) -> bool { return a.x < b.x; });
    int ip = 1, ie = 1;

    while (ie != 2 * m + 1)
    {
        while (ip != n + 1 && p[ip].x <= ev[ie].x)
        {
            Add(std::lower_bound(dey.begin(), dey.end(), p[ip].y) - dey.begin() + 1, 1);
            ip++;
        }
        Ans[ev[ie].id] += ev[ie].type * (Sum(std::upper_bound(dey.begin(), dey.end(), ev[ie].y2) - dey.begin()) - Sum(std::lower_bound(dey.begin(), dey.end(), ev[ie].y1) - dey.begin()));
        ie++;
    }
    for (int i = 1; i <= m; ++i)
        std::cout << Ans[i] << '\n';
    return 0;
}
