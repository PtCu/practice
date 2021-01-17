#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10;
int N, K, M;
vector<int> G[maxn];
int hasCow[maxn];
bool visited[maxn];
int nums[maxn]; //记录每个顶点被遍历的次数
void dfs(int x)
{
    visited[x] = true;
    nums[x]++;
    for (size_t i = 0; i < G[x].size(); ++i)
    {
        if (!visited[G[x][i]])
        {
            dfs(G[x][i]);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> K >> N >> M; //k个奶牛，N个牧场，M条路
    int x;
    for (size_t i = 1; i <= K; ++i)
    {
        cin >> hasCow[i];
    }
    int a, b;
    for (size_t i = 0; i < M; ++i)
    {
        cin >> a >> b;
        G[a].push_back(b);
    }
    int ans = 0;
    for (size_t i = 1; i <= K; ++i)
    {
        memset(visited, 0, sizeof(visited));
        dfs(hasCow[i]);
    }
    for (size_t i = 1; i <= N; ++i)
    {
        if (nums[i] == K)
            ++ans;
    }
    cout << ans;
}
