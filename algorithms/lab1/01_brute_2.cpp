#include <bits/stdc++.h>
using namespace std;
struct Stuff
{
    int value;
    int weight;
    Stuff(){};
    Stuff(const int &v, const int &w) : value(v), weight(w) {}
};
int C, M; //背包的容量C和物品数M
vector<Stuff> stuffs;
int n;
int main()
{
    cout << "请输入背包容量和物品数目" << endl;
    /*
    10 4
    7 42
    3 12
    4 40
    5 25
    */
    cin >> C >> M;
    int v, w;
    for (int i = 0; i < M; i++)
    {
        cin >> w >> v;
        stuffs.push_back(Stuff(v, w));
    }
    n = stuffs.size();
    int maxV = std::numeric_limits<int>::min();

    for (size_t i = 1; i < (1 << n); ++i)
    {
        int curV = 0, curW = 0;
        for (size_t j = 0; j < n; ++j)
        {
            if ((i >> j) & 1)
            {
                if (curW + stuffs[j].weight <= C)
                {
                    curV += stuffs[j].value;
                    curW += stuffs[j].weight;
                }
            }
        }
        maxV = max(maxV, curV);
    }
    cout << maxV;
}