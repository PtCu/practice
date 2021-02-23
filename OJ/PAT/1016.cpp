#include <bits/stdc++.h>
using namespace std;
int price[24];
typedef string Time;
struct Record
{
    Time start_time, end_time;
    float cost;
    Record(const Time &s, const Time &e) : start_time(s), end_time(e), cost(0){};
};
float getNum(char c1, char c2)
{
    return (c1 - '0') * 10 + c2 - '0';
}
float operator-(const Time &t1, const Time t2)
{
    int d1 = getNum(t1[0], t1[1]);
    int d2 = getNum(t2[0], t2[1]);

    int h1 = getNum(t1[3], t1[4]);
    int h2 = getNum(t2[3], t2[4]);

    int m1 = getNum(t1[6], t1[7]);
    int m2 = getNum(t2[6], t2[7]);

    float s1 = getNum(t1[9], t1[10]);
    float s2 = getNum(t1[9], t1[10]);

    return (d1 - d2) * 24 * 60 + (h1 - h2) * 60 + m1 - m2 + (float)(s1 - s2) / 60;
}
struct TimeRecord
{
    //1表示开，0表示关
    bool type;
    Time time;
    TimeRecord(bool _type, const Time &_time) : type(_type), time(_time) {}
    bool operator<(const TimeRecord &e)
    {
        return time < e.time;
    }
};
multimap<string, Record> m_rec;
unordered_map<string, set<TimeRecord>> M;
void getCost()
{
    //重载减法
    for (auto iter = m_rec.begin(); iter != m_rec.end(); ++iter)
    {
    }
}
int main()
{
    for (int i = 0; i < 24; ++i)
    {
        cin >> price[i];
    }
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
                    m_rec.insert(make_pair(iter->first, Record(on_time, it->time)));
                }
            }
            else
            {
                S.push_back(it->time);
            }
        }
    }
}