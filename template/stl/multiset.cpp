//luogu 2234
#include <bits/stdc++.h>
using namespace std;
int main()
{
    unsigned int n;
    int x;
    cin >> n;
    multiset<int> Set;
    int sum = 0;
    unsigned int l, s;
    cin >> x;
    Set.insert(x);
    sum += x;
    //先插入一个
    //lower_bound，upper_bound为二分查找。不如直接利用插入时返回的位置
    for (size_t i = 1; i < n; ++i)
    {
        cin >> x;
        //返回插入元素的位置
        auto it = Set.insert(x);
        auto cur = it;
        auto larger = ++it;
        --it;
        auto smaller = --it;

        //插入元素位于set末尾，即为当前最大数
        //end为末尾元素再后移一个元素的位置
        if (larger == Set.end())
            l = abs(*smaller - x); //只能加稍小的数
        else
            l = abs(*larger - x);
        if (cur == Set.begin())
            s = abs(*larger - x);
        else
            s = abs(*smaller - x);

        sum += ((l < s) ? l : s);
    }
    cout << sum;
}