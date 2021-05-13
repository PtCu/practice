//https://www.luogu.com.cn/problem/P5507
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
template <class item>
inline item read()
{
    item res = 0;
    bool negative = 0;
    char ch = getchar();
    while (!isdigit(ch))
        negative |= ch == '-', ch = getchar();
    while (isdigit(ch))
        res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return negative ? -res : res;
}
template <class item>
inline item read(item &t)
{
    t = read<item>();
    return t;
}
#define max(a, b) (!((a) < (b)) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
template <typename T, typename... Args>
inline void read(T &t, Args &...args)
{
    read(t), read(args...);
}
//快读，长了点
struct data
{
    int a[20], step[20], len;
    int hash()
    {
        int res = 0;
        for (register int i = 1; i <= 12; ++i)
            res = (res << 2) + a[i]; //hash
        return res;
    }
    bool check()
    {
        for (register int i = 1; i <= 12; ++i)
            if (a[i] != 1)
                return 0;
        return 1;
    }
    int hfunc()
    {
        int cnt = 0;
        for (register int i = 1; i <= 12; ++i)
            if (a[i] != 1)
                cnt += 5 - a[i];
        //估价函数
        //若不为1，要对上也要5-a[i]次
        return ((cnt - 1) >> 1) + 1;
    }
};
int a[20][5], s[20], depth = 4, minn;
int _next(int x)
{
    return x < 4 ? x + 1 : 1;
}
data st;
bool vis[70000000];
const int b[11] = {4, 6, 8, 9, 10, 11, 12, 13, 15, 17};
void dfs(data now)
{
    if (now.len + now.hfunc() > depth)
    {
        //minn = min(minn, now.len + now.hfunc());
        return;
    }
    if (now.check())
    {
        printf("%d\n", now.len);
        for (register int i = 1; i <= now.len; ++i)
            printf("%d ", now.step[i]);
        //printf("%.3lf", ss);
        exit(0);
    }
    for (register int i = 1; i <= 12; ++i)
    {
        data next = now;
        next.a[i] = _next(next.a[i]);
        next.step[++next.len] = i;
        next.a[a[i][now.a[i]]] = _next(next.a[a[i][now.a[i]]]);
        int val = next.hash();
        if (vis[val])
            continue;
        vis[val] = 1;
        //q.push(next);
        dfs(next);
        vis[val] = 0;
    }
}
int main()
{
    for (register int i = 1; i <= 12; ++i)
    {
        read(s[i], a[i][1], a[i][2], a[i][3], a[i][4]);
        st.a[i] = s[i];
    }
    vis[st.hash()] = 1; //其实不用的
    //q.push(st);
    for (register int i = 1; i <= 10; ++i)
    {
        depth = b[i];
        dfs(st);
    }
}