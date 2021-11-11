/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    using LL = long long;
    int nthUglyNumber(int n)
    {
        priority_queue<LL, vector<LL>, greater<LL>> pq;
        pq.push(1);
        unordered_set<LL> ugly_set;
        LL ans = 0;
        int coeffin[3] = {2, 3, 5};
        for (int i = 0; i < n; ++i)
        {
            auto cur = pq.top();
            ans = cur;
            pq.pop();
            for (int j = 0; j < 3; ++j)
            {
                auto cur2 = coeffin[j] * cur;
                if (!ugly_set.count(cur2))
                {
                    pq.push(cur2);
                    ugly_set.insert(cur2);
                }
            }
        }
        return ans;
    }
};
// @lc code=end
