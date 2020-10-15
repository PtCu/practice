#include <bits/stdc++.h>
using namespace std;
const int mul = 1e9;
//两个商品分数相同时：
//如果是同一类商品，则选择编号较小的
//如果是不同类商品，选择类号较小的
//所以可按类别将各个编号排序，类别小的编号小，类别大的编号大
struct Commodity
{
    int id;
    int score;
    Commodity(int _id, int _score) : id(_id), score(_score) {}
    bool operator<(const Commodity &c) const
    {
        //按分数从大到小排序，大的在前面，小的在后面。如果分数一样的话，id小的在前面，大的在后面
        return score != c.score ? score > c.score : id < c.id;
    }
};
int m, n, t;
set<Commodity> commodities;
unordered_map<int, set<Commodity>::iterator> um; //用hash表来根据商品id直接定位商品,方便删除 对应映射为type*mul+id
void query(vector<int> k, int K)
{
    vector<vector<int>> ans(m);
    for (auto it = commodities.begin(); it != commodities.end();it++)
    {
        t = it->id / mul; //商品类型
        if (ans[t].size() < k[t])
        {
            ans[t].push_back(i.id % mul);
            if (--K== 0) //知识点7：区别一下 while(t--)和 if(--k==0) break;
                break;
        }
    }
    for(auto& i:ans)
    {
        if(i.empty())
            cout << "-1" << endl;
        else
        {
            for(auto& j:i)
            {
                cout << j << " ";
            }
            cout << endl;
        }
        
    }
}


int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    cin >> m >> n; //m类商品，每个商品中有n个

    for (int i = 0; i < n; i++)
    {
        int id, score;
        cin >> id >> score;
        for (int j = 0; j < m; j++)
        {
            // commodities[j].insert(make_pair(id, score)); 另一种写法
            int a = j * mul + id;
            um[a] = commodities.insert(Commodity(a, score)).first; //在每类商品中对应的id下插入score
        }
    }
    int op_num;
    cin >> op_num;

    while (op_num--)
    {
        vector<int> k(m); //查询操作的上限  第i类商品的个数不超过k_i
        int op;
        cin >> op;
        if (op == 1)
        {
            int type, commodity, score;
            cin >> type >> commodity >> score;
            int a = type * mul + commodity;
            um[a] = commodities.insert(Commodity(a, score)).first;
        }

        else if (op == 2)
        {
            int type, commodity;
            cin >> type >> commodity;
            //删除
            int a = type * mul + commodity;
            commodities.erase(um[a]);
            um.erase(a);
            // commodities[type].erase(commodities[type].find(type)); 另一种写法，根据迭代器删除 find返回的迭代器
        }

        else
        { //查询操作
            int K;
            cin >> K; //所有商品中选出不超过K个

            for (int i = 0; i < m; i++)
            {
                cin >> k[i]; //第i类商品中不超过k_i个
            }
            query(k, K);
        }
    }
}
