#include <bits/stdc++.h>
#define ll long long
#define N 100010
using namespace std;
// c1[i]表示b在i选择的下一个城市（也就是在i东边距离i最近的城市）
// c2[i]表示a在i选择的下一个城市（也就是在i东边距离i第二近的城市）
// dist1[i]表示b从i到c1[i]的路程
// dist2[i]表示a从i到c2[i]的路程
// dist3[i][j]为a和b从i分别开了1<<j次的总距离，
// dist4[i][j]为a和b从i分别开了1<<j次以后a的总路程，
// dist5[i][j]为a和b从i分别开了1<<j次以后b的总路程
// c3[i][j]为a和b从i分别开了1<<j次以后他们在什么位置
ll c1[N], c2[N], c3[N][21], n, m, pos[N], dist1[N], dist2[N], dist3[N][21], dist4[N][21], dist5[N][21];
inline ll read()
{
    register ll num = 0;
    register char ch;
    register bool flag = false;
    while ((ch = getchar()) == ' ' || ch == '\n' || ch == '\r');
    if (ch == '-')flag = true; else num = ch ^ 48;
    while ((ch = getchar()) != ' '&&ch != '\n'&&ch != '\r'&&~ch)
        num = num * 10 + (ch ^ 48);
    if (flag)return -num; return num;
}
double minv = INT_MAX;
// 首先把所有城市的高度和编号存入一个结构体，然后排序，记录一下每个城市排序后的位置。
// 然后这个结构体数组可以直接加一个last域和next域改成双向链表，预处理的时候从1到n在链表上找到对应位置pos[i]，
// 不难想到第一近和第二近一定在pos[i]-2 pos[i]-1 pos[i]+1 pos[i]+2之间，在这四个位置之间和上面的暴力是一样的处理，
// 然后在链表中把pos[i]删去，这样的话由于1到n是从西到东的，链表中除了pos[i]以外的所有城市都在pos[i]东边，
// 那么就可以O(N)预处理出c1 c2 dist1 dist2
struct Node {
    ll h;
    int id, last, next;
}q[N];

inline bool cmp(register Node s, register Node t) { return s.h < t.h; }
inline void updata(register int i, register int loc, register int x)
{
    if (x >= 1 && x <= n)
    {
        if (!dist1[i] || dist1[i] > abs(q[loc].h - q[x].h) || (dist1[i] == abs(q[loc].h - q[x].h) && q[x].h < q[pos[c1[i]]].h))
        {
            dist2[i] = dist1[i];
            dist1[i] = abs(q[loc].h - q[x].h);
            c2[i] = c1[i];
            c1[i] = q[x].id;
        }
        else if (!dist2[i] || dist2[i] > abs(q[loc].h - q[x].h) || (dist2[i] == abs(q[loc].h - q[x].h) && q[x].h < q[pos[c2[i]]].h))
        {
            dist2[i] = abs(q[loc].h - q[x].h);
            c2[i] = q[x].id;
        }
    }
}

int main()
{
    n = read();
    for (register int i = 1; i <= n; ++i)q[i].h = read(), q[i].id = i;
    sort(q + 1, q + n + 1, cmp);
    for (register int i = 1; i <= n; ++i)
    {
        //反向表，查询city在排序后的位置
        pos[q[i].id] = i;
        if (i != 1)
            q[i].last = i - 1;
        if (i != n)
            q[i].next = i + 1;
    }
    for (register int i = 1; i <= n; ++i)
    {
        register int loc = pos[i];
        //利用双向链表，在五个数中间找最小和次小
        updata(i, loc, q[q[loc].last].last);
        updata(i, loc, q[loc].last);
        updata(i, loc, q[loc].next);
        updata(i, loc, q[q[loc].next].next);
        if (q[loc].last)q[q[loc].last].next = q[loc].next;
        if (q[loc].next)q[q[loc].next].last = q[loc].last;
        q[loc].last = q[loc].next = 0;
    }
    //初始化2^0的情况
    for (register int i = 1; i <= n; ++i)
    {
        dist4[i][0] = dist2[i];
        dist5[i][0] = dist1[c2[i]]; //c2[i]是a在i时选择的下一个城市，b在a之后选择城市
        dist3[i][0] = dist2[i] + dist1[c2[i]]; //总路程
        c3[i][0] = c1[c2[i]]; //a和b从i开了一个周期后的下一个城市
    }
    for (register int j = 1; j <= 20; ++j)
        for (register int i = 1; i <= n; ++i)
        {
            c3[i][j] = c3[c3[i][j - 1]][j - 1];
            if (c3[i][j])
            {
                dist3[i][j] = dist3[i][j - 1] + dist3[c3[i][j - 1]][j - 1]; //分为两段
                dist4[i][j] = dist4[i][j - 1] + dist4[c3[i][j - 1]][j - 1];
                dist5[i][j] = dist5[i][j - 1] + dist5[c3[i][j - 1]][j - 1];
            }
        }
    register ll xx = read(), ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        register ll a = 0, b = 0, loc = i, x0 = xx;
        for (register int j = 20; j >= 0; --j)
        {
            if (dist3[loc][j] && x0 >= dist3[loc][j])
            {
                x0 -= dist3[loc][j];
                a += dist4[loc][j];
                b += dist5[loc][j];
                loc = c3[loc][j];
            }
        }
        if (dist2[loc] <= x0)a += dist2[loc];
        if (a <= 0)continue;
        if (!ans || 1.0*a / b - minv < -0.00000001 || (fabs(1.0*a / b - minv) <= 0.00000001&&q[pos[ans]].h < q[pos[i]].h))
        {
            minv = 1.0*a / b;
            ans = i;
        }
    }
    printf("%lld\n", ans);
    m = read();
    while (m--)
    {
        register ll s = read(), x = read(), a = 0, b = 0;
        for (register int j = 20; j >= 0; --j)
        {
            if (dist3[s][j] && x >= dist3[s][j])
            {
                x -= dist3[s][j];
                a += dist4[s][j];
                b += dist5[s][j];
                s = c3[s][j];
            }
        }
        if (dist2[s] <= x)a += dist2[s];
        printf("%lld %lld\n", a, b);
    }
    return 0;
}