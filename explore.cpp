#include <bits/stdc++.h>
using namespace std;
class A {

public:
    A() = default;
    int i;
};

void f(A& a) {
    auto& b = a;
    b.i = 1;
}
int main() {
    vector<int> nums{ 1,1,2,3,4 };
    vector<int> origin;
    origin.assign(nums.begin(), nums.end());
    A a;
    f(a);
    return 0;

}