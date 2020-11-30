#include <bits/stdc++.h>
inline void read(int &x)
{
    x = 0;char ch = getchar();char c = ch;
    while(ch > '9' || ch < '0')c = ch, ch = getchar();
    while(ch <= '9' && ch >= '0')x = x * 10 + ch - '0', ch = getchar();
    if(c == '-')x = -x;
}

const int INF = 0x3f3f3f3f;
const int MAXN = 500 + 10;

struct Edge
{
    int u,v,next;
}edge[MAXN + 1];
int head[MAXN],cnt,root,b[MAXN],n,sum,w[MAXN],ans;

void insert(int a, int b){edge[++cnt] = Edge{a,b,head[a]};head[a] = cnt;}

int dfs1(int u)
{
    register int tmp = w[u];
    for(register int pos = head[u];pos;pos = edge[pos].next)
    {
        int v = edge[pos].v;
        if(!b[v])
        {
            b[v] = true;
            tmp += dfs1(v);
            if(tmp * 2 >= sum && !root)
                root = u;
            if(root)
                return 0;
        }
    }
    return tmp;
}

void dfs2(int u, int step)
{
    ans += w[u] * step;
    for(register int pos = head[u];pos;pos = edge[pos].next)
    {
        int v = edge[pos].v;
        if(!b[v])
        {
            b[v] = 1;
            dfs2(v, step + 1);
        }
    }
}

int main()
{
    read(n);
    register int tmp1,tmp2,tmp3;
    for(register int i = 1;i <= n;++ i)
    {
        read(tmp1);read(tmp2);read(tmp3);
        if(tmp2)
            insert(i,tmp2),insert(tmp2,i);
        if(tmp3)
            insert(i,tmp3),insert(tmp3,i);
        w[i] = tmp1;
        sum += tmp1;
    }
    b[1] = 1;
    dfs1(1);
    memset(b, 0, sizeof(b));
    b[root] = 1;
    dfs2(root, 0);
    printf("%d", ans);
    return 0;
}