#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
int color_num;
int node_color[maxn];
int matrix[maxn][maxn];
//测试数据
// 0 1 1 0 0
// 1 0 1 1 1
// 1 1 0 0 1
// 0 1 0 0 1
// 0 1 1 1 0
int n;
int sum = 0;
//当前染色是否符合要求
bool isValid(int node)
{
    for (int i = 0; i < n; ++i)
    {
        if (matrix[node][i])
        {
            if (node_color[i] == node_color[node])
            {
                return false;
            }
        }
    }
    return true;
}

//染色
void shade(int node)
{
    if (node > n - 1)
    {
        cout << "方案为" << endl;
        for (int i = 0; i < n; ++i)
        {
            cout << node_color[i] << " ";
        }
        ++sum;
        cout << endl;
        return;
    }
    //对所有的颜色逐个尝试
    for (int i = 1; i <= color_num; i++)
    {
        node_color[node] = i;
        if (isValid(node))
        {
            //如果当前颜色符合要求就染下一个
            shade(node + 1);
        }
        node_color[node] = -1;
    }
}

int main()
{
    cout << "输入顶点数" << endl;
    cin >> n;
    cout << "输入颜色数" << endl;
    cin >> color_num;
    cout << "输入邻接矩阵表示的图" << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> matrix[i][j];
        }
    }
    shade(0);
    cout << "总方案数为" << sum << endl;
}