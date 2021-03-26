#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int h[maxn];
struct Node
{
    int id, dis;
    Node() : id(0), dis(INT_MAX) {}
};
Node min_2[maxn][2];
int n;
int dis_ab[2]; // 1是a, 0是b
//int max_extend[maxn];
float travel(int s, int x)
{
    int cnt = 1;
    int d = 0;
    memset(dis_ab, 0, sizeof(dis_ab));
    for (int i = s; i < n; ++cnt)
    {
        int turn = cnt % 2;
        if (min_2[i][turn].dis == INT_MAX)
            break;
        if (min_2[i][turn].dis + d > x)
        {
            break;
        }
        else
        {
            d += min_2[i][turn].dis;
            dis_ab[turn] += min_2[i][turn].dis;
            i = min_2[i][turn].id;
        }
    }
    // max_extend[s] = max(max_extend[s], d);
    if (dis_ab[0] == 0)
        return numeric_limits<float>::max();
    float rate = (float)dis_ab[1] / dis_ab[0];
    return rate;
}
int travelAll(int x)
{
    float rate = numeric_limits<float>::max();
    int best = 0;
    for (int i = 1; i <= n; ++i)
    {
        auto tmp = travel(i, x);
        if (tmp < rate)
        {
            best = i;
            rate = tmp;
        }
        else if (tmp == rate)
        {
            if (h[i] > h[best])
            {
                best = i;
            }
        }
    }
    return best;
}

int main()
{

    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> h[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            int d = abs(h[j] - h[i]);
            if (d < min_2[i][0].dis)
            {
                min_2[i][1].dis = min_2[i][0].dis;
                min_2[i][1].id = min_2[i][0].id;
                min_2[i][0].dis = d;
                min_2[i][0].id = j;
            }
            //距离相同
            else if (d == min_2[i][0].dis)
            {
                //按海拔划分。海拔低的离得近
                if (h[j] < h[min_2[i][0].id])
                {
                    min_2[i][1].id = min_2[i][0].id;
                    min_2[i][1].dis = min_2[i][0].dis;
                    min_2[i][0].id = j;
                }
                //次小的
                else
                {
                    min_2[i][1].dis = d;
                    min_2[i][1].id = j;
                }
            }
            else if (d < min_2[i][1].dis)
            {
                min_2[i][1].dis = d;
                min_2[i][1].id = j;
            }
            else if (d == min_2[i][1].dis)
            {
                if (h[j] < h[min_2[i][1].id])
                {
                    min_2[i][1].id = j;
                }
            }
        }
    }
    int x0, m, si, xi;
    cin >> x0 >> m;
    cout << travelAll(x0) << endl;
    for (int i = 0; i < m; ++i)
    {
        cin >> si >> xi;
        travel(si, xi);
        cout << dis_ab[1] << " " << dis_ab[0] << endl;
    }
}