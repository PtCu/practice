#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
vector<int> G[maxn];

int main()
{
    int n, m;
    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m;++i){
        cin >> u >> v;
        G[u].push_back(v);
    }
}