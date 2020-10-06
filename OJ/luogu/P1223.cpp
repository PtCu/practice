#include <bits/stdc++.h>
using namespace std;
struct one
{
    int id;
    int time;
};
vector<one> source;
bool cmp(one a,one b){
    return a.time<b.time;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
      
        source.push_back({i,a});
    }
    sort(source.begin(), source.end(),cmp);
    double sum = 0;
    double len=source.size();
    for (int i = 0; i < len; i++)
    {
        cout << source[i].id+1 << " ";
        sum+=source[i].time*(n-i-1);
    }   
    cout<<endl;
    printf("%.2f",sum/len);
 
}