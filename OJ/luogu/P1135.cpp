#include <bits/stdc++.h>
using namespace std;
typedef struct
{
    int floor;
    int step; //走到这一floor所用的步数
} level;
int main(int argc, char const *argv[])
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> nums(n + 1);
    vector<bool> visited(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> nums[i];
    queue<level> q;
    q.push((level){a,0});
    visited[a] = true;
    level cur;
    //int ans = 0x7ffffff;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        if (cur.floor == b)
        {
                break;  //第一次找到的就是最小的
        }
        level next;
        if ((cur.floor + nums[cur.floor] <= n) && !visited[cur.floor + nums[cur.floor]])
        {
            visited[cur.floor + nums[cur.floor]] = true;
            next.floor = cur.floor + nums[cur.floor];
            next.step = cur.step + 1;
            q.push(next);
        }
        if (cur.floor - nums[cur.floor] >= 1 && !visited[cur.floor - nums[cur.floor]])
        {
            visited[cur.floor - nums[cur.floor]] = true;
            next.floor = cur.floor - nums[cur.floor];
            next.step = cur.step + 1;
            q.push(next);
        }
    }
    if(cur.floor!=b) cout<<"-1";
    else cout << cur.step;
    return 0;
}

/*

#include<cstdio>
#include<iostream>
using namespace std;
int n,a,b,ans=0x7ffffff;
int to[205];
bool vis[205];
void dfs(int now,int steps){
    if(now==b) ans=min(ans,steps);
    if(steps>ans) return;
    vis[now]=1;
    if(now+to[now]<=n&&!vis[now+to[now]]) dfs(now+to[now],steps+1);
    if(now-to[now]>=0&&!vis[now-to[now]]) dfs(now-to[now],steps+1);
    vis[now]=0; // 回溯
}
int main()
{
    scanf("%d%d%d",&n,&a,&b);
    for(int i=1;i<=n;i++) scanf("%d",&to[i]);
    vis[a]=1;
    dfs(a,0);
    if(ans!=0x7ffffff) printf("%d",ans);
    else printf("-1");
    return 0;
}
*/