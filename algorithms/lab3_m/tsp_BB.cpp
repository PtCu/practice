#include <bits/stdc++.h>
using namespace std;
const int maxn = 10 + 1;
//邻接矩阵
int matrix[maxn][maxn];
//节点数量
int N;
//记录这些节点是否访问过
bool visited[maxn];
//记录最终的最小代价
int final_res = INT_MAX; 
//保存
int final_path[maxn+1]; 
//求节点i的最小邻居
int firstMin(const vector<vector<int>> &mat, int i)
{
    int min = INT_MAX;
    for (int k = 0; k < N; ++k)
    {
        if (mat[i][k] < min && k != i)
            min = mat[i][k];
    }
    return min;
}

//求节点i的第二小邻居
int secondMin(const vector<vector<int>> &mat, int i)
{
    int first = INT_MAX, second = INT_MAX; //第一小的，第二小的
    for (int j = 0; j < N; ++j)
    {
        if (i == j)
            continue;
        if (mat[i][j] < first)
        {
            first = mat[i][j];
            second = first;
        }
        else if (mat[i][j] < second && mat[i][j] > first)
        {
            second = mat[i][j];
        }
    }
    return second;
}
void recur(const vector<vector<int>> &mat, int cur_bound, int cur_weight, int level, int cur_path[])
{
    //递归基：如果到达叶子节点，即到达level N。说明所有地点都走了一遍
    if (level == N)
    {
        if (mat[cur_path[level - 1]][cur_path[0]] != 0)
        {
            int cur_res = cur_weight + mat[cur_path[level - 1]][cur_path[0]];
            if(cur_res<final_)
        }
    }
}
void solve(const vector<vector<int>> &mat)
{
    //记录路径
    int cur_path[N + 1];

    int cur_bound = 0;
    memset(cur_path, -1, sizeof(cur_path));
    memset(visited, 0, sizeof(cur_path));

    //计算初始的下界
    for (int i = 0; i < N; ++i)
    {
        cur_bound += (firstMin(mat, i) + secondMin(mat, i));
    }

    //取整
    cur_bound = (cur_bound & 1) ? cur_bound / 2 + 1 : cur_bound / 2;

    //从顶点1开始。路径此时为0
    visited[0] = true;
    cur_path[0] = 0;

    recur(mat, cur_bound, 0, 1, cur_path);
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
    N = mat.size() - 1;

    solve(mat);

    cout << "最短路径的代价为" << endl;
}
int main()
{
    test();
}
