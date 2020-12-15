#include<bits/stdc++.h>
using namespace std;
struct Criminal{
    int x, y, z;
};
int main(){
    int n, m, a, b, c;
    cin >> n >> m;
    vector<Criminal> crimes(m+1);
    for (size_t i = 1; i <= m;++i) {
        cin >> crimes[i].x >> crimes[i].y >> crimes[i].z;
    }
    sort(crimes.begin(), crimes.end(), [](const Criminal &a, const Criminal &b) { return a.z > b.z; });
    
}