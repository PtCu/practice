#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int n,m,k;

int tot,last[N],nx[N<<1],to[N<<1];

void Add(int x,int y) {
	tot++;
	to[tot]=y;
	nx[tot]=last[x];
	last[x]=tot;
}

struct Node {
	int r;
	pair<int,int>x;
}a[N];

bool cmp(Node a,Node b) {
	return a.r<b.r;
}

int cnt,dfn[N],pos[N],id[N],b[N<<1],dep[N];

void dfs(int x,int fa) {
	dfn[x]=++cnt;
	id[cnt]=x;
	b[++tot]=dfn[x];
	pos[x]=tot;
	for(int j=last[x];j;j=nx[j]) {
		int v=to[j];
		if(v==fa) continue;
		dep[v]=dep[x]+1;
		dfs(v,x);
		b[++tot]=dfn[x];
	}
}

int f[N<<1][22],g[N<<1]; 

void Init(int n) {
    for(int i=1;i<=n;i++) f[i][0]=b[i];
    for(int i=1;i<=18;i++) 
        for(int j=1;j+(1<<i)-1<=n;j++) 
            f[j][i]=min(f[j][i-1],f[j+(1<<(i-1))][i-1]);
    for(int i=1;i<=n;i++) g[i]=(int)(log((double)(i))/log(2.0));
}

int Q(int l, int r) {
	if(l>r) swap(l,r);
    int k=g[r-l+1];
    return min(f[l][k],f[r-(1<<k)+1][k]);
}


int lca(int x,int y) {
	return id[Q(pos[x],pos[y])];
}

pair<int,int> c[10];

pair<int,int> Merge(pair<int,int>a,pair<int,int>b) {
	if(a.first==0||b.first==0) return make_pair(0,0);
	int x1=lca(a.first,b.first);
	int x2=lca(a.first,b.second);
	int x3=lca(a.second,b.first);
	int x4=lca(a.second,b.second);
	c[1]=make_pair(dep[x1],x1);
	c[2]=make_pair(dep[x2],x2);
	c[3]=make_pair(dep[x3],x3);
	c[4]=make_pair(dep[x4],x4);
	sort(c+1,c+5);
	if(c[3].second!=c[4].second) return make_pair(c[3].second,c[4].second);
	int t=max(dep[lca(a.first,a.second)],dep[lca(b.first,b.second)]);
	if(dep[c[3].second]<t) return make_pair(0,0);
	else return make_pair(c[3].second,c[3].second);
}

int pd(int x,int y,int v) {
	if(dep[v]>dep[x]&&dep[v]>dep[y]) return 0;
	int x1,x2,x3;
	x1=lca(x,y),x2=lca(x,v),x3=lca(y,v);
	if(dep[x2]<dep[x1]||dep[x3]<dep[x1]) return 0;
	if(dep[x2]>dep[x]||dep[x3]>dep[y]) return 0;
	if(x2==v||x3==v) return 1;
	return 0;
}

pair<int,int>F[N][22];
		

int main() {
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1;i<n;i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		Add(x,y);
		Add(y,x);
	}
	for(int i=1;i<=k;i++) scanf("%d%d%d",&a[i].x.first,&a[i].x.second,&a[i].r);
	sort(a+1,a+k+1,cmp);
	tot=0;
	dfs(1,0);
	Init(2*n-1);
	for(int i=1;i<=k;i++) F[i][0]=make_pair(a[i].x.first,a[i].x.second);
	for(int j=1;j<=18;j++)
		for(int i=1;i+(1<<j)-1<=k;i++) F[i][j]=Merge(F[i][j-1],F[i+(1<<(j-1))][j-1]);
	int top=1;
	int last=0;
	while(m--) {
		int opt;
		scanf("%d",&opt);
		if(opt==0) top++;
		else {
			int x;
			scanf("%d",&x);
			x^=last;
			int Ans=top;
			for(int i=18;i>=0;i--) {
				if(Ans+(1<<i)-1>k) continue;
				if(pd(F[Ans][i].first,F[Ans][i].second,x)) Ans+=(1<<i);
			}
			if(Ans>k) puts("-1"),last=-1;
			else printf("%d\n",a[Ans].r),last=a[Ans].r;
		}
	}
}