#include <bits/stdc++.h>
using namespace std;
vector<int> source;
int ans;
void solve(size_t lo, size_t hi, size_t k)
{
        size_t i = lo, j = hi;
        int pivot = source[i]; //分割点. 将比pivot小的都放在前面，比pivot大的都放在后面
        while (i < j)
        {
            //从后向前找到一个比pivot小的
            while ((i < j) && pivot < source[j])
                j--;
            //如果找到就放在前面
            if (i < j)
                source[i] = source[j];
            //从前向后找到一个比pivot大的
            while ((i < j) && pivot > source[i])
                i++;
            //如果找到就放在后面
            if (i < j)
                source[j] = source[i];
        }
        //i==j时将pivot放在中间
        source[i] = pivot;
        //第i个数为即第k小的数
        if (i == k)
        {
            ans = source[i];
            return;
        }
        //如果i>k, 说明第k个数在[lo,i-1]区间内
        else if (i > k)
        {
            solve(lo, i - 1, k);
        }

        //如果i<k，说明第k个数在[i+1,hi]区间内
        else
        {
            solve(i + 1, hi, k);
        }
    
}
int main()
{
    source = {4, 3, 2, 1, 5};
    solve(0, source.size() - 1, 1);
    cout << ans;
}