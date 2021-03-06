#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
struct Student
{
    int ID, tScore = 0, solved = 0;
    int scores[6] = {-1, -1, -1, -1, -1, -1};
    bool hasPass = false;
} s[maxn];

bool cmp(Student a, Student b)
{
    if (a.hasPass != b.hasPass)
        return a.hasPass;
    if (a.tScore != b.tScore)
        return a.tScore > b.tScore;
    if (a.solved != b.solved)
        return a.solved > b.solved;
    return a.ID < b.ID;
}
int p[6];
int main()
{
    int n, k, m;
    cin >> n >> k >> m;
    for (int i = 1; i <= k; ++i)
    {
        cin >> p[i];
    }
    int id, sub, score;
    for (int i = 0; i < m; ++i)
    {
        cin >> id >> sub >> score;
        s[id].ID = id; //用学号作为下标
        if (score != -1)
            s[id].hasPass = true; //提交且编译成功过
        if (p[sub] != s[id].scores[sub] && p[sub] == score)
        {
            s[id].solved++;
        }
        if (s[id].scores[sub] == -1)
        {
            s[id].scores[sub] = 0;
        }
        s[id].scores[sub] = max(score, s[id].scores[sub]);
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= k; ++j)
        {
            if (s[i].scores[j] >= 0)
                s[i].tScore += s[i].scores[j];
        }
    }
    sort(s + 1, s + 1 + n, cmp);
    int cur_tol = -1;
    int rank;
    for (int i = 1; i <= n && s[i].hasPass; ++i)
    {
        if (s[i].tScore != cur_tol)
            rank = i;
        cur_tol = s[i].tScore;
        printf("%d %05d %d", rank, s[i].ID, s[i].tScore);
        for (int j = 1; j <= k; ++j)
        {
            if (s[i].scores[j] != -1) //不等于-1意味着提交过，无论编译成功与否
                printf(" %d", s[i].scores[j]);
            else
                printf(" -"); //没提交过
        }
        printf("\n");
    }
    return 0;
}