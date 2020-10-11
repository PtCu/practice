#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int floor;
    int distance;
    int count;
    bool visited;
    Node() {}
    Node(const int &ff, const int &fd, const int &fc = 0, const bool &fvisited = false) : floor(ff), distance(fd), count(fc), visited(fvisited) {}
};

int main()
{
    int N, A, B, x;
    cin >> N >> A >> B;
    vector<Node> source;
    source.push_back(Node());
    for (int i = 1; i <= N; i++)
    {
        cin >> x;
        source.push_back(Node(i, x));
    }
    queue<Node> Q;
    Q.push(source[A]);
    Node p;
    while (!Q.empty())
    {
        p = Q.front();
        Q.pop();
        if(p.floor==B)
            break;
        if (p.floor + p.distance <= N)
        {
            int q = p.floor + p.distance;
            if (!source[q].visited)
            {
                source[q].visited = true;
                source[q].count = p.count + 1;
                Q.push(source[q]);
                
            }
        }
        if (p.floor - p.distance >= 1)
        {
            int q = p.floor - p.distance;
            if (!source[q].visited)
            {
                source[q].visited = true;
                source[q].count = p.count + 1;
                Q.push(source[q]);
            }
        }
    }
    if(p.floor==B)
        cout << p.count;
    else
        cout << -1;
}