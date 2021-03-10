#include <bits/stdc++.h>
using namespace std;
const int maxn = 520;
vector<int> G[maxn];
int degree[maxn];
bool visited[maxn];
int n, m;
int sum;
void dfs(int x)
{
    if (visited[x])
        return;
    // if (sum == n)
    //     return;
    visited[x] = 1;
    // sum++;

    for (int i = 0; i < G[x].size();++i){
        dfs(G[x][i]);
    }
}
int main()
{

    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }

    bool isEuler = true;
    bool isSemi = false;
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (degree[i] % 2 != 0)
        {
            isEuler = false;
            cnt++;
        }
    }
    if (cnt == 2)
    {
        isSemi = true;
    }
    cout << degree[1];
    for (int i = 2; i <= n; ++i)
    {
        cout << " " << degree[i];
    }
    cout << endl;

    int con = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            dfs(i);
            con++;
        }
    }

    if (con != 1)
    {
        cout << "Non-Eulerian";
        return 0;
    }

    if (isEuler)
    {
        cout << "Eulerian";
    }
    else if (isSemi)
    {
        cout << "Semi-Eulerian";
    }
    else
    {
        cout << "Non-Eulerian";
    }
}