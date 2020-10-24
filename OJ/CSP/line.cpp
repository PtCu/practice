#include <bits/stdc++.h>
typedef struct Point
{
    int x;
    int y;
    Point(int a, int b) : x(a), y(b) {}
} Point;
std::vector<Point> A;
std::vector<Point> B;

bool classify(int t0, int t1, int t2)
{
    //根据第一个A的节点来确定位置：A的其他节点应该和第一个节点同侧，B的所有节点应该和第一个节点异侧
    if (t0 + t1 * A[0].x + t2 * A[0].y > 0) 
    {
        for (int i = 1; i < A.size(); i++) 
        {
            if (t0 + t1 * A[i].x + t2 * A[i].y <=0) //如果A中节点出现异侧
                return false;                       //返回失败
        }
        for (int i = 0; i < B.size(); i++)
        {
            if (t0 + t1 * B[i].x + t2 * B[i].y >= 0) //如果B中节点出现和A的同侧的
                return false;   //返回失败
        }   
    }

    else    
    {
        for (int i = 1; i < A.size(); i++) //对
        {
            if (t0 + t1 * A[i].x + t2 * A[i].y >= 0) //如果false
                return false;                       //返回失败
        }
        for (int i = 0; i < B.size(); i++)
        {
            if (t0 + t1 * B[i].x + t2 * B[i].y <= 0)
                return false;
        } //至此，A全部在直线的一侧
    }
    return true;
}
int main()
{
    int n, m;
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> n >> m;
    while (n--)
    {
        int x, y;
        std::cin >> x >> y;
        char type;
        std::cin >> type;
        type == 'A' ? A.push_back(Point(x, y)) : B.push_back(Point(x, y));
    }
    while (m--)
    {
        int t0, t1, t2;
        std::cin >> t0 >> t1 >> t2;
        classify(t0, t1, t2) ? std::cout << "Yes" << std::endl : std::cout << "No" << std::endl;
    }
}