#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 1e6 + 5;
const int mod = 998244353;

int n, m, t;
vector <int> vec[maxn];

int a[maxn];
int p[maxn];
long long sum[maxn];
long long f[maxn];

int main(){
	int i, j;
	
	scanf("%d", &t);
	
	while(t--){
		scanf("%d%d", &n, &m);
		for(i=0;i<=n+1;i++){
			vec[i].clear();
			vec[i].push_back(0);
			f[i] = sum[i] = 0;
		}
		
		sum[1] = f[1] = 1;
		
		for(i=2;i<=n+1;i++){
			scanf("%d", &a[i]);
			vec[a[i]].push_back(i - 1);
			p[i] = (int)vec[a[i]].size() - 1;
		}
		
		int maxx = 0;
		
		for(i=2;i<=n+1;i++){
			int x = max(0, p[i] - m);
			maxx = max(maxx, vec[a[i]][x]);
			f[i] = (sum[i - 1] - sum[maxx] + mod) % mod;
			sum[i] = (sum[i - 1] + f[i]) % mod;
		}
		
		printf("%lld\n", f[n + 1]);
	}
	
	return 0;
}
