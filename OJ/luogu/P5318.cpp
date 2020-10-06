#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;

std::vector<int> G[MAXN];
int n, m;
bool visited[MAXN];
queue<int> q;

void dfs(int x, int cur) {//x指当前所在的节点，cur指已遍历过的节点个数
    visited[x] = true;//标记以避免重复访问
    cout << x << " ";//输出
    if (cur == n) return ;
    for (int i=0; i<G[x].size(); i++)
        if (!visited[G[x][i]]) dfs(G[x][i], cur+1);//记得要判断是否遍历过
}

void bfs(int x) {
    memset(visited, false, sizeof(visited));//记得一定要清空
    visited[x] = true;
    q.push(x);
    while (!q.empty()) {
        int v = q.front();
        q.pop();//记得要弹出，否则会一直在第一层遍历
        cout << v << " ";//输出
        for (int i=0; i<G[v].size(); i++) 
            if (!visited[G[v][i]]) {
                visited[G[v][i]] = true;
                q.push(G[v][i]);//记得要入队
            }
    }
}

int main() {
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);//标准邻接表建有向图
    }
    for (int i=1; i<=n; i++) sort(G[i].begin(), G[i].end());//标准vector排序
    dfs(1, 0);
    cout << endl;
    bfs(1);
    cout << endl;
    return 0;
}