
#include <iostream>
#include <vector>
#include <cstdlib>
#define MAX 10000
using namespace std;
 
struct EdgeNode{ //边表节点类型
	int to, w; //顶点序号和边长
};
vector<EdgeNode> map[MAX];
 
int main(){
	EdgeNode e;
	int n, m, i, j, k, w;
	cin >> n >> m; //n个顶点m组数据
	
	for(i = 0; i < m; ++i){
		cin >> j >> k >> w;
		e.to = k; e.w = w;
		map[j].push_back(e);
	}
	
	//遍历
	for(i = 1; i <= n; ++i){
		for(vector<EdgeNode>:: iterator k = map[i].begin(); 
		k != map[i].end(); ++k){
			EdgeNode t = *k;
			cout << i << ' ' << t.to << ' ' << t.w << endl;
		}
	}
	system("pause");
	return 0;
}