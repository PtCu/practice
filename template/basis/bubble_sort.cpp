#include <bits/stdc++.h>
using namespace std;
void bubble_sort(vector<int> &a)
{
    int lo = 0, hi = a.size();
    bool swapped = true;
    while (lo < hi--)
    {
        swapped = false;
        for (int i = lo; i < hi; ++i)
        {
            if (a[i] > a[i + 1])
            {
                swapped = true;
                swap(a[i], a[i + 1]);
            }
        }
        if (!swapped)
            break;
    }
}