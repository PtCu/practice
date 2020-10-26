#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e2;
int n;
int pers[MAX][MAX];
int p_nums = 0;

//可以用stl的next_permutation，
//输入：nums；待排列的数组； start：排列的起始位置；end: 排列的末尾位置
void permutation(int nums[], int start, int end)
{
    //递归基
    if (start == end)
    {
        for (int i = 0; i <= end; i++)
        {
            pers[p_nums][i] = nums[i];
        }
        p_nums++;
    }
    else
    {
        for (int i = start; i <= end; i++)
        {
            //依次将i,i+1,...end各个数放在最开头
            swap(nums[i], nums[start]);
            //递归排列后面的数[start+1,end]
            permutation(nums, start + 1, end);
            //递归后还原
            swap(nums[i], nums[start]);
        }
    }
}
//遍历所有的排列，得到代价最低的路径
//输入：邻接矩阵表示的图
//输出：最短路径的代价
int brute(vector<vector<int>> &mat)
{

    int ans = INT32_MAX;
    //遍历每个排列
    for (int i = 0; i < p_nums; i++)
    {
        int sum = 0;
        for (int j = 0; j < n - 1; j++)
        {
            int cur = pers[i][j];
            //对每个排列，计算其路径和
            sum += mat[pers[i][j]][pers[i][j + 1]];
        }

        ans = min(sum, ans);
    }
    return ans;
}
//接受矩阵。按ctrl+z结束
void input_vector(vector<vector<int>> &vec)
{
    vector<int> v;
    while (!cin.eof())
    {
        int tmp(0);
        v.clear();
        string line;
        getline(cin, line);
        istringstream ss(line);
        while (ss >> tmp)
        {
            v.push_back(tmp);
        }
        vec.push_back(v);
    }
}
void test()
{

    vector<vector<int>> mat;
    cout << "请输入以邻接矩阵表示的图，按ctrl+Z表示输入结束" << endl;
    input_vector(mat);
    // mat = {
    //     {-1, 3, 6, 7},
    //     {12, -1, 2, 8},
    //     {8, 6, -1, 2},
    //     {3, 7, 6, -1}};
    n = mat.size()-1;
    int nums[MAX];
    for (int i = 0; i < n; i++)
    {
        nums[i] = i;
    }
    permutation(nums, 0, n - 1);

    cout << "最短路径的代价为" << endl;
    cout << brute(mat);
}
int main()
{
    test();
}
