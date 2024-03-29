#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
struct Stuff
{
    int value;  //价值
    int weight; //重量
    Stuff(){};
    Stuff(const int &v, const int &w) : value(v), weight(w) {}
};

vector<Stuff> stuffs;
int capacity; //背包总容量
int cur_cap;  //当前背包容量
int cur_v;    //当前背包价值
int ans = -1; //结果

void trace(int x)
{
    //到达叶节点
    if (x > stuffs.size() - 1)
    {
        ans = max(ans, cur_v);
        return;
    }

    if (cur_cap >= stuffs[x].weight)
    {
        //放入x
        cur_cap -= stuffs[x].weight;
        cur_v += stuffs[x].value;
        trace(x + 1);
        cur_cap += stuffs[x].weight;
        cur_v -= stuffs[x].value;
    }
    //不放x
    trace(x + 1);
}
int main()
{
    cout << "请输入背包容量和物品数目" << endl;
    int M; //背包的容量C和物品数M
    cin >> capacity >> M;
    cur_cap = capacity;
    int v, w;
    cout << "输入物品的重量、价值" << endl;
    for (int i = 0; i < M; i++)
    {
        cin >> w >> v;
        stuffs.push_back(Stuff(v, w));
    }
    cout << "最大价值为" << endl;
    trace(0);
    cout << ans;
}