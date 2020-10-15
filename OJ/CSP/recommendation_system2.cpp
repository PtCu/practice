#include <bits/stdc++.h>
using namespace std;

struct Commodity
{
    long long id, score;
    Commodity(long long id, long long score) : id(id), score(score) {}
    //知识点1： 重载set的运算符，传参是const，重载的函数还是个常函数
    //set里按该运算符进行排序，set的实现也是红黑树
    bool operator<(const Commodity &c) const
    {
        return this->score != c.score ? this->score > c.score : this->id < c.id;
    }
};

int main()
{
    //freopen("data.in","r",stdin);

    long long m, n, op, id, score, k, c, t;
    cin >> m >> n;
    const long long mul = (long long)1e9; //知识点2：用大常数实现数组，（看情况使用）

    vector<long long> K(m);                                //查询3里：每类物品挑选上限
    set<Commodity> commodities;                            //知识点3：set里用
    unordered_map<long long, set<Commodity>::iterator> um; //知识点4：unordered_map里存结构体指针
    //知识点5：unorder_map和map的区别：
    //unordered_map实现是hash，查询复杂度基本是常数
    //map的实现是红黑树，查询复杂度O(logn)
    //set插入 pair<iterator,bool> insert (const value_type& val);返回一个pair，其中第一个为iterator

    for (int i = 0; i < n; i++)
    {
        cin >> id >> score;
        for (int j = 0; j < m; j++)
        {
            long long a = mul * j + id;
            //知识点6：set的insert返回的是pair，first是iterator，second是bool
            um[a] = commodities.insert(Commodity(a, score)).first;
        }
    }

    cin >> op;
    while (op--)
    {
        cin >> c;
        if (c == 1)
        {
            cin >> t >> id >> score;
            long long a = t * mul + id;
            um[a] = commodities.insert(Commodity(a, score)).first;
        }
        else if (c == 2)
        {
            cin >> t >> id;
            long long a = t * mul + id;
            commodities.erase(um[a]);
            um.erase(a);
        }
        else if (c == 3)
        {
            cin >> k;
            vector<vector<long long>> ans(m);
            for (int i = 0; i < m; i++)
            {
                cin >> K[i];
            }
            for (auto &i : commodities)
            {
                t = i.id / mul; //商品类型
                if (ans[t].size() < K[t])
                {
                    ans[t].push_back(i.id % mul);
                    if (--k == 0) //知识点7：区别一下 while(t--)和 if(--k==0) break;
                        break;
                }
            }

            //知识点8：合理使用auto进行迭代，这个里就避开了第二层vector empty的问题
            for (auto &i : ans)
            {
                if (i.empty())
                {
                    cout << "-1";
                }
                else
                {
                    for (auto &j : i)
                    {
                        cout << j << " ";
                    }
                }
                cout << endl;
            }
        }
    }
    return 0;
}