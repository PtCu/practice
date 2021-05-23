#include <bits/stdc++.h>
using namespace std;
void selection_sort(vector<int> &a)
{
    //从前往后换第i个
    for (int i = 0; i < a.size() - 1; ++i)
    {
        int ith = i;
        for (int j = i + 1; j < a.size(); ++j)
        {
            if (a[j] < a[ith])
            {
                ith = j;
            }
        }
        swap(a[ith], a[i]);
    }
}

void selection_sort(vector<int> &a)
{
    //换最后一个，即找最大的并放到最后位置
    int lo = 0, hi = a.size();
    while (lo < --hi)
    {
        //将[hi]与[lo, hi]中的最大者交换
        swap(*max_element(a.begin(), a.begin() + hi - lo), *(a.begin() + hi - lo));
    }
}
