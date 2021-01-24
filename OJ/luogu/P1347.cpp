#include <bits/stdc++.h>
using namespace std;
const int maxn = 30;
vector<char> G[maxn];
int indgree[maxn];
int n, m;
void topo()
{
    //TODO:
}
int main()
{
    cin >> n >> m;
    char a, b, c;
    fill(indgree, indgree + n, -1);
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> c >> b;
        if (indgree[a - 'A'] == -1)
            indgree[a - 'A']++;
        if (indgree[b - 'A'] == -1)
            indgree[b - 'A']++;

        G[a - 'A'].push_back(b - 'A');
        indgree[b - 'A']++; //边输入边判断
        topo();
    }

    queue<char> Q;
    vector<char> ans;
    for (int i = 0; i < n; ++i)
    {
        if (!indgree[i])
        {
            Q.push(i);
            ans.push_back(i);
        }
    }
    while (!Q.empty())
    {
        int p = Q.front();
        Q.pop();
        for (int i = 0; i < G[p].size(); ++i)
        {
            if (!--indgree[G[p][i]])
            {
                Q.push(G[p][i]);
                ans.push_back(G[p][i]);
            }
        }
    }

    if (ans.size() == n)
    {
        cout << "Sorted sequence determined after " << n << " relations:";
        for (auto a : ans)
        {
            cout << (char)(a + 'A');
        }
        cout << "." << endl;
        return 0;
    }
    else if (ans.size() < n)
    {
        cout << "Sorted sequence cannot be determined. "
             << endl;
        return 0;
    }
}