#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n,m;
    cin>>n>>m;
    vector<int> source(m);
    for(int i=0;i<m;i++){
        cin>>source[i];
    }
    sort(source.begin(),source.end());
    for(int i=0;i<m;i++){
        cout<<source[i]<<" ";
    }
    return 0;
}

//桶排：
// #include<bits/stdc++.h>
// using namespace std;
// long long b[1001],n,m,k;
// int main() {
//     cin>>m>>n;
//     for(long long i=1; i<=n; ++i) {
//         cin>>k;
//         b[k]++;
//     }
//     for(long long i=1; i<=m; i++) {
//         while(b[i]>0) {
//             cout<<i<<" ";
//             b[i]--;
//         }
//     }
//     return 0;
// }