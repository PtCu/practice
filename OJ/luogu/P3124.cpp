#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
struct Grass
{
    int size, position;
};
Grass hales[maxn];
int main()
{
    int ans = INT_MAX;
    int n, b;
    cin >> n >> b;
    for (int i = 1; i <= n; ++i)
    {
        cin >> hales[i].size >> hales[i].position;
    }
    hales[0].position = b;
    sort(hales + 1, hales + n + 1, [](const Grass &a, const Grass &b) { return a.position < b.position; });
    int right = upper_bound(hales + 1, hales + 1 + n, hales[0], [](const Grass &a, const Grass &b) { return a.position < b.position; }) - hales;
    int left = right - 1;
    // 注意，只能增加某一块干草的高度
    // 如果要把 bessie 堵住，必须要保证当前所在空隙两端草堆大小均大于或等于空隙长度。
    //  因此，我们若是要通过加高某一草堆把 bessie 堵住，必须满足堵住它时空隙的另一端的草堆大小大于或等于空隙长度，
    // 也就是我们需要找到第一个到此草堆的距离小于其大小的草堆，并把当前草堆的大小修改为这一距离。
    // 由于 bessie 的冲撞方向对答案有影响，我们将区间分为 bessie 左边与右边两部分进行分别处理。
    // 对于每一段区间，我们设立两个指针，一个枚举需要加高的草堆，一个指向另一端，两指针从中间开始背向移动寻找答案即可。
    //这是因为对于我们枚举的草堆，若是上一个草堆都无法与指向另一端的指针之前指向的位置匹配，
    // 这一次两者距离进一步增大，之前指向的位置就更无法满足要求，即答案满足一定的单调性。

    //i为待加高草堆，j为另一侧的。枚举右侧的i
    //每次找到从i向左侧能到达的最远距离，作为对i的最大冲击力，以此来加高i
    for (int i = right, j = left; i <= n && j > 0; ++i)
    {
        while (j > 0 && hales[i].position - hales[j].position > hales[j].size)
        {
            --j;
        }
        if (j > 0)
        {
            ans = min(ans, max(0, hales[i].position - hales[j].position - hales[i].size));
        }
    }

    //枚举左侧的i
    for (int i = left, j = right; i >= 1 && j <= n; --i)
    {
        while (j <= n && hales[j].position - hales[i].position > hales[j].size)
        {
            ++j;
        }
        if (j <= n)
        {
            ans = min(ans, max(0, hales[j].position - hales[i].position - hales[i].size));
        }
    }
    printf("%d", ans == INT_MAX ? -1 : ans);
}