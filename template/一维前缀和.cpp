//P3406
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
struct Node
{
    long long a, b, c;
} nodes[maxn];
long long cnt[maxn];
long long vis[maxn];
int main()
{
    int n, m;
    int last, cur;
    cin >> n >> m >> last;
    for (int i = 2; i <= m; ++i)
    {
        cin >> cur;
        cnt[min(last, cur)]++;
        cnt[max(last, cur)]--;
        last = cur;
    }
    for (int i = 1; i < n; ++i)
    {
        vis[i] += cnt[i];
    }
    long long ans = 0;
    for (int i = 1; i < n; ++i)
    {
        cin >> nodes[i].a >> nodes[i].b >> nodes[i].c;
        ans += min(vis[i] * nodes[i].a, vis[i] * nodes[i].b + nodes[i].c);
    }
    cout << ans;
}