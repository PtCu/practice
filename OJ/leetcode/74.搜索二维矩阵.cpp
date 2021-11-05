/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size();
        int low = 0, high = m * n - 1;
        int mid = 0, i = 0, j = 0;
        bool isFound = false;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            i = mid / n;
            j = mid % n;
            if (matrix[i][j] < target)
            {
                low = mid + 1;
            }
            else if (matrix[i][j] > target)
            {
                high = mid - 1;
            }
            else
            {
                isFound = true;
                break;
            }
        }
        return isFound;
    }
};
// @lc code=end
