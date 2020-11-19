#include <bits/stdc++.h>

using namespace std;

int n, t;

int main(){
	int i, j;
	
	scanf("%d", &t);
	
	while(t--){
		scanf("%d", &n);
		n--;
		if(n & 1){
			printf("%.2f\n", (1ll << (n / 2)) * sqrt(2));
		}else{
			printf("%.2f\n", (double)(1ll << (n / 2)));
		}
	}
	
	return 0;
}
