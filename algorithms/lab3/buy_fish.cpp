//王伯买鱼
//https://blog.csdn.net/geneti/article/details/80257458
#include <bits/stdc++.h>
using namespace std;
vector<int> node;            //鱼
multimap<int, int> conflict; //冲突
int min_price;
int m, n;
int max_num;
vector<int> method;  //当前买鱼方案
vector<int> bmethod; //最佳买鱼方案
//num为当前买鱼条数，p为剩余的钱
//剪枝：
//1. 钱没花完但是已经没有鱼可以买了，买剩下的都有冲突（其实这个也可以算终止条件）
//2. 当前状态即使把预算未用完的钱全部买最便宜的鱼，还是比历史最大的买鱼条数小
void dfs(int num, int left_money)
{
    //剪枝1
    if (left_money < 0)
    {
        max_num = max(num - 1, max_num);
        return;
    }
    //剪枝2
    if (left_money / min_price + num < max_num)
    {
        return;
    }

    for (size_t i = 0; i < node.size(); ++i)
    {
        if (num == 0 && left_money == m)
        {
            method.push_back(i + 1);
            dfs(num + 1, left_money - node[i]);
            method.pop_back();
        }
        else
        {
            auto sz = conflict.count(i + 1);
            auto n_con = conflict.find(i + 1);
            
        }
    }
}
int main()
{

    cin >> m >> n;
    node.resize(n);
    int s, t;
    for (size_t i = 0; i < n; ++i)
    {
        cin >> s >> t;
        node[s] = t;
    }
    int p, q;
    while (cin >> p >> q && p && q)
    {
        conflict.insert(pair<int, int>(p, q));
        conflict.insert(make_pair(q, p));
    }
    min_price = *min_element(node.begin(), node.end());
}