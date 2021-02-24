//wrong answer
#include <bits/stdc++.h>
using namespace std;
int price[24];
int time_range[25];
typedef string Time;
struct Record
{
    Time start_time, end_time;
    int month;
    float cost;
    int range;
    Record() {}
    Record(const Time &s, const Time &e) : start_time(s), end_time(e), cost(0){};
    bool operator<(const Record &e) const
    {
        return start_time < e.start_time;
    }
};

struct TimeRecord
{
    //1表示开，0表示关
    bool type;
    Time time;
    TimeRecord(bool _type, const Time &_time) : type(_type), time(_time) {}
    bool operator<(const TimeRecord &e) const
    {
        return time < e.time;
    }
};
map<string, set<Record>> m_rec;
unordered_map<string, set<TimeRecord>> M;

float oneDay;

void getRange()
{
    for (int i = 0; i <= 24; ++i)
    {
        time_range[i] = 60 * i;
    }
}
float getNum(char c1, char c2)
{
    return (c1 - '0') * 10 + c2 - '0';
}
int getMonth(Record &rec)
{
    Time t1 = rec.start_time;
    int mo1 = getNum(t1[0], t1[1]);
    return mo1;
}
void getTwoCost(Record &rec)
{
    Time t1 = rec.start_time, t2 = rec.end_time;

    int d1 = getNum(t1[3], t1[4]);
    int d2 = getNum(t2[3], t2[4]);

    int h1 = getNum(t1[6], t1[7]);
    int h2 = getNum(t2[6], t2[7]);

    int m1 = getNum(t1[9], t1[10]);
    int m2 = getNum(t2[9], t2[10]);

    rec.range = (d2 - d1) * 24 * 60 + (h2 - h1) * 60 + m2 - m1;

    int time1 = h1 * 60 + m1;
    int time2 = h2 * 60 + m2;

    int rank1 = upper_bound(time_range, time_range + 25, time1) - time_range - 1;
    int rank2 = upper_bound(time_range, time_range + 25, time2) - time_range - 1;

    int cost = 0;
    //跨小时
    if (rank2 > rank1)
    {
        //计算跨小时的部分
        //先算零头
        cost += price[rank2] * m2;
        cost += price[rank1] * (60 - m1);
        //如果跨多个小时，都加上
        for (int i = rank1 + 1; i <= rank2 - 1; ++i)
        {
            cost += price[i] * 60;
        }
        //跨天
        if (d2 > d1)
        {
            cost += (d2 - d1) * oneDay;
        }
    }
    //rank2<rank1,跨天
    else if (d2 > d1)
    {
        cost += price[rank2] * m2;
        cost += price[rank1] * (60 - m1);
        for (int i = 0; i <= rank2 - 1; ++i)
        {
            cost += price[i] * 60;
        }
        for (int i = rank1 + 1; i <= 24; ++i)
        {
            cost += price[i] * 60;
        }
        if (d2 - 1 > d1)
        {
            cost += (d2 - d1 - 1) * oneDay;
        }
    }
    rec.start_time = rec.start_time.substr(3, 8);
    rec.end_time = rec.end_time.substr(3, 8);
    rec.cost = cost;
}

void getCost_print()
{
    //重载减法
    for (auto iter = m_rec.begin(); iter != m_rec.end(); ++iter)
    {
        auto p = *iter->second.begin();
        cout << iter->first << " ";
        printf("%02d\n", getMonth(p));
        float cost = 0;
        for (auto it = iter->second.begin(); it != iter->second.end(); ++it)
        {
            Record rec = *it;
            getTwoCost(rec);
            cout << rec.start_time << " " << rec.end_time << " " << rec.range << " $" << setiosflags(ios::fixed) << setprecision(2) << (float)rec.cost / 100 << endl;
            cost += rec.cost;
        }
        if(cost)
        cout << "Totol amount: $" << setiosflags(ios::fixed) << setprecision(2) << (float)cost / 100 << endl;
    }
}
int main()
{
    for (int i = 0; i < 24; ++i)
    {
        cin >> price[i];
        oneDay += price[i] * 60;
    }
    getRange();
    int n;
    cin >> n;
    Time time;
    string name, type;
    for (int i = 0; i < n; ++i)
    {
        cin >> name >> time >> type;
        //type is on
        if (type[1] == 'n')
        {
            M[name].insert(TimeRecord(1, time));
        }
        else
        {
            M[name].insert(TimeRecord(0, time));
        }
    }
    vector<Time> S;
    string on_time, off_time;
    for (auto iter = M.begin(); iter != M.end(); ++iter)
    {
        S.clear();
        for (auto it = iter->second.begin(); it != iter->second.end(); ++it)
        {
            //括号匹配。对排好序的时间，用栈来两两配对，得到时间对
            if (it->type == 0)
            {
                if (!S.empty())
                {
                    on_time = S.back();
                    S.pop_back();
                    m_rec[iter->first].insert(Record(on_time, it->time));
                }
            }
            else
            {
                S.push_back(it->time);
            }
        }
    }
    getCost_print();
}