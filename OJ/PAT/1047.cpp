#include <bits/stdc++.h>
using namespace std;
char names[40000][5];
map<int, set<int>> course2stu;
vector<int> stu[2501]; //选取某课的所有学生编号
bool cmp(int a, int b)
{
    return strcmp(names[a], names[b]) < 0;
}
int main()
{
    int n, k;
    cin >> n >> k;
    int num, x;
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", names[i]);
        scanf("%d", &num);
        for (int j = 0; j < num; ++j)
        {
            scanf("%d", &x);
            stu[x].push_back(i);
        }
    }
    for (int i = 1; i <= k; ++i)
    {
        printf("%d %d\n", i, stu[i].size());
        sort(stu[i].begin(), stu[i].end(), cmp);
        for (int j = 0; j < stu[i].size(); ++j)
        {
            printf("%s\n", names[stu[i][j]]);
        }
    }
    return 0;
}