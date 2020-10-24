#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> s;
    for (int i = 0; i < n;i++){
        int x;
        cin>>x;
        s.push_back(x);
    }
    for (int i = 0; i < m;i++){
        int x;
        cin >> x;
        cout << s[x-1] << endl;
    }
}