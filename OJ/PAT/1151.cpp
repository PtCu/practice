#include <bits/stdc++.h>
using namespace std;
vector<int> in, pre;
unordered_map<int, int> M_in;
int n;
void lca(int in_l, int in_r, int pre_root, int a, int b)
{
    if (in_l > in_r)
        return;
    int in_root = M_in[pre[pre_root]];
    int in_a = M_in[a];
    int in_b = M_in[b];
    //在左子树搜索。跳过右子树部分
    if (in_root > in_a && in_root > in_b)
        lca(in_l, in_root - 1, pre_root + 1, a, b);
    else if ((in_a < in_root && in_b > in_root) || (in_a > in_root && in_b < in_root))
        printf("LCA of %d and %d is %d.\n", a, b, in[in_root]);
    //在右子树。跳过左子树部分
    else if (in_root < in_a && in_root < in_b)
        lca(in_root + 1, in_r, pre_root + 1 + (in_root - in_l), a, b);
    else if (in_a == in_root)
        printf("%d is an ancestor of %d.\n", a, b);
    else if (in_b == in_root)
        printf("%d is an ancestor of %d.\n", b, a);
}
int main()
{
    int m, x;
    cin >> m >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        M_in[x] = i;
        in.push_back(x);
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        pre.push_back(x);
    }
    int a, b;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        if (!M_in.count(a) && !M_in.count(b))
        {
            printf("ERROR: %d and %d are not found.\n", a, b);
        }
        else if (!M_in.count(a))
        {
            printf("ERROR: %d is not found.\n", a);
        }
        else if (!M_in.count(b))
        {
            printf("ERROR: %d is not found.\n", b);
        }
        else
            lca(0, n-1, 0, a, b);
    }
    return 0;
}