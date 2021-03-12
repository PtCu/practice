#include <bits/stdc++.h>
using namespace std;
vector<int> pre;
unordered_map<int, bool> M;
void lca(int a, int b)
{
    int anc;
    for (int i = 0; i < pre.size(); ++i)
    {
        if (a <= pre[i] && pre[i] <= b || b <= pre[i] && pre[i] <= a)
        {
            anc = pre[i];
            break;
        }
    }
    if (anc == a)
        printf("%d is an ancestor of %d.\n", a, b);
    else if (anc == b)
        printf("%d is an ancestor of %d.\n", b, a);
    else
        printf("LCA of %d and %d is %d.\n", a, b, anc);
}
int main()
{
    int m, n, x;
    cin >> m >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        pre.push_back(x);
        M[x] = 1;
    }
    int a, b;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        if (!M.count(a) && !M.count(b))
            printf("ERROR: %d and %d are not found.\n", a, b);
        else if (!M.count(a))
            printf("ERROR: %d is not found.\n", a);
        else if (!M.count(b))
            printf("ERROR: %d is not found.\n", b);
        else
            lca(a, b);
    }
    return 0;
}