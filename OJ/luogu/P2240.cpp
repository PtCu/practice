#include <bits/stdc++.h>
using namespace std;
typedef struct {
    int m;
    int v;
    float ratio;
}GoldHeap;
//降序用>，升序用小于
bool cmp(GoldHeap a,GoldHeap b){
    return a.ratio>=b.ratio;
}   
int main(int argc, char const *argv[])
{
    int n,t;
    cin>>n>>t;
    vector<GoldHeap> heaps(n);
    for(int i=0;i<n;i++){
        cin>>heaps[i].m>>heaps[i].v;
        heaps[i].ratio=(float)heaps[i].v/heaps[i].m;
    }
    sort(heaps.begin(),heaps.end(),cmp);
    float total=0;
   for(int i=0;i<n;i++){
       if(t>=heaps[i].m){
           t-=heaps[i].m;
            total+=heaps[i].v;
       }
       else {
           total+=heaps[i].ratio*t;
           t=0;}
       if(t==0)
       break;
   }
   printf("%.2f", total);


    return 0;
}
