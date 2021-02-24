#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
const int START = 8 * 3600;
const int END = 17 * 3600;
map<string, int> M;
struct Window
{
    int finish;
    Window() { finish = START; }
} windows[maxn];
int to_seconds(string time)
{
    int hh, mm, ss;
    sscanf(time.c_str(), "%02d:%02d:%02d", &hh, &mm, &ss);
    return hh * 3600 + mm * 60 + ss;
}
int main()
{
    int n, k;
    cin >> n >> k;
    string time_stamp;
    int time;
    int total = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> time_stamp >> time;
        if (to_seconds(time_stamp) < END)
        {
            M[time_stamp] = time;
            total++;
        }
    }
    int wait_time = 0;
    for (auto iter = M.begin(); iter != M.end(); ++iter)
    {
        int arriving_time = to_seconds(iter->first);
        int id = 0;
        //挑选最先结束的
        for (int i = 1; i < k; ++i)
        {
            if (windows[i].finish < windows[id].finish)
            {
                id = i;
            }
        }
        //第二波人到来时，第一波还没办理完业务，需要等待
        if (arriving_time < windows[id].finish)
        {
            wait_time += windows[id].finish - arriving_time;
            windows[id].finish += iter->second * 60;
        }
        //第一波人已经办理完业务，此时无需等待
        else
        {
            windows[id].finish = arriving_time + iter->second * 60;
        }
    }
    cout << setiosflags(ios::fixed) << setprecision(1) << (float)wait_time / (60 * total);
}