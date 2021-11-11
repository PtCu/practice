/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> G(numCourses);
        vector<int> indegree(numCourses);

        for (auto &pair : prerequisites)
        {
            G[pair[1]].emplace_back(pair[0]);
            ++indegree[pair[0]];
        }
        queue<int> Q;

        for (int i = 0; i < numCourses; ++i)
        {
            //将所有入度为0的点入队
            if (indegree[i] == 0)
            {
                Q.push(i);
            }
        }
        //判断是否是DAG的方法：拓扑排序看是否能遍历每一个点。
        int inqNum = 0;

        while (!Q.empty())
        {
            auto p = Q.front();
            Q.pop();
            ++inqNum;
            for (auto &n : G[p])
            {
                if (--indegree[n] == 0)
                    Q.push(n);
            }
        }

        if (inqNum == numCourses)
            return true;
        return false;
    }
};
// @lc code=end
