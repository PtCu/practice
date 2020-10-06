#include <bits/stdc++.h>
using namespace std;
struct Burdening
{
    int s, b;
    Burdening() {}
    Burdening(int _s, int _b) : s(_s), b(_b) {}
};
vector<Burdening> sources;
int ans = 0x7fffffff;
int n;
void dfs(int i, int s, int b)
{
    if (i >= n)
    {
        if (s == 1 && b == 0)
            return;
        ans = min(abs(s - b), ans);
        return;
    }
    //添加
    dfs(i + 1, s * sources[i].s, b + sources[i].b);
    //不添加
    dfs(i + 1, s, b);
}

int main()
{

    cin >> n;
    int s, b;

    for (int i = 0; i < n; i++)
    {
        cin >> s >> b;
        sources.push_back(Burdening(s, b));
    }
    dfs(0, 1, 0);
    cout << ans;
}