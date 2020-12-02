#include <bits/stdc++.h>
using namespace std;
vector<int> nodes;
int n;
const int maxn = 20;
void build(int n)
{
    nodes.resize(maxn);
    nodes[0] = 1;
    for (size_t i = 0; i < n; ++i)
    {
        nodes[2 * i + 1] = 1;
        nodes[2 * i + 2] = 1;
    }
}
void eraseNode(int x, int y)
{
    int index = (1 << (x - 1)) - 1 + y;
    queue<int> Q;
    Q.push(index);
    while (!Q.empty())
    {
        int p = Q.front();
        nodes[p] = -1;
        if (2 * index + 1 < n)
            Q.push(2 * index + 1);
        if (2 * index + 2 < n)
            Q.push(2 * index + 2);
    }
}
void print()
{
    size_t index;
    for (index = maxn; index >= 0; --index)
    {
        if (nodes[index] == 1)
            break;
    }
    int level = (int)log2(index) + 1;
    int width = (1 << (level - 1)) + (1 << level) - 1;
    int height = 3 * (1 << (level - 2));
    int depth = 1;
    int extra = level >> 1;
    int cur = 1;
    for (size_t i = 1; i <= height; ++i)
    {
        if (i == cur + extra || i == 1)
        {
            cur += extra;
            extra >>= 1;
            for (size_t j = 1; j <= width; ++j)
            {
                
                    cout << "o";
                cout << " ";
            }
            cout << endl;
            ++depth;
        }
        else
            cout << endl;
    }
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int m, x, y;
    cin >> m >> n;
    build(m);
    while (n--)
    {
        cin >> x >> y;
        eraseNode(x, y);
    }
    print();
}