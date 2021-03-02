#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
struct Node
{
    char name[9];
    int age;
    int worth;
} node[maxn], waitingList[maxn];
bool cmp(const Node &a, const Node &b)
{
    if (a.worth != b.worth)
        return a.worth > b.worth;
    else if (a.age != b.age)
        return a.age < b.age;
    else
        return strcmp(a.name, b.name) < 0;
}
//下标表示年龄，元素为改年龄的人数
int nums[201];
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        scanf("%s %d %d", &node[i].name, &node[i].age, &node[i].worth);
    }
    sort(node, node + n, cmp);
    //预处理，只保留可能输出的
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        nums[node[i].age]++;
        if (nums[node[i].age] <= 100)
            waitingList[cnt++] = node[i];
    }
    //输出
    int print = 0;
    int m, ageMin, ageMax;
    for (int i = 1; i <= k; ++i)
    {
        cin >> m >> ageMin >> ageMax;
        cout << "Case #" << i <<":"<< endl;
        print = 0;
        for (int j = 0; j < cnt; ++j)
        {
            if (waitingList[j].age >= ageMin && waitingList[j].age <= ageMax && print < m)
            {
                printf("%s %d %d\n", waitingList[j].name, waitingList[j].age, waitingList[j].worth);
                print++;
            }
        }
        if (print == 0)
            cout << "None" << endl;
    }
}