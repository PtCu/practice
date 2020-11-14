#include <bits/stdc++.h>
using namespace std;
const int N = 3;
struct Node
{
    //父节点
    Node *parent;
    //当前的矩阵状态
    int mat[N][N];
    //当前的空白块坐标
    int x, y;
    //当前错位的数量
    int cost;
    //当前的层级
    int level;
    Node() = default;
    //在newX，newY处生成一个新节点
    Node(Node *p, int m[N][N],
         const int &_x, const int &_y,
         const int &l,
         const int &newX, const int &newY,
         const int &_c = INT_MAX) : parent(p), level(l), cost(_c), x(newX), y(newY)
    {
        memcpy(mat, m, sizeof(mat));
        swap(mat[_x][_y], mat[newX][newY]);
    }

    //计算现在到最终结果的差距（不正确的个数）,即计算h(x)
    void calCost(int final[N][N])
    {
        int count = 0;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (mat[i][j] && (final[i][j] != mat[i][j]))
                    ++count;
            }
        }
        cost = count;
    }
};

void printNode(Node *n)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
            cout << n->mat[i][j] << " ";
        cout << endl;
    }
}

void printPath(Node *p)
{
    if (!p)
        return;
    printPath(p->parent);
    printNode(p);
    cout << endl;
}
//核心：按照cost+level排序。cost为不正确的数字个数，level为深度。每次选择最小的进行搜索。
struct cmp
{
    bool operator()(const Node *lhs, const Node *rhs) const
    {
        return (lhs->cost + lhs->level) > (rhs->cost + rhs->level);
    }
};
int movement[4][2] = {{1, 0},
                      {0, -1},
                      {-1, 0},
                      {0, 1}};
void solve(int init[N][N], int x, int y, int final[N][N])
{
    //优先队列：按照代价排序。小的在前面
    priority_queue<Node *, vector<Node *>, cmp> pq;

    //初始根节点
    Node *root = new Node(nullptr, init, x, y, 0, x, y);
    root->calCost(final);

    //入队
    pq.push(root);
    int nx = 0, ny = 0;
    while (!pq.empty())
    {
        Node *cur = pq.top();
        pq.pop();
        //如果和答案一样了，就打印
        if (cur->cost == 0)
        {
            //递归打印
            printPath(cur);
            return;
        }

        for (int i = 0; i < 4; ++i)
        {
            nx = movement[i][0] + cur->x;
            ny = movement[i][1] + cur->y;
            if (nx >= 0 && nx < N && ny >= 0 && ny < N)
            {
                Node *child = new Node(cur, cur->mat, cur->x, cur->y, cur->level + 1, nx, ny);
                child->calCost(final);
                pq.push(child);
            }
        }
    }
}

int main()
{
    int init[N][N] = {{2, 8, 3},
                      {1, 6, 4},
                      {7, 0, 5}};

    int final[N][N] = {{1, 2, 3},
                       {8, 0, 4},
                       {7, 6, 5}};
    solve(init, 2, 1, final);
    return 0;
}