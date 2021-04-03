#include <bits/stdc++.h>
using namespace std;
vector<int> source;
int profitBetween(size_t lo, size_t hi, size_t &ml, size_t &mr)
{
    if (hi - lo < 2)
    {
        ml = mr = lo;
        return 0;
    }
    int min_l = INT_MAX; //左侧最小元素
    int max_r = INT_MIN; //右侧最大元素

    //求最左侧的最小元素
    size_t mi = (lo + hi) >> 1;
    for (size_t i = lo; i < mi; ++i)
    {
        if (source[i] < min_l)
        {
            min_l = source[i];
            ml = i;
        }
    }
    //求最右侧的最大元素
    for (size_t i = mi; i < hi; ++i)
    {
        if (source[i] > max_r)
        {
            max_r = source[i];
            mr = i;
        }
    }
    int ans = max_r - min_l;

    //左侧和右侧的买入卖出下标
    size_t l_ml, l_mr, r_ml, r_mr;

    int pl = profitBetween(lo, mi, l_ml, l_mr);
    int pr = profitBetween(mi, hi, r_ml, r_mr);

    //求左侧、右侧以及中间的最大值并更改索引
    if (pl > ans)
    {
        //右侧最大
        if (pr > pl)
        {
            ans = pr;
            ml = r_ml; //买入下标为右侧的买入下标
            mr = r_mr;//卖出下标为右侧的卖出下标
        }
        //左侧最大
        else
        {
            ans = pl;   //同理，替换索引
            ml = l_ml;
            mr = l_mr;
        }
    }
    else
    {
        //右侧最大
        if (pr > ans)
        {
            ans = pr; //同理，替换索引
            ml = r_ml;
            mr = r_mr;
        }
        //否则左侧买入，右侧卖出最大
    }
    
    return ans;
}

int main()
{
    size_t i = 0, j = 0;
    source = {7, 1, 5, 3, 6, 4};
    int profit = profitBetween(0, source.size(), i, j);
    cout << i + 1 << " " << j + 1;
}