#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int pos[maxn]; //pos[i]表示i所在的位置
int main()
{
    int n, x;
    cin >> n;
    //除0外错位的数目
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        pos[x] = i;
        if (pos[x] != x && x != 0)
        {
            ++cnt;
        }
    }
    int num = 0;
    int unsorted = 1;
    while (cnt)
    {
        if (pos[0] == 0)
        {
            for (; unsorted < n; ++unsorted)
            {
                if (pos[unsorted] != unsorted)
                {
                    swap(pos[0], pos[unsorted]);
                    num++;
                    break;
                }
            }
        }
        swap(pos[0], pos[pos[0]]);
        num++;
        cnt--;
    }
    cout << num;
}