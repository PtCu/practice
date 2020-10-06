/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 *
 * https://leetcode-cn.com/problems/maximal-rectangle/description/
 *
 * algorithms
 * Hard (44.53%)
 * Likes:    373
 * Dislikes: 0
 * Total Accepted:    23.5K
 * Total Submissions: 51.9K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * 给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * ⁠ ["1","0","1","0","0"],
 * ⁠ ["1","0","1","1","1"],
 * ⁠ ["1","1","1","1","1"],
 * ⁠ ["1","0","0","1","0"]
 * ]
 * 输出: 6
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.size() == 0)
            return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int maxSize=0;
        vector<vector<int>> width(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '1')
                {
                    if (j == 0)
                        width[i][j] = 1;
                    else
                    {
                        width[i][j] = width[i][j - 1] + 1;
                    }
                }
                int minWidth=width[i][j];
                for(int row=i;row>=0;row--){
                    minWidth=min(width[row][j],minWidth);
                    maxSize=max(maxSize,(i-row+1)*minWidth);
                }
            }
        }
        return maxSize;
    }
};
// @lc code=end
int main(){
    Solution s;
    vector<vector<char> > c(4);
    c[0]={'1','0','1','0','0'};
    c[1]={'1','0','1','1','1'};
    c[2]={'1','1','1','1','1'};
    c[3]={'1','0','0','1','0'};
    s.maximalRectangle(c);
}
