#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int N=1050,E=1000,INF=0x3f3f3f3f;
int n,m,k,C;
int d[N];
bool st[N];
struct D
{
    int v,dis;
    bool operator <(const D& t)const
    {
        return dis>t.dis;
    }
};
struct Gas
{
    int id;
    int ming;
    double everg;
    bool operator <(const Gas& t)
    {
        if(ming!=t.ming)return ming>t.ming;
        else if(everg!=t.everg) return everg<t.everg;
        else return id<t.id;
    }
}ga[15];
vector<D>adj[N];
priority_queue<D>q;
int get_i(char c[])
{
    if(c[0]=='G') return atoi(c+1)+E;
    else  return atoi(c);
}
void Dijkstra(int s)
{
    memset(st,0,sizeof st);
    memset(d,0x3f,sizeof d);
    d[s]=0;
    q.push({s,d[s]});
    while(!q.empty())
    {
        int u=q.top().v;
        q.pop();
        if(st[u])continue;
        st[u]=true;
        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i].v,dis=adj[u][i].dis;
            if(d[v]>d[u]+dis)
            {
                d[v]=d[u]+dis;
                q.push({v,d[v]});
            }
        }
    }

    
}
int main()
{
    scanf("%d %d %d %d",&n,&m,&k,&C);
    while(k--)
    {
        char a[6],b[6];
        int w;
        scanf("%s %s %d",a,b,&w);
        int u=get_i(a),v=get_i(b);
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    bool has_way=false;
    for(int i=1;i<=m;i++)
    {
        Dijkstra(i+E);
        int cnt=0,tt=0;
        int ming=INF;
        for(int i=1;i<=n;i++)
        {
            if(d[i]<=C)
            {
                ming=min(ming,d[i]);
                tt+=d[i];
                cnt++;
            }
        }
        if(cnt==n)
        {
            double r=1.0*tt/(1.0*n);
            has_way=true;
            ga[i]={i,ming,r};
        }
    }
    sort(ga+1,ga+m+1);
    if(!has_way)puts("No Solution");
    else
    {
        cout<<"G"<<ga[1].id<<endl;
        printf("%.1f %.1f\n",1.0*ga[1].ming,ga[1].everg+1e-8);
    }
    return 0;
}