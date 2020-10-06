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

int t;
string S, T;
vector <int> A, B;

int main(){
	int i, j;
	
	cin >> t;
	
	while(t--){
		cin >> S >> T;
		long long ans = 0;
		A.clear(), B.clear();
		
		
		for(i=0;i<S.length();i++){
			if(S[i] == '1'){
				A.push_back(i);
			}
		}
		
		for(i=0;i<T.length();i++){
			if(T[i] == '1'){
				B.push_back(i);
			}
		}
		
		if(A.size() != B.size()){
			cout << -1 << endl;
			continue;
		}
		
		for(i=0;i<A.size();i++){
			ans += abs(A[i] - B[i]);
		}
		
		cout << ans << endl;
	}
	
	return 0;
}
