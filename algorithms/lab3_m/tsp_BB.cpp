#include<bits/stdc++.h>
using namespace std;
const int maxn = 10 + 1;
int matrix[maxn][maxn];



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
