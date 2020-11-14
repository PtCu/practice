#include <bits/stdc++.h>
using namespace std;
const int maxn = 10 + 1;

//节点数量
int N;
//记录这些节点是否访问过
bool visited[maxn];
//记录最终的最小代价
int final_res = INT_MAX;
//保存最终路径
int final_path[maxn + 1];

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

//cur_bound：根节点的下界
//cur_weight：从根节点到现在的路径的代价
//level：空间树的层级
//cur_path：记录路径
void recur(const vector<vector<int>> &mat, int cur_bound, int cur_weight, int level, int cur_path[])
{
    //递归基：如果到达叶子节点,即到达level N,说明所有地点都走了一遍
    if (level == N)
    {
        //如果最后一个节点到第一个节点还有路径
        if (mat[cur_path[level - 1]][cur_path[0]] != 0)
        {
            //将这条路径的代价加上去
            int cur_res = cur_weight + mat[cur_path[level - 1]][cur_path[0]];
            //如果当前路径更好
            if (cur_res < final_res)
            {
                final_res = cur_res;
                //覆盖最终结果
                copy(cur_path, cur_path + N, final_path);
            }
        }
        return;
    }
    //对邻接顶点构建查找树
    for (int i = 0; i < N; ++i)
    {
        //对于level-1，如果没有访问过邻居i并且存在level-1到i的路径
        if (mat[cur_path[level - 1]][i] != 0 && !visited[i])
        {
            int temp = cur_bound;
            //加上这条边的代价
            cur_weight += mat[cur_path[level - 1]][i];

            //调整当前节点的下界使得下界更接近真实值
            //节点0需要减去节点0和节点1的最小边的一半，再加上边0-1，即
//             Lower Bound for vertex 1 = 
//    Old lower bound - ((minimum edge cost of 0 + 
//                     minimum edge cost of 1) / 2) 
//                   + (edge cost 0-1)
            if (level == 1)
            {
                cur_bound -= ((firstMin(mat, cur_path[level - 1]) + firstMin(mat, i)) / 2);
            }
            //对于其他节点level-1，由于level-1的最小边已经在level-2中减去，所以在level-1中应当减去第二小的边。
            //同时要减去邻居的最小边（也就是子节点的最小边）
            //最后加上边(level-1)-i
            else
            {
                cur_bound -= ((secondMin(mat, cur_path[level - 1]) + firstMin(mat, i)) / 2);
            }

            //下界为cur_bound+cur_weight。如果下界小于当前结果说明有搞头要继续深入查找
            if (cur_bound + cur_weight < final_res)
            {
                cur_path[level] = i;
                visited[i] = true;

                //继续向level+1深入查找
                recur(mat, cur_bound, cur_weight, level + 1, cur_path);
            }

            //如果
            cur_weight -= mat[cur_path[level - 1]][i];
            cur_bound = temp;

            memset(visited, false, sizeof(visited));
            for (int j = 0; j <= level - 1; ++j)
            {
                visited[cur_path[j]] = true;
            }
        }
    }
}
void solve(const vector<vector<int>> &mat)
{
    //记录路径
    int cur_path[N + 1];

    int cur_bound = 0;
    memset(cur_path, -1, sizeof(cur_path));
    memset(visited, 0, sizeof(visited));

    //计算下界
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

int main()
{
    vector<vector<int>> mat;
    cout << "请输入以邻接矩阵表示的图，按ctrl+Z表示输入结束" << endl;
    input_vector(mat);
    // mat = {
    //     {-1, 3, 6, 7},
    //     {12, -1, 2, 8},
    //     {8, 6, -1, 2},
    //     {3, 7, 6, -1}};
    N = mat.size();

    solve(mat);

    cout << "最短路径的代价为" << endl;
    cout << final_res << endl;
    cout << "路径为:" << endl;
    for (int i = 0; i < N; ++i)
        cout << final_path[i] << "->";
    cout << final_path[N];
    return 0;
}
