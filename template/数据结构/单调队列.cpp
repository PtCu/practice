// https://www.nowcoder.com/practice/1624bc35a45c42c0bc17d17fa0cba788?tpId=13&tqId=23458&ru=%2Fpractice%2F9023a0c988684a53960365b889ceaf5e&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&sourceUrl=
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxInWindows(const vector<int> &num, unsigned int size)
    {
        if (size == 0 || num.empty() || num.size() < size)
            return {};
        deque<int> dq;
        //求最大值用递减的单调队列。队列中保留的是下标，以方便判断头部元素是否过期
        vector<int> ans;
        dq.push_back(0);
        for (int i = 1; i < size; ++i)
        {
            while (!dq.empty() && num[i] > num[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }
        ans.push_back(num[dq.front()]);
        for (int i = size; i < num.size(); ++i)
        {
            while (!dq.empty() && num[i] > num[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            if (dq.front() + size <= i)
                dq.pop_front();
            ans.push_back(num[dq.front()]);
        }
        return ans;
    }
};