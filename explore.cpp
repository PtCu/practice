#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int c, d;
};
vector<Node> a = {{1, 1}, {1, 1}, {1, 1}};
int main()
{
    auto begin = a.begin();
    auto end = a.end();
    auto mid = partition(begin, end, [](Node p) { return p.c < 1; });
    int a = mid - begin;
    return 0;
}