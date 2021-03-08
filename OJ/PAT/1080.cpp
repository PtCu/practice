#include <cstdio>
#include <algorithm>
using namespace std;

struct Student
{
    int id, ge, gi, sum, rank, choices[5];
} st[40000];
struct School
{
    //存储录取名额、已录取人数、上一个录取学生的st[]数组下标
    int quota, hasAd = 0, lastStu = -1;
    //存储已录取学生的st[]数组下标
    int admission[40000];
} sc[100];
bool cmp(Student a, Student b)
{
    if (a.sum != b.sum)
        return a.sum > b.sum;
    return a.ge > b.ge;
}
bool cmpid(int a, int b)
{
    return st[a].id < st[b].id;
}

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++)
        scanf("%d", &sc[i].quota);
    for (int i = 0; i < n; i++)
    {
        st[i].id = i; //初始时id即下标
        scanf("%d %d", &st[i].ge, &st[i].gi);
        st[i].sum = st[i].ge + st[i].gi;
        for (int j = 0; j < k; j++)
            scanf("%d", &st[i].choices[j]);
    }
    sort(st, st + n, cmp);
    //计算各学生的排名
    st[0].rank = 1;
    for (int i = 1; i < n; i++)
    {
        if (st[i].sum != st[i - 1].sum || st[i].ge != st[i - 1].ge)
            st[i].rank = i + 1;
        else
            st[i].rank = st[i - 1].rank;
    }
    for (int i = 0; i < n; i++) //对于每个学生
    {
        for (int j = 0; j < k; j++) //对于每个志愿
        {
            int cur = st[i].choices[j]; //该生当前志愿的学校编号
            int last = sc[cur].lastStu; //该校上一个录取的学生在st[]数组中的下标
            if (sc[cur].hasAd < sc[cur].quota || (last != -1 && st[last].rank == st[i].rank))
            {                                           //如果还有名额，或者只要和上一个被录取学生的排名相同则可录取
                sc[cur].lastStu = i;                    //更新上一个录取的学生在数组中的下标
                sc[cur].admission[sc[cur].hasAd++] = i; //将录取的学生的数组下标储存
                break;                                  //结束对该生的处理
            }
        }
    }
    //输出
    for (int i = 0; i < m; i++)
    {
        sort(sc[i].admission, sc[i].admission + sc[i].hasAd, cmpid); //按学生编号升序输出
        for (int j = 0; j < sc[i].hasAd; j++)
        {
            if (j > 0)
                printf(" ");
            printf("%d", st[sc[i].admission[j]].id);
        }
        printf("\n");
    }
    return 0;
}