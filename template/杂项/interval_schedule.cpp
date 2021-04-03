#include <bits/stdc++.h>
using namespace std;
struct Job
{
    float start_time;
    float finish_time;
};
int main()
{
    int num;
    cout << "请输入讲座的数目:" << endl;
    cin >> num;
    vector<Job> jobs(num);
    cout << "请依次输入讲座的开始时间、结束时间:" << endl;
    for (int i = 0; i < num; ++i)
    {
        cin >> jobs[i].start_time >> jobs[i].finish_time;
    }
    sort(jobs.begin(), jobs.end(), [](const Job &a, const Job &b) { return a.finish_time < b.finish_time; });
    vector<Job> outcome;
    outcome.push_back(jobs.front());
    for (size_t i = 1; i < num; ++i)
    {
        if (jobs[i].start_time >= outcome.back().finish_time)
        {
            outcome.push_back(jobs[i]);
        }
    }
    cout << outcome.size();
}