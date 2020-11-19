#include <iostream>
using namespace std;

// const int N = 5;
// const int MAX = 9999999;
// float p[N + 1] = {0, 0.15, 0.10, 0.05, 0.1, 0.20};
// float q[N + 1] = {0.05, 0.10, 0.05, 0.05, 0.05, 0.10};
const int N = 16;
const int MAX = 9999999;
float p[N + 1] = {
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
float q[N + 2] = {
    0,1.0 / 128,1.0 / 128,1.0 / 64,1.0 / 32,1.0 / 16,1.0 / 8,1.0 / 4,1.0 / 2,0,0,0, 0, 0,0,0,0,0};

float e[N + 2][N + 1];  //子树期望代价
int root[N + 1][N + 1]; //记录根节点
float w[N + 2][N + 1];  //子树概率总和

void optimal_bst_search_tree(float p[], float q[], int n)
{
    int i;
    for (i = 1; i <= n + 1; i++)
    {
        e[i][i - 1] = q[i - 1];
        w[i][i - 1] = q[i - 1];
    }
    int l, j, r;
    for (l = 1; l <= n; l++)
    {
        for (i = 1; i <= n - l + 1; i++) //步长
        {
            j = i + l - 1;
            e[i][j] = MAX;
            w[i][j] = w[i][j - 1] + p[j] + q[j];
            for (r = i; r <= j; r++)
            {
                double t = e[i][r - 1] + e[r + 1][j] + w[i][j];
                if (t < e[i][j])
                {
                    e[i][j] = t;
                    root[i][j] = r;
                }
            }
        }
    }
}

void print_root()
{
    int i, j;
    cout << "各子树的根：" << endl;
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
            cout << root[i][j] << " ";
        cout << endl;
    }
}

void construct_optimal_bst(int i, int j)
{
    if (i <= j)
    {
        int r = root[i][j];
        cout << r << " ";
        construct_optimal_bst(i, r - 1);
        construct_optimal_bst(r + 1, j);
    }
}
void print_bst(int i, int j)
{
    if (i == 1 && j == N)
        cout << "root is " << root[i][j] << endl;
    if (i < j)
    {
        int r = root[i][j];
        if (i != r)
            cout << "left child root " << root[i][r - 1] << endl;
        print_bst(i, root[i][j] - 1);
        if (j != r)
            cout << "right child root " << root[r + 1][j] << endl;
        print_bst(root[i][j] + 1, j);
    }
}
int main()
{
    optimal_bst_search_tree(p, q, N);
    print_root();
    cout << "构造的最优二叉树：" << endl;
    construct_optimal_bst(1, N);
    cout << endl;
    print_bst(1, N);
    cout << 1 + 3.0 / 4 + 0.5 + 5.0 / 16 + 6.0 / 32 + 7.0 / 64 + 8.0 / 128 + 9.0 / 128 << endl;
}