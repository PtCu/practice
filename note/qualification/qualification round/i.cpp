#include <bits/stdc++.h>

const int XN=50+11,XL=1e7+11,dx[]={0,0,1,-1},dy[]={1,-1,0,0};

int n,a[XN][XN];
bool vis[XL];

void DFS(int x,int y,int v,int s) {
    vis[v]=1;
    if(!s)
        return;
    else {
        for(int d=0;d<4;++d) {
            int gx=x+dx[d],gy=y+dy[d];
            if(1<=std::min(gx,gy) && std::max(gx,gy)<=n)
                DFS(gx,gy,v*10+a[gx][gy],s-1);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);std::cout.tie(0);
    std::cin>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            std::cin>>a[i][j];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(a[i][j]!=0)
                DFS(i,j,a[i][j],6);
            else
                vis[0]=1;
    int mex=0;
    for(;vis[mex];++mex);
    std::cout<<mex<<'\n';
    return 0;
}

