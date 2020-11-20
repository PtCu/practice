#include <bits/stdc++.h>
using namespace std;
struct Student
{
    int id;
    string name;
};
const int N = 4;
Student students[N] = {{1, "a"}, {2, "b"}, {3, "c"}, {4, "d"}};
string getName_seq(int id)
{
    for (size_t i = 0; i < N; ++i)
    {
        if (id == students[i].id)
            return students[i].name;
    }
    return "NO";
}
string getName_bin(int id)
{
    //assert: students数组已经排好序
    size_t lo = 0, hi = N;
    while (lo < hi)
    {
        size_t mi = (lo + hi) >> 1;
        (id < students[mi].id) ? hi = mi : lo = mi + 1;
    }
    string name;
    id == --lo ? name = students[id].name : name = "No"; //循环结束时，lo为大于e的元素的最小秩，故lo-1为不大于e的元素的最大秩
    return name;
   
} //有多个命中元素时，总能保证返回秩的最大者;查找失败时，能够返回失败的位置
int main()
{
}