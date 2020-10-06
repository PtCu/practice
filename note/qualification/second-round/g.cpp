#include <bits/stdc++.h>

using namespace std;

int n, m, t;
int a[105][105];
int b[105][105];
int c[105], d[105];
int f[105], g[105];
int minx[105];

bool cmp(int x, int y){
	return minx[x] < minx[y];
}

bool cmpf(int x, int y){
	return a[c[1]][x] < a[c[1]][y];
}

bool cmpg(int x, int y){
	return b[d[1]][x] < b[d[1]][y];
}

int main(){
	int i, j;
	
	scanf("%d", &t);
	
	while(t--){
		scanf("%d%d", &n, &m);
		
		for(i=1;i<=n;i++){
			minx[i] = 1e9;
			for(j=1;j<=m;j++){
				scanf("%d", &a[i][j]);
				f[j] = j;
				minx[i] = min(minx[i], a[i][j]);
			}
			c[i] = i;
		}
		
		sort(c + 1, c + n + 1, cmp);
		sort(f + 1, f + m + 1, cmpf);
		
		for(i=1;i<=n;i++){
			minx[i] = 1e9;
			for(j=1;j<=m;j++){
				scanf("%d", &b[i][j]);
				minx[i] = min(minx[i], b[i][j]);
				g[j] = j;
			}
			d[i] = i;
		}
		
		sort(d + 1, d + n + 1, cmp);
		sort(g + 1, g + m + 1, cmpg);
		
		bool flag = false;
		
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				flag = (flag || (a[c[i]][f[j]] != b[d[i]][g[j]]));
			}
		}
		
		printf(flag ? "NO\n" : "YES\n");
	}
	
	return 0;
}