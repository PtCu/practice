#include <bits/stdc++.h>
using namespace std;
struct Stuff
{
    int value;
    int weight;
    Stuff(){};
    Stuff(const int &v, const int &w) : value(v), weight(w) {}
};

vector<Stuff> stuffs;

int brute(int index, int capacity)
{
    if (index < 0 || capacity <= 0)
        return 0;
    //不放第i个的价值
    int res = brute(index - 1, capacity);
    //权衡是否能放第i个
    if (capacity >= stuffs[index].weight)
    {
        res = max(res, brute(index - 1, capacity - stuffs[index].weight) + stuffs[index].value);
    }

    return res;
}

int main()
{
    int T, M;
    cin >> T >> M;
    int v, w;
    for (int i = 0; i < M; i++)
    {
        cin >> w >> v;
        stuffs.push_back(Stuff(v, w));
    }
    int ans = brute(M - 1, T);
    cout << ans;
}