#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
struct Node
{
    int ID;
    int virtue, talent;
    int type;
} nodes[maxn];
int n, l, h;
bool cmp(const Node &a, const Node &b)
{
    if (a.type != b.type)
    {
        return a.type < b.type;
    }
    else if (a.talent + a.virtue != b.talent + b.virtue)
    {
        return a.talent + a.virtue > b.talent + b.virtue;
    }
    else if(a.virtue!=b.virtue)
    {
        return a.virtue > b.virtue;
    }
    else{
        return a.ID < b.ID;
    }
}
int main()
{
    int t_v, t_t, t_id;
    cin >> n >> l >> h;
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> t_id >> t_v >> t_t;
        if (t_v >= l && t_t >= l)
        {
            nodes[cnt].ID = t_id;
            nodes[cnt].virtue = t_v;
            nodes[cnt].talent = t_t;
            if (t_v >= h && t_t >= h)
            {
                nodes[cnt].type = 1;
            }
            else if (t_v >= h && t_t < h)
            {
                nodes[cnt].type = 2;
            }
            else if (t_v < h && t_v >= t_t)
            {
                nodes[cnt].type = 3;
            }
            else
            {
                nodes[cnt].type = 4;
            }
            ++cnt;
        }
    }
    sort(nodes, nodes + cnt, cmp);
    cout << cnt << endl;
    for (int i = 0; i < cnt; ++i)
    {
        printf("%08d %d %d\n", nodes[i].ID, nodes[i].virtue, nodes[i].talent);
    }
}