#include <bits/stdc++.h>
using namespace std;
#define LChild(x) (2 * x + 1)
#define RChild(x) (2 * (x + 1))
#define Parent(x) (((x)-1) / 2)
const int maxn = 1e3+20;
int source[maxn];
int a[maxn];
int cnt;
int n;
// void pre_order(int x)
// {
//     if (x >= n)
//         return;
//     a[x] = source[cnt++];
//     pre_order(LChild(x));
//     pre_order(RChild(x));
// }
int isHeap()
{
    queue<int> Q;
    Q.push(0);
    //1为大顶堆，-1为小顶堆
    int type = 0;
    while (!Q.empty())
    {
        auto p = Q.front();
        Q.pop();
        if (LChild(p) < n)
        {
            if (type == 1 && a[LChild(p)] > a[p])
                return 0;
            if (type == -1 && a[LChild(p)] < a[p])
                return 0;
            if (a[LChild(p)] > a[p])
                type = -1;
            else if (a[LChild(p)] < a[p])
                type = 1;
            Q.push(LChild(p));
        }
        if (RChild(p) < n)
        {
            if (type == 1 && a[RChild(p)] > a[p])
                return 0;
            if (type == -1 && a[RChild(p)] < a[p])
                return 0;
            if (a[RChild(p)] > a[p])
                type = -1;
            else if (a[RChild(p)] < a[p])
                type = 1;
            Q.push(RChild(p));
        }
    }
    return type;
}
vector<int> ans;
void postorder(int x)
{
    if (x >= n)
        return;
    postorder(LChild(x));
    postorder(RChild(x));
    ans.push_back(a[x]);
}
void init()
{
    cnt = 0;
    memset(source, 0, sizeof(source));
    memset(a, 0, sizeof(a));
    ans.clear();
}
int main()
{
    int m, x;
    cin >> m >> n;
    for (int i = 0; i < m; ++i)
    {
        init();
        for (int j = 0; j < n; ++j)
        {
            cin >> a[j];
        }
        //pre_order(0);
        int type = isHeap();
        if (type == 1)
        {
            cout << "Max Heap" << endl;
        }
        else if (type == -1)
        {
            cout << "Min Heap" << endl;
        }
        else
        {
            cout << "Not Heap" << endl;
        }
        postorder(0);
        cout << ans[0];
        for (int i = 1; i < ans.size(); ++i)
        {
            cout << " " << ans[i];
        }
        cout << endl;
    }
}