#include <bits/stdc++.h>
using namespace std;

bool has7(int n)
{ //判断是否有7
    if (n % 7 == 0)
        return true;
    else
    {
        while (n)
        {
            int x = n % 10;
            if (x == 7)
                return true;
            n /= 10;
        }
    }

    return false;
}
int main()
{
    int ppl[4]; //每个人当前跳过的数目
    memset(ppl, 0, sizeof(ppl));
    int n;
    cin >> n;
    int cur_num = 0;
    int total = 0;
    while (total != n)
    {
        cur_num++;
        if (has7(cur_num))
        {
            ppl[(cur_num - 1) % 4]++;
        }
        else
            total++;
    }
    for (int i = 0; i < 4; i++)
    {
        cout << ppl[i] << endl;
    }
}