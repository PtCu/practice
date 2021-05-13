//https://www.luogu.com.cn/problem/P5507
#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 24;
int g[N], nxt[14][6], fa[N], ans[30], choice[N];
struct Node
{
    int state;
    double F;
    Node(int s) : state(s)
    {
        double h = 0;
        F = 0;
        for (int i = 0; i < 12; ++i)
        {
            if ((s >> (i << 1)) & 3) //获取第i+1个旋钮状态（0~3）
            {
                h += 4 - ((s >> (i << 1)) & 3);
            }
        }
        F = h * 1.2 + g[s];
    }
    //函数值越大，优先级越低
    bool operator<(const Node &e)
    {
        return F > e.F;
    }
};
//默认为less，即大顶堆。F值越小的越优先
priority_queue<Node> Q;
int main()
{
    int button, Start = 0, x;
    for (int i = 0; i < 12; ++i)
    {
        cin >> button;
        Start |= (button - 1) << (i << 1);
        for (int j = 0; j < 4; ++j)
        {
            cin >> x;
            nxt[i][j] = x - 1;
        }
    }
    Q.push(Node(Start));
    g[Start] = 0;
    while (!Q.empty())
    {
        int state = Q.top().state;
        Q.pop();
        if (state == 0)
            break;
        int si, sNxt, nx, nextState;
        for (int i = 0; i < 12; ++i)
        {
            si = (state >> (i << 1)) & 3;
            nx = nxt[i][si];
            sNxt = (state >> (nx << 1)) & 3;
            nextState = state ^ (si << (i << 1)) ^ (((si + 1) & 3) << (i << 1)) ^ (sNxt << (nx << 1)) ^ (((sNxt + 1) & 3) << (nx << 1));
            if (!g[nextState])
            {
                g[nextState] = g[state] + 1;
                fa[nextState] = state;
                choice[nextState] = i + 1;
                Q.push(Node(nextState));
            }
        }
    }
    int cnt = 0, state = 0;
    while (state != Start)
    {
        ans[++cnt] = choice[state];
        state = fa[state];
    }
    printf("%d\n", cnt);
    for (int i = cnt; i; i--)
    {
        printf("%d ", ans[i]);
    }
}