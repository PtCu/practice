#include <bits/stdc++.h>
using namespace std;
struct Tree
{
    bool isDrop;  //是否掉落
    int cur_num;  //剩下的数量
    int total;    //原本的数量
    int pick_num; //采摘的数量
    Tree() : isDrop(false), cur_num(0), total(0), pick_num(0){};
};
int main()
{
    int n, m;
    cin >> n;
    vector<Tree> trees(n);
    int T = 0;
    int D = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> m;              //操作数
        cin >> trees[i].total; //苹果总数
        trees[i].cur_num = trees[i].total;
        for (int j = 1; j < m; j++)
        {
            int a;
            cin >> a;     
            if (a > 0) //统计操作，此时a为剩下的数量
            {
                trees[i].cur_num = a;
                if (!trees[i].isDrop&&(trees[i].total - trees[i].pick_num > a)) //原本的数量-现在的数量>采摘的数量 ,苹果有掉落的
                {
                    trees[i].isDrop = true;
                    D += 1;
                }
            }
            else //a<=0，表示掉下来的数量
            {
                trees[i].cur_num += a;  //剩下的数量
                trees[i].pick_num -= a; //采摘的数量
            }
        }
        T += trees[i].cur_num;
    }

    int E = 0;
    if (n > 2)
        for (int i = 0; i < n; i++)
        {
            if (trees[(i - 1 + n) % n].isDrop && trees[i].isDrop && trees[(i + 1) % n].isDrop)
                E++;
        }
    cout << T << " " << D << " " << E;
}