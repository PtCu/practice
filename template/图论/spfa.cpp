#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
struct Edge
{
    int to, cost;
};
vector<Edge> G[maxn];
int D[maxn];
int inQueue[maxn];
//在迭代n-1次后如果还可以进行松弛操作，说明一定存在负环。
//如果采用队列实现，那么当某个结点入队了n次时可以判断出存在负环，
int times[maxn]; //记录入队次数，用于检测可达负环
bool hasNegCyle;
int n, m, s;
void spfa(int s)
{
    fill(D, D + maxn, INT_MAX);
    D[s] = 0;
    queue<int> Q;
    Q.push(s);
    inQueue[s] = 1;
    times[s]++;
    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();
        inQueue[cur] = 0;
        for (int i = 0; i < G[cur].size(); ++i)
        {
            Edge e = G[cur][i];
            if (D[e.to] > D[cur] + e.cost)
            {
                D[e.to] = D[cur] + e.cost;
                //如果此时不在队列则入队
                if (!inQueue[e.to])
                {
                    times[e.to]++;     //松弛成功后不在队中才入队
                    inQueue[e.to] = 1; //入队后要标记已在队中
                    Q.push(e.to);      //并更新入队次数
                    //入队后都要检查可达负环
                    if (times[e.to] == n)
                    {
                        hasNegCyle = true;
                        return;
                    }
                }
            }
        }
    }
}
int main()
{

    cin >> n >> m >> s;
    int u, v, w;
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v >> w;
        G[u].push_back({v, w});
    }
    spfa(s);
    for (int i = 1; i <= n; ++i)
    {
        cout << D[i] << " ";
    }
}