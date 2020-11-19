#include <bits/stdc++.h>

template <class T> bool Enlarge(T &a,T const &b) {
    return a<b?a=b,1:0; //如果a小于b则返回true并且使a等于b（扩大）
}

template <class T> bool Reduce(T &a,T const &b) {
    return a>b?a=b,1:0;
}

const int XN=5e4+11;

struct Edge {
    int to;         //编号
    long long v;    //距离
};
std::vector<Edge> G[XN];

long long Dijkstra(int s,int t) {
    static long long sp[XN]; //存放s到各点的距离
    std::priority_queue<std::pair<long long,int>,
        std::vector<std::pair<long long,int>>,
        std::greater<std::pair<long long,int>>> Q;
    memset(sp,31,sizeof(sp));
    sp[s]=0;
    Q.push(std::make_pair(0,s));
    static bool used[XN];
    while(!Q.empty()) {
        int pos=Q.top().second;Q.pop();
        if(used[pos])
            continue;
        used[pos]=1;
        for(auto &e : G[pos]) {
            int u=e.to;
            if(Reduce(sp[u],sp[pos]+e.v))   //s直接到u的距离和s经过pos再到u的距离进行比较
                Q.push(std::make_pair(sp[u],u));
        }
    }
    return sp[t];
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int n,m,t,s,e;
    std::cin>>n>>m>>t>>s>>e;
    for(int i=1;i<=m;++i) {
        int x,y,z;std::cin>>x>>y>>z;
        G[x].push_back({y,(long long)z});
        G[y].push_back({x,(long long)z});
    }
    for(int i=1;i<=n;++i)
        for(int b=0;b<16;++b)
            if((i^(1<<b))<=n)
                G[i].push_back({i^(1<<b),(long long)t*(1<<b)});
    std::cout<<Dijkstra(s,e)<<'\n';
    return 0;
}

