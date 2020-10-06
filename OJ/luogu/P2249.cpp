#include <bits/stdc++.h>
using namespace std;
int binarySearch(int goal,vector<int>& source){
    int left=0;int right=source.size()-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(source[mid]>goal){
            right=mid-1;
        }
        else if(source[mid]<goal){
            left=mid+1;
        }
        else{
            return mid;
        }
    }
    return -1;

}
int main(int argc, char const *argv[])
{
    int n,m;
    cin>>n>>m;
    vector<int> source,destination;
    //刚开始vector为空时不能用下标赋值，必须push_back
    for(int i=0;i<n;i++){
        int j;
        cin>>j;
        source.push_back(j);
    }
    for(int i=0;i<m;i++){
        int j;
        cin>>j;
        destination.push_back(j);
    }
    for(int i=0;i<m;i++){
        int index=binarySearch(destination[i],source);
        if(index==-1) cout<<index<<" ";
        else{
            while(source[index]==destination[i])
                index--;
            cout<<index+2<<" ";
        }
    }
    return 0;
}
// #include<cstdio>
// using namespace std;

// int n,m,q,a[1000005];

// int find(int x) //二分查找 
// {
//     int l=1,r=n;
//     while (l<r)
//     {
//         int mid=l+(r-l)/2;
//         if (a[mid]>=x) r=mid;
//         else l=mid+1;
//     }

//     if (a[l]==x) return l; //找都了就输出他的位置 
//     else return -1; // 没找到输出-1 
// }

// int main()
// {
//     scanf("%d %d",&n,&m); //读入 

//     for (int i=1 ; i<=n ; i++)
//         scanf("%d",&a[i]); //还是读入 

//     for (int i=1 ; i<=m ; i++)
//     {
//         scanf("%d",&q);
//         int ans=find(q); //看看查找的结果 
//         printf("%d ",ans); //输出 
//     }

//     return 0;
// }