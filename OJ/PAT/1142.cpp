#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;
int G[maxn][maxn];
set<int> source;
int ne, nv, m, k;
int query(set<int> &source)
{
    //Not clique
    for (auto i : source)
    {
        for (auto j : source)
        {
            if (i != j)
                if (!G[i][j])
                    return -1;
        }
    }

    bool isMax = false;
    for (int i = 1; i <= nv; ++i)
    {
        if (!source.count(i))
        {
            //假设有点可以扩展
            isMax = false;
            for (auto j : source)
            {
                if (!G[i][j])
                {
                    //添加该点无法构成clique
                    isMax = true;
                    break;
                }
            }
            //Not Max
            if (!isMax)
                return 0;
        }
    }

    return 1;
}

int main()
{

    cin >> nv >> ne;
    int a, b;
    for (int i = 0; i < ne; ++i)
    {
        cin >> a >> b;
        G[a][b] = G[b][a] = 1;
    }
    int x;
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> k;
        source.clear();
        for (int j = 0; j < k; ++j)
        {
            cin >> x;
            source.insert(x);
        }
        int ans = query(source);
        if (ans == -1)
        {
            cout << "Not a Clique" << endl;
        }
        else if (ans == 0)
        {
            cout << "Not Maximal" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }
}