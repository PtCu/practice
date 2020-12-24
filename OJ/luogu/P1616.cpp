#include <bits/stdc++.h>
using namespace std;
struct Stuff
{
    int v, w;
    Stuff() {}
    Stuff(const int &_w, const int &_v) : w(_w), v(_v) {}
};
vector<Stuff> stuffs;
int t, m; //t为容量，m为物品数目
const int maxn = 1e7 + 20;
long long f[maxn];
void complete_pack()
{
    long long maxV = -1;
    for (size_t i = 0; i < stuffs.size(); ++i)
    {
        for (size_t j = stuffs[i].w; j <= t; ++j)
        {
            f[j] = max(f[j], f[j - stuffs[i].w] + stuffs[i].v);
            maxV = max(f[j], maxV);
        }
    }
    cout << maxV;
}
//i=1时，计算只放第一件物品的最大价值
//i=2时，计算加上第二件物品的最大价值（在只放第一件物品的前提下）
//f[v]表示容量为v在前i种背包时所得的价值，这里我们要添加的不是前一个背包，而是当前背包，所以要考虑的是当前状态。
int main()
{
    cin >> t >> m;
    int a, b;
    for (size_t i = 0; i < m; ++i)
    {
        cin >> a >> b;
        stuffs.push_back({a, b});
    }
    complete_pack();
}