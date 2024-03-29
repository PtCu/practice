#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
int d[maxn];
// 考虑一个简单的贪心，如果我们要使上升子序列尽可能的长，则我们需要让序列上升得尽可能慢，
// 因此我们希望每次在上升子序列最后加上的那个数尽可能的小。
// 基于上面的贪心思路，我们维护一个数组 d[i] ，表示长度为 i 的最长上升子序列的末尾元素的最小值，
// 用 len 记录目前最长上升子序列的长度，起始时 len 为 1，d[1]=nums[0]。
// 同时我们可以注意到 d[i] 是关于 i 单调递增的。因为如果 d[j]>=d[i] 且 j<i，
// 我们考虑从长度为 i 的最长上升子序列的末尾删除 i−j 个元素，那么这个序列长度变为 j ，
// 且第 j 个元素 x（末尾元素）必然小于 d[i]，也就小于 d[j]。那么我们就找到了一个长度为 j 的最长上升子序列，并且末尾元素比 d[j] 小，从而产生了矛盾。因此数组 d 的单调性得证。

// 我们依次遍历数组 nums 中的每个元素，并更新数组 d 和 len 的值。如果nums[i]>d[len] 则更新 len=len+1，否则在 d[1…len]中找满足d[i−1]<nums[j]<d[i] 的下标i，并更新 d[i]=nums[j]。
// 根据 d 数组的单调性，我们可以使用二分查找寻找下标 i，优化时间复杂度。
// 最后整个算法流程为：
// 设当前已求出的最长上升子序列的长度为len（初始时为 1），从前往后遍历数组 nums，在遍历到 nums[i] 时：
// 如果nums[i]>d[len] ，则直接加入到 d数组末尾，并更新len=len+1；
// 否则，在 d数组中二分查找，找到第一个比nums[i] 小的数 d[k] ，并更新d[k+1]=nums[i]。
// 以输入序列 [0,8,4,12,2] 为例：
// 第一步插入 d=[0]；
// 第二步插入 8，d=[0,8]；
// 第三步插入 4，d=[0,4]；
// 第四步插入 12，d=[0,4,12]；
// 第五步插入 2，d=[0,2,12]。
// 最终得到最大递增子序列长度为 3。
vector<int> nums = {3, 2, 1, 4, 5};
int LIS()
{
    int len = 1, n = nums.size();
    if (n == 0)
        return 0;
   
    for (int i = 0; i < n; ++i)
    {
        //换成lower_bound则是最长递增。注意区别
        int pos = upper_bound(d , d + len , nums[i]) - d;
        //如果可以接在len后面就接上，如果是最长上升子序列
        if (pos == len)
        {
            d[len++] = nums[i];
        }
        //否则就找一个最该替换的替换掉
        else
        {
            d[pos] = nums[i];
        }

    }
    return len;
}

int lengthOfLIS(vector<int> &nums)
{
    int len = 1, n = (int)nums.size();
    if (n == 0)
    {
        return 0;
    }
    vector<int> d(n + 1, 0);
    d[len] = nums[0];
    for (int i = 1; i < n; ++i)
    {
        if (nums[i] > d[len])
        {
            d[++len] = nums[i];
        }
        else
        {
            int l = 1, r = len, pos = 0; // 如果找不到说明所有的数都比 nums[i] 大，此时要更新 d[1]，所以这里将 pos 设为 0
            while (l <= r)
            {
                int mid = (l + r) >> 1;
                if (d[mid] < nums[i])
                {
                    pos = mid;
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
            //结束时，pos为小于nums[i]的最大秩
            d[pos + 1] = nums[i];
        }
    }
    return len;
}

int main()
{
    cout << LIS();
}
