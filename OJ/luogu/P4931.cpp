#include<bits/stdc++.h>
using namespace std;
struct node{
    int l,r;
}a[100010];
int Max=-1,n;
void dfs(int root,int step){
    if(root==0) return;
    Max=max(Max,step);
    dfs(a[root].l,step+1);
    dfs(a[root].r,step+1);
}
int main(){
    cin>>n;//输入n
    for(int i=1;i<=n;i++){
        cin>>a[i].l>>a[i].r;//输入该节点的左节点和右节点
    }
    dfs(1,1);//从1号节点，深度为1开始搜索 
    cout<<Max;//输出最大值
    return 0;
}