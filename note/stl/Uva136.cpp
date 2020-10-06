//计算丑数 优先队列
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int coef[3] = {2, 3, 5};
int main()
{
    priority_queue<LL, vector<LL>, greater<LL>> pg; //队列中的元素从小到大排序
    set<LL> s;
    pg.push(1);
    s.insert(1);
    for (int i = 1;; i++)
    {
        LL x = pg.top();
        pg.pop();   //用过的需要丢弃掉
        if (i == 1500)
        {
            cout << "结果为" << x << endl;
            break;
        }
        for (int j = 0; j < 3; j++) //每次生成3个，并检查生成的三个是否已经存在
        {
            LL x2 = coef[j] * x;
            if (!s.count(x2))
            {
                s.insert(x2);
                pg.push(x2);
            }
        }
    }
}