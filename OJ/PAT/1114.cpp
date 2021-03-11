#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
int f[maxn];
int Find(int x)
{
    if (x == f[x])
        return x;
    return f[x] = Find(f[x]);
}
struct Family
{
    int id;
    int ppl_num;
    double area;
    double estate_num;
} nodes[maxn], fina[maxn];
//较小者为老大。
void Union(int a, int b)
{
    // if (a < b)
    //     swap(a, b);
    // f[Find(a)] = Find(b);
    
    int fa = Find(a);
    int fb = Find(b);
    if (fa == fb)
        return;
    if (fa < fb)
        swap(fa, fb);
    f[fa] = fb;
    //转移财产

    nodes[fb].area += nodes[fa].area;
    nodes[fb].estate_num += nodes[fa].estate_num;
    // cout << "  " << fa << " to " << fb << " " << nodes[fa].area << " " << nodes[fa].estate_num << endl;
    // cout << "  " << fb << " now is " << nodes[fb].area << " " << nodes[fb].estate_num << endl;
    nodes[fa].area = 0;
    nodes[fa].estate_num = 0;
}

int ans[maxn];
bool cmp(const Family &a, const Family &b)
{
    double av = a.area / a.ppl_num;
    double bv = b.area / b.ppl_num;
    if (av != bv)
        return av > bv;
    else
        return a.id < b.id;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int id, father, mother, k, x;
    double m_estate, area;
    for (int i = 1; i < maxn; ++i)
    {
        f[i] = i;
    }
    unordered_set<int> s;
    for (int i = 0; i < n; ++i)
    {
        cin >> id >> father >> mother >> k;
        s.insert(id);
        if (father != -1)
        {
            s.insert(father);
            Union(id, father);
        }
        if (mother != -1)
        {
            s.insert(mother);
            Union(id, mother);
        }
        for (int j = 0; j < k; ++j)
        {
            cin >> x;
            s.insert(x);
            Union(id, x);
        }
        cin >> m_estate >> area;
        nodes[Find(id)].area += area;
        nodes[Find(id)].estate_num += m_estate;
    }
    int cnt = 0;

    for (auto a : s)
    {
        if (a == f[a])
        {
            ans[cnt++] = a;
        }
        nodes[Find(a)].ppl_num++;
    }
    for (int i = 0; i < cnt; ++i)
    {
        fina[i].id = ans[i];
        fina[i].area = nodes[ans[i]].area;
        fina[i].estate_num = nodes[ans[i]].estate_num;
        fina[i].ppl_num = nodes[ans[i]].ppl_num;
    }
    sort(fina, fina + cnt, cmp);
    cout << cnt << endl;
    for (int i = 0; i < cnt; ++i)
    {
        printf("%04d %d %.3lf %.3lf\n", fina[i].id, fina[i].ppl_num, fina[i].estate_num / fina[i].ppl_num, fina[i].area / fina[i].ppl_num);
    }
}
