#include<bits/stdc++.h>
using namespace std;
#define ul dfs(a+l-1,b+l-1,a,b,l);//递归做左上角
#define ur dfs(a+l-1,b+l,a,b+l,l);//递归做右上角
#define dl dfs(a+l,b+l-1,a+l,b,l);//递归做左下角
#define dr dfs(a+l,b+l,a+l,b+l,l);//递归做右下角
int k,x,y;
void dfs(int x,int y,int a,int b,int l){
//x,y表示这次要填的方格位置
//a,b表示这次要填方格的左上角的位置
//l表示这次要填方格大小
	if (l==1) return;
	l>>=1;
	if (x-a<l && y-b<l){//左上角
		printf("%d %d 1\n",a+l,b+l);
		dfs(x,y,a,b,l);
		ur
		dl
		dr
	}
	if (x-a<l && y-b>=l){//右上角
		printf("%d %d 2\n",a+l,b+l-1);
		ul
		dfs(x,y,a,b+l,l);
		dl
		dr
	}
	if (x-a>=l && y-b<l){//左下角
		printf("%d %d 3\n",a+l-1,b+l);
		ul
		ur
		dfs(x,y,a+l,b,l);
		dr
	}
	if (x-a>=l && y-b>=l){//右下角
		printf("%d %d 4\n",a+l-1,b+l-1);
		ul
		ur
		dl
		dfs(x,y,a+l,b+l,l);
	}
}
int main(){
	scanf("%d%d%d",&k,&x,&y);
	dfs(x,y,1,1,1<<k);
}