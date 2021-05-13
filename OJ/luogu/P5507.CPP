#include <bits/stdc++.h>
using namespace std;
#define For(i, sta, en) for (int i = sta; i <= en; i++)
inline int read()
{
    int sum = 0, fu = 1;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            fu = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        sum = (sum << 1) + (sum << 3) + (ch ^ 48);
        ch = getchar();
    }
    return sum * fu;
}
const int N = 1 << 24;
bool vis[N];
int nxt[14][6], fa[N], choice[N], v[N], flag, m1, m2, mid, ans1[30], ans2[30];
queue<int> q;
int main()
{
    int button, Start = 0;
    For(i, 0, 11)
    {
        button = read();                   //读入第i+1个旋钮状态
        Start |= (button - 1) << (i << 1); //记录初始状态，如状态分别为1，2，3，4就相当于1234
        For(j, 0, 3) nxt[i][j] = read() - 1;
    }
    vis[Start] = vis[0] = 1; //是否访问过
    v[Start] = 1;            //初始状态对应的方向，正向
    v[0] = 2;                //区分方向. 目标状态对应的方向，反向
    q.push(Start);
    q.push(0);
    while (!q.empty() && !flag)
    {
        int state = q.front(), direction = v[state];
        q.pop();
        int si, sNext, nx, nextState;
        For(i, 0, 11)
        {
            if (direction == 1)
            {                                                                         //正向
                si = (state >> (i << 1)) & 3;                                         //1、获取第i+1个旋钮状态（0~3）
                nx = nxt[i][si];                                                      //2、获取牵连旋钮编号
                sNext = (state >> (nx << 1)) & 3;                                     //3、获取牵连旋钮状态，方式同1
                nextState = state ^ (si << (i << 1)) ^ (((si + 1) & 3) << (i << 1));  //4、修改状态为第i+1个旋钮旋转后的状态
                nextState ^= (sNext << (nx << 1)) ^ (((sNext + 1) & 3) << (nx << 1)); //5、修改状态为牵连旋钮旋转后的状态
            }
            else
            { //反向
                si = (state >> (i << 1)) & 3;
                nx = nxt[i][(si + 3) & 3]; //获取第i+1个旋钮逆向旋转后的牵连旋钮编号
                sNext = (state >> (nx << 1)) & 3;
                nextState = state ^ (si << (i << 1)) ^ (((si + 3) & 3) << (i << 1));  //修改状态为第i+1个旋钮逆向旋转后的状态
                nextState ^= (sNext << (nx << 1)) ^ (((sNext + 3) & 3) << (nx << 1)); //修改状态为牵连旋钮逆向旋转后的状态
            }
            //如果这个状态在之前访问过
            if (vis[nextState])
            {
                if (v[nextState] == direction)
                    continue; //同方向的直接跳过，之前到达的时候肯定不劣于现在
                /*
                 * 不同方向说明已经找到答案了
                 *  m1 记录正向与逆向的连接点
                 *  m2 记录逆向与正向的连接点
                 *  mid 记录从state状态转移到nextState状态选择的旋钮编号
                 */
                m1 = direction == 1 ? state : nextState;
                mid = i + 1;
                m2 = direction == 1 ? nextState : state;
                flag = 1;
                break;
            }
            vis[nextState] = 1;
            v[nextState] = direction;  //继承方向
            fa[nextState] = state;     //用于回溯操作
            choice[nextState] = i + 1; //记录本次操作
            q.push(nextState);
        }
    }
    int cnt1 = 0, state = m1, cnt2 = 0;
    //正向回溯
    while (state != Start)
    {
        ans1[++cnt1] = choice[state];
        state = fa[state];
    }
    //逆向回溯
    state = m2;
    while (state != 0)
    {
        ans2[++cnt2] = choice[state];
        state = fa[state];
    }
    //总步数，还要加上中间那一步mid操作
    printf("%d\n", cnt1 + cnt2 + 1);
    for (int i = cnt1; i; i--)
        printf("%d ", ans1[i]);
    printf("%d ", mid);
    For(i, 1, cnt2) printf("%d ", ans2[i]);
    return 0;
}