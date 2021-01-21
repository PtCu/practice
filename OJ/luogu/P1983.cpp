#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
vector<int> G[maxn];
bool cache[maxn];
vector<int> stop;
void topo()
{
    
}
int main()
{
    int n, m;
    cin >> n >> m;
    int s, x;
    for (size_t i = 0; i < m; ++i)
    {
        memset(cache, 0, sizeof(cache));
        stop.clear();
        cin >> s;
        for (size_t j = 1; j <= s; ++j)
        {
            cin >> x;
            stop.push_back(x);
            cache[x] = 1;
        }
        for (size_t j = 1; j <= s; ++j)
        {
            if (!cache[j])
            {
                for (auto k : stop)
                {
                    G[k].push_back(j); //k到j的连线
                }
            }
        }
    }
}