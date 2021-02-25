#include <bits/stdc++.h>
using namespace std;
const int maxn = 310;
//grade to id. [1, maxn] are local, 0 is global
map<int, set<string>, greater<int>> grade2id[maxn];
//id to group.
unordered_map<string, int> id2Group;

unordered_map<string, int> id2localRank;
int main()
{
    int n, k;
    cin >> n;
    string id;
    int mark;
    for (int i = 1; i <= n; ++i)
    {
        cin >> k;
        for (int j = 1; j <= k; ++j)
        {
            cin >> id >> mark;
            grade2id[i][mark].insert(id);
            grade2id[0][mark].insert(id);
            id2Group[id] = i;
        }
    }
    //计算局部排名。
    //对于每个组
    for (int i = 1; i <= n; ++i)
    {
        long long rank = 1;
        //对每个grade
        for (auto iter = grade2id[i].begin(); iter != grade2id[i].end(); ++iter)
        {
            for (auto it = iter->second.begin(); it != iter->second.end(); ++it)
            {
                id2localRank[*it] = rank;
            }
            rank += iter->second.size();
        }
    }
    cout << id2Group.size() << endl;
    long long rank = 1;
    for (auto iter = grade2id[0].begin(); iter != grade2id[0].end(); ++iter)
    {
        for (auto it = iter->second.begin(); it != iter->second.end(); ++it)
        {
            int group = id2Group[*it];
            int localrank = id2localRank[*it];
            cout << *it << " " << rank << " " << group << " " << localrank << endl;
        }
        rank += iter->second.size();
    }
}