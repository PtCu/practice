#include <bits/stdc++.h>
using namespace std;
int f[10001];
int getfather(int x)
{
    if (f[x] == x)
        return x;
    else{
        f[x]=getfather(f[x]);
    }
    return f[x];
}
void Union(int x,int y) 
{
    int f1=getfather(x);
    int f2=getfather(y);
    f[f1]=f2;
    
};
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        f[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        int z, x, y;
        cin >> z >> x >> y;
        if (z == 1)
            Union(x,y);   //合并操作就是把一个节点的祖先变为另一个节点的祖先。
        else if(z==2)
        {
            if (getfather(x) == getfather(y))
                cout << 'Y'<<endl;
            else
            
                cout << 'N'<<endl;
            
        }
    }
}