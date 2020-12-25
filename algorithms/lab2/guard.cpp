#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
bool guard[maxn][maxn];   //警卫分布情况
int overseen[maxn][maxn]; //每个陈列室被多少个警卫监控
bool ans[maxn][maxn];     //结果
int min_num_guard;        //最少警卫数目
int cur_num_guard;        //警卫数目
int n, m;
int not_monitored;

//在i,j处增设警卫
void addGuard(int i, int j)
{
    ++cur_num_guard;
    if (i >= 0 && i <= m - 1 && j >= 0 && j <= n - 1)
    {
        guard[i][j] = 1;
        if (!overseen[i][j])
            --not_monitored;
        ++overseen[i][j];
    }
    else
        return;
    //影响i,j处上下左右的陈列室状态
    //上
    if (i >= 1 && i <= m - 1 && j >= 0 && j <= n - 1)
    {
        if (!overseen[i - 1][j])
            --not_monitored;
        ++overseen[i - 1][j];
    }
    //左
    if (i >= 0 && i <= m - 1 && j >= 1 && j <= n - 1)
    {
        if (!overseen[i][j - 1])
            --not_monitored;
        ++overseen[i][j - 1];
    }
    //下
    if (i >= 0 && i <= m - 2 && j >= 0 && j <= n - 1)
    {
        if (!overseen[i + 1][j])
            --not_monitored;
        ++overseen[i + 1][j];
    }
    //右
    if (i >= 0 && i <= m - 1 && j >= 0 && j <= n - 2)
    {
        if (!overseen[i][j + 1])
            --not_monitored;
        ++overseen[i][j + 1];
    }
}

//撤销在i,j处的警卫
void removeGuard(int i, int j)
{
    --cur_num_guard;
    if (i >= 0 && i <= m - 1 && j >= 0 && j <= n - 1)
    {
        guard[i][j] = 0;
        --overseen[i][j];
        if (!overseen[i][j])
            ++not_monitored;
    }
    else
        return;
    //影响i,j处上下左右的陈列室状态
     //上
    if (i >= 1 && i <= m - 1 && j >= 0 && j <= n - 1)
    {
        --overseen[i - 1][j];
        if (!overseen[i - 1][j])
            ++not_monitored;
    }
    //左
    if (i >= 0 && i <= m - 1 && j >= 1 && j <= n - 1)
    {
        --overseen[i][j - 1];
        if (!overseen[i][j - 1])
            ++not_monitored;
    }
     //下
    if (i >= 0 && i <= m - 2 && j >= 0 && j <= n - 1)
    {
        --overseen[i + 1][j];
        if (!overseen[i + 1][j])
            ++not_monitored;
    }
     //右
    if (i >= 0 && i <= m - 1 && j >= 0 && j <= n - 2)
    {
        --overseen[i][j + 1];
        if (!overseen[i][j + 1])
            ++not_monitored;
    }
}

//找到下一个没人看守的陈列室
int next(int x)
{

    for (int i = x / n; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (!overseen[i][j])
            {
                return i * n + j;
            }
        }
    }
    return -1;
}
void trace(int x)
{
    //到达叶节点
    if (!not_monitored && cur_num_guard < min_num_guard)
    {
        //如果当前解更有，就替换
        min_num_guard = cur_num_guard;
        memcpy(ans, guard, sizeof(guard));
        return;
    }

    int i = x / n;
    int j = x % n;
    //越界
    if (i < 0 || i > m - 1 || j < 0 || j > n - 1)
        return;

    //在i,j处增设警卫
    addGuard(i, j);
    int nextPos = next(x);
    //递归
    trace(nextPos);
    //撤出警卫
    removeGuard(i, j);

    //在i,j+1处增设警卫
    if (j + 1 <= n - 1)
    {
        addGuard(i, j + 1);
        nextPos = next(x);
        //递归
        trace(nextPos);
        //撤出警卫
        removeGuard(i, j + 1);
    }

    //在i+1,j处增设警卫
    if (i + 1 <= m - 1)
    {
        addGuard(i + 1, j);
        nextPos = next(x);
        //递归
        trace(nextPos);
        //撤出警卫
        removeGuard(i + 1, j);
    }
}
int main()
{
    cout << "请输入陈列馆长和宽" << endl;
    cin >> m >> n;
    min_num_guard = m * n;
    not_monitored = m * n;
    cur_num_guard = 0;
    trace(0);
    cout << "所需的最少警卫数:" << min_num_guard << endl;

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

