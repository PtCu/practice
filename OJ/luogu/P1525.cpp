#include<bits/stdc++.h>
using namespace std;
const int maxn = 20020;
const int maxm = 200020;
struct Conflict{
    int x, y, z;
};
int f[maxn];
int enemies[maxn];

int find(int x){
    if(x==f[x])
        return x;
    return f[x]=find(f[x]);
}
int main(){
    int n, m, a, b, c;
    cin >> n >> m;
    vector<Conflict> conflicts(m+1);
    for (size_t i = 1; i <= m;++i) {
        cin >> conflicts[i].x >> conflicts[i].y >> conflicts[i].z;
        f[i] = i;
    }
    sort(conflicts.begin(), conflicts.end(), [](const Conflict &a, const Conflict &b) { return a.z > b.z; });
    for (size_t i = 1; i <= m;++i){
        if(find(conflicts[i].x)==find(conflicts[i].y)){
            cout << conflicts[i].z;
            return 0;
        }

        //如果当前x没有敌人
        if(!enemies[conflicts[i].x])
        {
            //把y作为x的敌人
            enemies[conflicts[i].x] = conflicts[i].y;
        }
        //如果有，就把敌人的敌人与自己划分为一组
        else{
            f[find(enemies[conflicts[i].x])] = find(conflicts[i].y);
        }

                //如果当前x没有敌人
        if(!enemies[conflicts[i].y])
        {
            //把y作为x的敌人
            enemies[conflicts[i].y] = conflicts[i].x;
        }
        else{
            f[find(enemies[conflicts[i].y])] = find(conflicts[i].x);
        }
    }
    cout << 0 << endl;
    return 0;
}