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

//输入：
//index:物品序号
//capacity:背包容量
//输出：在此背包容量下最大价值
int brute(int index, int capacity)
{
    if (index < 0 || capacity <= 0)
        return 0;
    //不放第i个的价值
    int res = brute(index - 1, capacity);
    //权衡是否放第i个物品
    if (capacity >= stuffs[index].weight)
    {
        //如果能放下，就看是放下此物品的价值大还是不放的价值大
        res = max(res, brute(index - 1, capacity - stuffs[index].weight) + stuffs[index].value);
    }

    return res;
}

int main()
{
    cout << "请输入背包容量和物品数目" << endl;
    int C, M; //背包的容量C和物品数M
    cin >> C >> M;
    int v, w;
    for (int i = 0; i < M; i++)
    {
        cin >> w >> v;  
        stuffs.push_back(Stuff(v, w));
    }
    cout << "最大价值为" << endl;
    int ans = brute(M - 1, C);
    cout << ans;
}