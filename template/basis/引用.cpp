#include <bits/stdc++.h>

using namespace std;
int main(){
    int a = 1;
    int &b = a;
    auto c = b; //复制
    auto &d = b;
    int &e = a;
    e = 2;
    cout << a << b << c << d << e;
}