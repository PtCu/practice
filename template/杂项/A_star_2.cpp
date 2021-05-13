//https://www.luogu.com.cn/problem/solution/P1379
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline ll read()
{
    ll f = 1, x = 0;
    char ch;
    do
    {
        ch = getchar();
        if (ch == '-')
            f = -1;
    } while (ch > '9' || ch < '0');
    do
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    } while (ch >= '0' && ch <= '9');
    return f * x;
}

int now;

char s[15];

string goal = "123804765";

int h(string cur)
{
    int res = 0;
    for (int i = 0; i < 9; i++)
    {
        if (goal[i] != cur[i] && goal[i] != 0)
            res++;
    }
    return res;
}

struct node
{
    int f, step;
    string now;
    bool operator<(const node &x) const
    {
        return f > x.f;
    }
};

int ans = 0x7fffffff;

priority_queue<node> q;

map<string, bool> visited;

map<string, int> dis;

int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

void A_STAR()
{
    while (!q.empty())
    {
        node t = q.top();
        q.pop();
        string cur = t.now;
        if (cur == goal)
        {
            printf("%d\n", t.step);
            return;
        }

        int sx, sy; //0的位置
        for (int i = 0; i < 9; i++)
        {
            if (cur[i] - '0' == 0)
                sx = i / 3 + 1, sy = i % 3 + 1;
        }

        int tmp1 = (sx - 1) * 3 + sy - 1;
        for (int i = 0; i < 4; i++)
        {
            int xx = dx[i] + sx, yy = dy[i] + sy;
            if (xx < 1 || xx > 3 || yy < 1 || yy > 3)
                continue;
            int tmp2 = (xx - 1) * 3 + yy - 1;
            swap(cur[tmp1], cur[tmp2]);
            if (visited[cur] == 0 || (visited[cur] == 1 && (t.step + 1) < dis[cur]))
            {
                dis[cur] = t.step + 1;
                q.push((node){h(cur) + t.step + 1, t.step + 1, cur});
                visited[cur] = 1;
            }
            swap(cur[tmp1], cur[tmp2]);
        }
    }
}

int main()
{
    scanf("%s", s);

    if (h(s) == 0)
    {
        cout << 0;
        return 0;
    }
    while (q.size())
        q.pop();
    q.push((node){h(s), 0, s});
    visited[s] = 1;
    dis[s] = 0;
    A_STAR();
    return 0;
}