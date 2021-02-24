#include <iostream>
#include <cstdio>
#include <map>
#include <vector>

using namespace std;

int Stamp(string t)
{
    int MM, dd, hh, mm;
    sscanf(t.c_str(), "%d:%d:%d:%d", &MM, &dd, &hh, &mm);
    return dd * 1440 + hh * 60 + mm;
}

double Amount(int stamp, vector<int> &toll)
{
    double ans = stamp / 1440 * toll[24];
    int HH = 0;
    stamp %= 1440;
    while (stamp >= 60)
    {
        ans += 60 * toll[HH++ % 24];
        stamp -= 60;
    }
    ans += stamp * toll[HH % 24];
    return ans / 100;
}

void Bill(pair<string, map<string, string>> customer, vector<int> &toll)
{
    double total = 0;
    for (auto on = customer.second.begin(); on != customer.second.end(); on++)
        if (on->second == "off-line" && on != customer.second.begin())
        {
            auto off = on--;
            if (on->second == "on-line")
            {
                int onStamp = Stamp(on->first);
                int offStamp = Stamp(off->first);
                if (total == 0)
                    cout << customer.first << ' ' << on->first.substr(0, 2) << endl;
                cout << on->first.substr(3, 8) << ' ' << off->first.substr(3, 8) << ' ';
                cout << offStamp - onStamp << ' ';
                double sum = Amount(offStamp, toll) - Amount(onStamp, toll);
                printf("$%.2f\n", sum);
                total += sum;
            }
            ++on;
        }
    if (total)
        printf("Total amount: $%.2f\n", total);
}

int main()
{
    map<string, map<string, string>> record;
    vector<int> toll(25, 0);
    for (int i = 0; i < 24; i++)
        cin >> toll[i];
    for (int i = 0; i < 24; i++)
        toll[24] += toll[i];
    toll[24] *= 60;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string name, time, status;
        cin >> name >> time >> status;
        record[name][time] = status;
    }
    for (auto x : record)
        Bill(x, toll);
}