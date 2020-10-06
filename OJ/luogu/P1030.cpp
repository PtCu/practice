#include<bits/stdc++.h>
using namespace std;
/*中序ACGDBHZKX，后序CDGAHXKZB，首先可找到主根B；

那么我们找到中序遍历中的B，由这种遍历的性质，可将中序遍历分为ACGD和HZKX两棵子树，

那么对应可找到后序遍历CDGA和HXKZ（从头找即可）

从而问题就变成求1.中序遍历ACGD，后序遍历CDGA的树 2.中序遍历HZKX，后序遍历HXKZ的树；
*/
//每次输出根节点
void d(string in,string post){
    if(in.size()>0){
    char root=post[post.size()-1];
    cout<<root;
    
    int k=in.find(root);
    d(in.substr(0,k),post.substr(0,k));
    d(in.substr(k+1),post.substr(k,post.size()-k-1));
    }
   
    
}
int main(int argc, char const *argv[])
{
    string post,in;
    cin>>in>>post;  
    d(in,post);

    return 0;
}
