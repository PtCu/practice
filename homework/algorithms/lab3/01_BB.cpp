#include <bits/stdc++.h>
using namespace std;
int Capacity; //背包容量
int N;        //物品数量
struct Stuff
{
    int value;    //价值
    float weight; //重量
    Stuff(){};
    Stuff(const int &v, const int &w) : value(v), weight(w) {}
};

vector<Stuff> stuffs;
struct Node
{
    //level为结点在决策树的层级。可通过level来访问背包
    //profit为从根节点到这个结点的价值
    //bound为这个结点子树的最大价值
    int level, profit, bound;
    float weight;
};

//返回以u为根节点的子树的上界价值
int bound(Node u)
{
    //如果当前节点的重量大于容量，则子树没有价值
    if (u.weight > Capacity)
        return 0;

    //价值的上界
    int profit_bound = u.profit;

    //从下一个背包开始加起
    int j = u.level + 1;
    int totweight = u.weight;

    //将剩下的物品能加入的全加入
    while ((j < N) && (totweight + stuffs[j].weight <= Capacity))
    {
        totweight += stuffs[j].weight;
        profit_bound += stuffs[j].value;
        j++;
    }

    //如果还有剩下的，则按单位价值将其加入
    if (j < N)
    {
        profit_bound += (Capacity - totweight) * stuffs[j].value / stuffs[j].weight;
    }
    return profit_bound;
}

int solve()
{
    //按单位价值对背包进行排序
    sort(stuffs.begin(), stuffs.end(), [](Stuff a, Stuff b) { return a.value / a.weight > b.value / b.weight; });

    //遍历树的队列
    queue<Node> Q;
    Node u, v; //父子关系的两个结点

    //辅助结点
    u.level = -1;
    u.profit = u.weight = 0;
    Q.push(u);

    int maxProfit = 0;
    while (!Q.empty())
    {
        u = Q.front();
        Q.pop();

        //如果是最后一个结点就结束
        if (u.level == N - 1)
            continue;

        //如果不是最后一个结点就增加层级
        v.level = u.level + 1;

        //如果加入v.level的物品的话，计算子节点v的价值
        v.weight = u.weight + stuffs[v.level].weight;
        v.profit = u.profit + stuffs[v.level].value;

        if (v.weight <= Capacity && v.profit > maxProfit)
            maxProfit = v.profit;
        //计算上界。
        v.bound = bound(v);
        //如果上界大于当前最优解，则说明有潜力，需要入队
        if (v.bound > maxProfit)
            Q.push(v);

        //如果不加入v.level的话，计算子节点v的价值
        v.weight = u.weight;
        v.profit = u.profit;
        //计算上界
        v.bound = bound(v);
         //如果上界大于当前最优解，则说明有潜力，需要入队
        if (v.bound > maxProfit)
            Q.push(v);
        
    }
    return maxProfit;
}
int main()
{
    cout << "请输入背包容量和物品数目" << endl;
    //背包的容量C和物品数N
    cin >> Capacity >> N;
    int v, w;
    cout << "输入物品的重量、价值" << endl;
    for (int i = 0; i < N; i++)
    {
        cin >> w >> v;
        stuffs.push_back(Stuff(v, w));
    }
    // stuffs={{42,7},{12,3},{40,4},{25,5}};
    cout << "最大价值为" << endl;
    cout << solve();
}