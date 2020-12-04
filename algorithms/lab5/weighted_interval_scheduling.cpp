#include <bits/stdc++.h>
using namespace std;

const int maxn = 30;

struct Request
{
    int b, e, v; //开始，结束，价值
    Request() {}
    Request(const int &_b, const int &_e, const int &_v) : b(_b), e(_e), v(_v) {}
};

vector<Request> requests;
vector<int> opt;
vector<pair<bool, int>> S; //记录选择的清况
int n;         //活动总数
vector<int> p; //p[i]表示活动i之前的所有活动里面离i最近并且相容的活动
void dp()
{
    opt[0] = 0;
    //初始化p，找到在活动i之前的所有活动里面离i最近并且相容的活动
    for (size_t i = 1; i <= n; ++i)
    {
        for (int j = i - 1; j > 0; --j)
        {
            if (requests[j].e <= requests[i].b)
            {
                p[i] = j;
                break;
            }
        }
    }

    for (size_t i = 1; i <= n; ++i)
    {
        //如果选i得到的价值更大
        if (opt[p[i]] + requests[i].v >= opt[i - 1])
        {
            //就选择i。更新opt记录
            opt[i] = opt[p[i]] + requests[i].v;
            //记录选择。考虑活动i的时候选择了参加活动n，搭配上前面{1, 2, …, p(i)}中的最优组合。
            S[i].first = true;
            S[i].second = p[i];
        }
        else
        {
            opt[i] = opt[i - 1];
            //放弃活动i，此时活动的选择情况还是与之前考虑活动i-1时候的情况一致
            S[i].first = false;
            S[i].second = i - 1;
        }
    }
    cout << "最大价值为： ";
    cout << opt[n] << endl;
    cout << "执行的任务为: ";
    for (size_t i = n; i >= 1; i = S[i].second)
    {
        if (S[i].first == true)
        {
            cout << i << " ";
        }
    }
}
int main()
{

    cout << "输入任务总数" << endl;
    cin >> n;
    int b, e, v;
    requests.push_back({0, 0, 0});
    cout << "输入开始时间、结束时间、价值" << endl;
    for (size_t i = 0; i < n; ++i)
    {
        cin >> b >> e >> v;
        requests.push_back({b, e, v});
    }
    sort(requests.begin(), requests.end(), [](const Request &a, const Request &b) -> bool { return a.e < b.e; });
    opt.resize(n + 1);
    S.resize(n + 1);
    p.resize(n + 1);
    dp();
}