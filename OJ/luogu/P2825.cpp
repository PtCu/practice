#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4;
int N, K, M;
vector<int> G[maxn];
bool hasCow[maxn];
bool visited[maxn];
void dfs(int x, int& remain)
{
    if (hasCow[x])
        remain -= 1;
    for (size_t i = 0; i < G[x].size(); ++i)
    {
        if (!visited[G[x][i]])
        {
            visited[G[x][i]] = true;
            dfs(G[x][i], remain);
        }
    }
}
int main()
{

    cin >> K >> N >> M; //k个奶牛，N个牧场，M条路
    int x;
    for (size_t i = 1; i <= K; ++i)
    {
        cin >> x;
        hasCow[x] = true;
    }
    int a, b;
    for (size_t i = 0; i < M; ++i)
    {
        cin >> a >> b;
        G[b].push_back(a);
    }
    int ans = 0;
    for (size_t i = 1; i <= M;++i){
        memset(visited, 0, sizeof(visited));
        int remain = K;
        dfs(i, remain);
        if(remain==0)
            ans++;
    }
    cout << ans;
}
