#include <bits/stdc++.h>
using namespace std;
const int maxt = 1000 + 10;
//map的用法.
//map内部是红黑树，unordered_map内部是哈希表。对于有顺序要求问题，map高效一点。
//对于查找问题，unordered_map更高效
int main()
{
    int t, kase = 0;
    while (scanf("%d", &t) == 1 && t)
    {
        printf("Scenario #%d\n", ++kase);
        map<int, int> team;         //team[x]表示编号为x的人所在的团队编号
        for (int i = 0; i < t; i++) //一共t个团队
        {
            int n, x;
            scanf("%d", &n); //每个团队的人数
            while (n--)
            {
                scanf("%d", &x);
                team[x] = i;
            }
        }
        queue<int> q, q2[maxt]; //q是团队的队列，而q2[i]是团队i成员的队列
        while (true)
        {
            int x;
            char cmd[10];
            scanf("%s", &cmd);
            if (cmd[0] == 'S')
                break;
            else if (cmd[0] == 'D') //出队
            {
                int t = q.front();
                printf("%d\n", q2[t].front());
                q2[t].pop();
                if (q2[t].empty())
                    q.pop();
            }
            else if (cmd[0] == 'E')
            {
                scanf("%d", &x);
                int t = team[x];
                if (q2[t].empty())
                    q.push(t);
                q2[t].push(x);
            }
        }
        printf("\n");
    }
    return 0;
}