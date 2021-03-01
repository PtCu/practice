#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int weight;
    vector<int> child;
} node[101];
int s;
vector<int> path;
bool cmp(int a, int b)
{
    return node[a].weight > node[b].weight;
}
//idx：当前节点。w：到当前节点的总权重，包括当前节点
void dfs(int idx, int w)
{
    path.push_back(idx);
    if (s == w)
    {
        if (node[idx].child.size() == 0)
        {
            for (int i = 0; i < path.size(); ++i)
            {
                if (i != 0)
                    cout << " ";
                cout << node[path[i]].weight;
            }
            cout << endl;
        }
    }
    //路径权重小于题目要求，可继续往下搜索
    else if (w < s)
    {
        for (int i = 0; i < node[idx].child.size(); ++i)
        {
            int c = node[idx].child[i];
            dfs(c, w + node[c].weight);
        }
    }
     //注意！每一个结点的dfs完成后，都要将该结点从path中删除，表示途径该结点的所有路径已遍历完成
    path.pop_back();
}
int main()
{
    int n, m;
    cin >> n >> m >> s;
    for (int i = 0; i < n; ++i)
    {
        cin >> node[i].weight;
    }
    for (int i = 0; i < m; ++i)
    {
        int f, son, k;
        cin >> f >> k;
        for (int j = 0; j < k; ++j)
        {
            cin >> son;
            node[f].child.push_back(son);
        }
        //排序，为了实现题目所要求的，按照权重降序输出路径结点
        sort(node[f].child.begin(), node[f].child.end(), cmp);
    }
    dfs(0, node[0].weight);
}