#include <bits/stdc++.h>
using namespace std;
int arr[1002];
int main(int argc, const char **argv)
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=i;j>=0;j--){  //j到这来，可以错开
            int num;
            cin>>num;
            if(j>=1)
            arr[j]=max(arr[j],arr[j-1])+num;
            else arr[j]=arr[j]+num;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,arr[i]);
    }
    cout<<ans;
    return 0;
}