#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000;
vector<int> tree[maxn + 5]; //tree[i]表示节点i的相邻节点
int d[maxn + 5];            //d[i]表示以i为根的子树的节点个数
int N;
int minNode;
int minBalance;

void dfs(int node, int parent)
{
    d[node] = 1;        //the node itself
    int maxSubTree = 0; //subtree that has the most number of nodes
    for (int i = 0; i < tree[node].size(); ++i)
    {
        int son = tree[node][i];
        if (son != parent)
        {
            dfs(son, node);
            d[node] += d[son];
            maxSubTree = max(maxSubTree, d[son]);
        }
    }
    maxSubTree = max(maxSubTree, N - d[node]); //upside subtree with N-d[node] nodes
    if (maxSubTree < minBalance)
    {
        minBalance = maxSubTree;
        minNode = node;
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &N);
        for (int i = 1; i <= N - 1; i++)
        {
            tree[i].clear();
        }
        for (int i = 1; i <= N - 1; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        minNode = 0;
        minBalance = INT32_MAX;
        dfs(1, 0); // fist node as root
        printf("%d %d\n", minNode, minBalance);
    }
    return 0;
}