#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin >> n;
    unordered_map<int, int> m;
    for (int i = 1; i <= n;++i){
        cin >> x;
        m[x] = i;
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q;++i){
        cin >> x;
        if(!m.count(x)){
            cout << 0 << endl;
            continue;
        }
        cout << m[x] << endl;
    }
}