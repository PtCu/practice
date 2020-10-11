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
vector<Node> source;
int N, A, B;
int ans = INT_MAX;
void dfs(int i)
{
    if (i == B)
    {
        ans = min(ans,source[i].count);
        return;
    }
    if(source[i].count>ans)
        return;
    source[i].visited = true;
    if (i + source[i].distance <= N && !source[i + source[i].distance].visited)
    {
        source[i + source[i].distance].count = source[i].count + 1;
        dfs(i + source[i].distance);
    }
    if (i - source[i].distance >= 1 && !source[i -source[i].distance].visited)
    {
        source[i - source[i].distance].count = source[i].count + 1;
        dfs(i - source[i].distance);
    }
    source[i].visited = false;  //dfs改变一个点状态后一定要回溯
}
int main()
{

    cin >> N >> A >> B;
    int x;
    source.push_back(Node());
    for (int i = 1; i <= N; i++)
    {
        cin >> x;
        source.push_back(Node(i, x));
    }
    dfs(A);
    if (ans != INT_MAX)
        cout << ans;
    else
        cout << -1;
}