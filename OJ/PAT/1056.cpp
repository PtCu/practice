#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
struct Node
{
    int weight;
    int id;
    Node() {}
    Node(int w, int i) : weight(w), id(i) {}
} nodes[maxn];
int place[maxn];
int order[maxn];
int main()
{
    int n_p, n_g;
    cin >> n_p >> n_g;
    for (int i = 0; i < n_p; ++i)
    {
        cin >> nodes[i].weight;
        nodes[i].id = i;
    }
    queue<Node> Q;
    for (int i = 0; i < n_p; ++i)
    {
        cin >> order[i];
        Q.push(nodes[order[i]]);
    }
    while (Q.size() != 1)
    {
        int num = Q.size();
        int group = num / n_g;
        if (num % n_g)
            group++;
        for (int j = 0; j < group; ++j)
        {
            Node cur_max=Q.front();
            for (int i = 0; j * n_g + i < num && i < n_g; ++i)
            {
                Node p = Q.front();
                Q.pop();
                if (p.weight > cur_max.weight)
                {
                    place[cur_max.id] = group + 1;
                    cur_max = p;
                }
                else
                {
                    place[p.id] = group + 1;
                }
            }
            Q.push(cur_max);
        }
    }
    place[Q.front().id] = 1;
    cout << place[0];
    for (int i = 1; i < n_p; ++i)
    {
        cout <<" "<< place[i] ;
    }
}