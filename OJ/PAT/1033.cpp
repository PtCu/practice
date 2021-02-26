#include <bits/stdc++.h>
using namespace std;
const int maxn = 510;
struct Station
{
    double price, distance;
} stations[maxn];
bool cmp(const Station &a, const Station &b)
{
    return (a.distance == b.distance) ? a.price < b.price : a.distance < b.distance;
}
int main()
{
    int c, d, d_unit, n;
    cin >> c >> d >> d_unit >> n;
    double max_dis_cap = c * d_unit;
    for (int i = 0; i < n; ++i)
    {
        cin >> stations[i].price >> stations[i].distance;
    }
    //终点视为加油站
    stations[n].price = 0;
    stations[n].distance = d;
    sort(stations, stations + n, cmp);
    //当前油量
    double cur_c = 0;
    //目前的加油站下标
    int cur_station = 0;
    //花费
    double cost = 0;
    //当前行驶距离
    double cur_dis = 0;
    bool flag = true;
    if (stations[0].distance != 0)
    {
        cout << "The maximum travel distance = " << setiosflags(ios::fixed) << setprecision(2) << 0.0f;
        return;
    }
    while (cur_station != n)
    {

        int next_station = cur_station + 1;

        //贪心的选下一个加油站
        for (int i = next_station; i <= n && stations[cur_station].distance + max_dis_cap >= stations[i].distance; ++i)
        {
            //第一个比当前的要便宜的作为下一个
            if (stations[i].price < stations[cur_station].price)
            {
                next_station = i;
                break;
            }
            //没有比当前便宜的，找出下几个加油站中最便宜的
            else if (stations[i].price < stations[next_station].price)
            {
                next_station = i;
            }
        }
        //到不了
        if (stations[cur_station].distance + max_dis_cap < stations[next_station].distance)
        {

            cout << "The maximum travel distance = " << setiosflags(ios::fixed) << setprecision(2) << (stations[cur_station].distance + max_dis_cap);
            flag = false;
            break;
        }

        double need = (stations[next_station].distance - stations[cur_station].distance) / d_unit;

        //尽可能的多加便宜的油
        //如果下一个的价格更便宜
        if (stations[next_station].price < stations[cur_station].price)
        {
            //加到这个加油站距离的油量
            if (cur_c <= need)
            {
                cost += (need - cur_c) * stations[cur_station].price;
                cur_c = need;
            }
            cur_c -= need;
        }
        //下几个没有更便宜的
        else
        {
            //加满
            cost += (c - cur_c) * stations[cur_station].price;
            cur_c = c - need;
        }

        //到达这个加油站
        cur_station = next_station;
    }
    if (flag)
        printf("%.2lf", cost);
}