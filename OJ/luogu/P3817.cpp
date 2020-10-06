#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    long long x;
    cin>>n>>x;
    vector<long long> candies;
    for(int i=0;i<n;i++){
        long long a;
        cin>>a;
        candies.push_back(a);
    }
    long long ans=0;
    if(candies[0]>x){
        
        ans=candies[0]-x;
        candies[0]=x;
    }
    for(int i=1;i<n;i++){
        long long sum=candies[i]+candies[i-1];
        if(sum>x){
            ans+=sum-x;
            candies[i]=x-candies[i-1];
        }
    }
    cout<<ans;
}