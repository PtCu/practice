#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
vector<int> tree[maxn + 5]; //tree[i]表示节点i的相邻节点
int d[maxn + 5];            //d[i]表示以i为根的节点的个数
int N;                      //节点总数
int minNode;
int minBalance = INT32_MAX;
void dfs(int node, int parent)
{
    d[node] = 1;
    int maxSubTree = 0;
    for (size_t i = 0; i < tree[node].size(); ++i)
    {
        size_t son = tree[node][i];
        if (son != parent)
        {
            dfs(son, node);
            d[node] += d[son];
            maxSubTree = max(maxSubTree, d[son]);
        }
    }
    maxSubTree = max(maxSubTree, N - d[node]);
    if (maxSubTree < minBalance)
    {
        minBalance = maxSubTree;
        minNode = node;
    }
}
int nodes[maxn];
bool visited[maxn];
int ans = 0;
void dfs2(int step, int node)
{
    ans += step * nodes[node];

    for (size_t i = 0; i < tree[node].size(); ++i)
    {
        if (!visited[tree[node][i]])
        {
            visited[tree[node][i]] = true;
            dfs2(step + 1, tree[node][i]);
        }
    }
}
// struct Node
// {
//     int V;
//     int d; //距离
//     Node() : V(0), d(0) {}
// };
// Node nodes[maxn];
// bool visited[maxn];
// int bfs(int root)
// {
//     queue<int> Q;
//     Q.push(root);
//     visited[root] = true;
//     int sum = 0;
//     while (!Q.empty())
//     {
//         int p = Q.front();
//         Q.pop();
//         //p的所有邻居
//         for (size_t i = 0; i < tree[p].size(); ++i)
//         {
//             if (!visited[tree[p][i]])
//             {
//                 visited[tree[p][i]] = true;
//                 nodes[tree[p][i]].d = nodes[p].d + 1;
//                 sum += nodes[tree[p][i]].d * nodes[tree[p][i]].V;
//                 Q.push(tree[p][i]);
//             }
//         }
//     }
//     return sum;
// }
int main()
{

    cin >> N;
    int x, y, z;
    for (size_t i = 1; i <= N; ++i)
    {
        cin >> x >> y >> z;
        nodes[i] = x;
        if (y)
        {
            tree[i].push_back(y);
            tree[y].push_back(i);
        }
        if (z)
        {
            tree[i].push_back(z);
            tree[z].push_back(i);
        }
    }
    dfs(1, 0);
    visited[minNode] = true;
    dfs2(0, minNode);
    cout << ans;
}