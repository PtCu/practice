#include <bits/stdc++.h>
using namespace std;
struct contest
{
    int start;
    int end;
};
bool compare(contest a, contest b)
{
    return a.end < b.end;
}
int main()
{
    int n;
    cin >> n;
    vector<contest> contests(n);
    for(int i=0;i<n;i++){
        cin>>contests[i].start;
        cin>>contests[i].end;
    }
    sort(contests.begin(),contests.end(),compare);
    int pre=0;
    int ans=0;
    for(int i=0;i<n;i++){
        if(contests[i].start>=pre){
            ans++;
            pre=contests[i].end;
        }
    }
    cout<<ans;
}