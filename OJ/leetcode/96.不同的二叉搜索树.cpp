/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start

class Solution
{
public:
    int dict[20];
    int count_num(int n)
    {
        if (n == 0 || n == 1)
            return 1;
        if (n == 2)
            return 2;
        int left_num = 0, right_num = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (dict[i - 1] == 0)
                dict[i - 1] = count_num(i - 1);
            if (dict[n - i] == 0)
                dict[n - i] = count_num(n - i);
            dict[n] += dict[n - i] * dict[i - 1];
        }
        return dict[n];
    }
    int count_num2(int n)
    {
        dict[0] = 1;
        dict[1] = 1;
        //dict[n]的值依赖于dict[0],dict[1],dict[2],...dict[n-1]
        //故从小到大计算dict[i]
        for (int i = 2; i <= n; ++i)
        {
            for (int j = 1; j <= i; ++j)
            {
                dict[i] += dict[j - 1] * dict[i - j];
            }
        }
        return dict[n];
    }
    int numTrees(int n)
    {
        for (int i = 0; i < 20; ++i)
        {
            dict[i] = 0;
        }
        return count_num2(n);
    }
};
// @lc code=end
