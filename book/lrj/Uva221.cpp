#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 5;
struct Building
{
    int id;
    double x, y, w, d, h;
    bool operator>(const Building &rhs) const   //左下优先
    {
        return x < rhs.x || (x == rhs.x && y < rhs.y);
    }
} b[maxn];

int n;
double x[maxn * 2];

bool cover(int i, double mx)
{ //判断建筑物i是否能盖住mx
    return b[i].x <= mx && b[i].x + b[i].w > mx;
}

//判断建筑物i在x=mx处是否可见
bool visible(int i, double mx)
{
    if (!cover(i, mx)) //不能遮盖
        return false;
    for (int k = 0; k < n; k++) //i被建筑物k遮盖（高度没k高）
        if (b[k].y < b[i].y && b[k].h >= b[i].h && cover(k, mx))
            return false;
    return true;
}
int main()
{
    int kase = 0;
    while (scanf("%d", &n) == 1 && n)
    {
        for (int i = 0; i < n; i++)
        {

            scanf("%lf%lf%lf%lf%lf", &b[i].x, &b[i].y, &b[i].w, &b[i].d, &b[i].h);
            x[i * 2] = b[i].x;
            x[i * 2 + 1] = b[i].x + b[i].w;
            b[i].id = i + 1;
        }
        sort(b, b + n); //building里面重载了>
        sort(x, x + n * 2);

        //unique的作用是“去掉”容器中相邻元素的重复元素（不一定要求数组有序），它会把重复的元素添加到容器末尾（所以数组大小并没有改变），而返回值是去重之后的尾地址
        int m = unique(x, x + n * 2) - x; //x坐标排序后去重，得到m个坐标。
        if (kase++)
            printf("\n");

        for (int i = 1; i < n; i++)
        {
            bool vis = false;
            for (int j = 0; j < m - 1; j++)
                if (visible(i, (x[j] + x[j + 1]) / 2))  //只需判断中点是否可见即可
                {
                    vis = true;
                    break;
                }
            if (vis)
                printf("% d", b[i].id);
        }
        printf("\n");
    }
    return 0;
}