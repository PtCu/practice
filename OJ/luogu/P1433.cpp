#include <bits/stdc++.h>
using namespace std;
struct Point
{
    float x, y;
    Point() {}
    Point(const float &fx, const float &fy) : x(fx), y(fy) {}
};

float calDistance(const Point &a, const Point &b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

// vector<bool> visited;
// float ans = INT32_MAX;
// void dfs(int j, const Point &k, float sum)
// {
//     if (j == n)
//     {
//         ans = min(ans, sum);
//         return;
//     }

//     for (int i = 0; i < n; i++)
//     {
//         if (visited[i])
//             continue;
//         visited[i] = true;
//         dfs(j + 1, points[i], sum + calDistance(points[i], k));
//         visited[i] = false;
//     }
// }

// i=5~000101表示点1和点3已被访问
// dp[i][j]表示分析在当前的状态i下，路径都为已经访问过的城市，找一条最短路径到达的点j的总距离
//        相应的状态转移方程为dp[ i ][ j]=min(dp[ i ][ j], dp[ i ^ (1<<j) ][ k ] + dis[ k ][ j ]  );
//  i ^ (1<<j)的意思是将j这个城市从i状态中去掉。 dis[ k][ j ] 是k和j之间的距离。
// if (i&(1<<(j - 1))) 表示判断j是否被访问过
float dp[35000][20];
int main()
{
    int n;
    float a, b;
    cin >> n;
    vector<Point> points;
    // visited.resize(n, false);
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        points.push_back(Point(a, b));
    }
    //O(n^2*2^n) 
    memset(dp, 127, sizeof(dp)); //填充为1<<127
    for (int i = 0; i < (1 << n); ++i) //所有状态
    {
        for (int j = 0; j < n; ++j)
        {
            //该状态没走j点
            if ((i & (1 << j)) == 0)
                continue;
            //该状态只走了j点，则走过j点的最短路径为0
            if (i == (1 << j))
            {
                dp[i][j] = 0;
                continue;
            }
            //该状态走过j点且还走过其他点，看是否经过其他点到达j点路径更短
            for (int k = 0; k < n; ++k)
            {
                //该状态没走过k点，跳过
                if ((i & (1 << k)) == 0 || j == k)
                    continue;
                //该状态走过k点, 比较由i经k到达j是否更短
                dp[i][j] = min(dp[i][j], dp[i - (1 << j)][k] + calDistance(points[k], points[j]));
            }
        }
    }
    float ans = FLT_MAX;
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, dp[(1 << n) - 1][i] + calDistance(Point(0, 0), points[i]));
    }
    cout << fixed << setprecision(2) << ans;
    return 0;
}