#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
// n是桶的数量，w是数据范围[0,w]
int n, w, a[N];
vector<int> bucket[N];

//插入排序，在桶内排序
void insertion_sort(vector<int> &A)
{
    for (int i = 1; i < A.size(); ++i)
    {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            --j;
        }
        A[j + 1] = key;
    }
}

void bucket_sort()
{
    //一个桶的数据范围
    int bucket_size = w / n + 1;
    for (int i = 0; i < n; ++i)
    {
        bucket[i].clear();
    }
    for (int i = 1; i <= n; ++i)
    {
        bucket[a[i] / bucket_size].push_back(a[i]);
    }
    //此时已经排好序。回填即可
    int p = 0;
    for (int i = 0; i < n; ++i)
    {
        insertion_sort(bucket[i]);
        for (int j = 0; j < bucket[i].size(); ++j)
        {
            a[++p] = bucket[i][j];
        }
    }
}