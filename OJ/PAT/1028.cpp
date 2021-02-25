#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
struct Stu
{
    string ID, name;
    int grade;
} students[maxn];
bool cmp1(const Stu &s1, const Stu &s2)
{
    return s1.ID < s2.ID;
}
bool cmp2(const Stu &s1, const Stu &s2)
{
    return s1.name <= s2.name;
}
bool cmp3(const Stu &s1, const Stu &s2)
{
    return s1.grade <= s2.grade;
}
int main()
{
    int n, c;
    cin >> n >> c;
    for (int i = 1; i <= n; ++i)
    {
        cin >> students[i].ID >> students[i].name >> students[i].grade;
    }
    if (c == 1)
    {
        sort(students + 1, students + 1 + n, cmp1);
    }
    else if (c == 2)
    {
        sort(students + 1, students + 1 + n, cmp2);
    }
    else
    {
        sort(students + 1, students + 1 + n, cmp3);
    }
        for (int i = 1; i <= n; ++i)
    {
        cout<< students[i].ID <<" " << students[i].name <<" "<< students[i].grade<<endl;
    }
}
