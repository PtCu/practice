#include <bits/stdc++.h>
using namespace std;
const int rows = 3;
const int cols = 3;
int C[3][3] = {
    {9, 2, 7},
    {6, 4, 3},
    {5, 8, 1}};

//任务分配：每一行选取一个元素，
//这些元素分别属于不同的列，并且元素之和最小
int main()
{
    int a[rows] = {0, 1, 2};
    int minC = numeric_limits<int>::max();
    do
    {
        int cost = 0;
        for (size_t i = 0; i < cols; ++i)
        {
            cost += C[i][a[i]];
        }
        minC = min(minC, cost);
    } while (next_permutation(a, a + rows));

    cout << minC;
}