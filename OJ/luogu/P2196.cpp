
#include <bits/stdc++.h>
using namespace std;
int n, ans, pos;
const int N = 30;
int mine[N], f[N], _map[N][N], pre[N];
void print(int x) //递归输出。
{
    if (pre[x] == 0)
    {
        cout << x;
        return;
    }              //如果没了，就输出，回溯。
    print(pre[x]); //继续打印前驱。
    cout << ' ' << x;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> mine[i];
    for (int i = 1; i <= n - 1; i++)
        for (int j = i + 1; j <= n; j++) //读入01串，不要读错位。
            cin >> _map[i][j];
    for (int i = 1; i <= n; i++) //出点
    {
        for (int j = 1; j <= n; j++)
        {
            if (_map[j][i])
            {
                if (f[j] > f[i]) //入点大于出点，则加上
                {
                    pre[i] = j;
                    f[i] = f[j];
                }

                // f[i] = max(f[i], f[j]); //递推式的实现， 出点i和入点j的比较
                // if (f[i] == f[j])
                //     pre[i] = j; //记下前驱。
            }
        }
        f[i] += mine[i];      //然后别忘了加上地雷数
        ans = max(ans, f[i]); //答案取大值
        if (ans == f[i])
            pos = i; //记下最后的点。
    }
    print(pos);
    cout << endl
         << ans << endl; //不要输出了f[n]，这不是答案。
    return 0;
}