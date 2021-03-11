//PAT 1057
// 举例来说，树状数组所能解决的典型问题就是存在一个长度为n的数组，我们如何高效进行如下操作：

// update(idx, delta)：将num加到位置idx的数字上。
// prefixSum(idx)：求从数组第一个位置到第idx（含idx）个位置所有数字的和。
// rangeSum(from_idx, to_idx)：求从数组第from_idx个位置到第to_idx个位置的所有数字的和

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
stack<int> s;
int c[maxn];
int n;
inline int lowbit(int x)
{
    return (-x) & x;
}
//更新位置i的数，同时更新后面的数，因为树状数组本质是分段前缀和
void update(int i, int x)
{
    while (i <= maxn)
    {
        c[i] += x;
        i += lowbit(i);
    }
}
//求[1, i]区间内的数之和
int sum(int i)
{
    int sum = 0;
    while (i > 0)
    {
        sum += c[i];
        i -= lowbit(i);
    }
    return sum;
}
int Pop()
{
    int x = s.top();
    update(x, -1);
    s.pop();
    return x;
}
void Push(int x)
{
    s.push(x);
    update(x, 1);
}
int PeekMedian()
{
    int l = 1, r = maxn, mid, k = (s.size() + 1) / 2;
    while (l < r)
    {
        mid = (l + r) >> 1;
        if (sum(mid) >= k)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}
int main()
{
    cin >> n;
    char str[12];
    while (n--)
    {
        scanf("%s", &str);
        if (str[1] == 'o')
        {
            if (!s.empty())
            {
                int x = Pop();
                printf("%d\n", x);
            }
            else
            {
                printf("Invalid\n");
            }
        }
        else if (str[1] == 'u')
        {
            int x;
            scanf("%d", &x);
            Push(x);
        }
        else if (str[1] == 'e')
        {
            if (!s.empty())
            {
                int x = PeekMedian();
                printf("%d\n", x);
            }
            else
            {
                printf("Invalid\n");
            }
        }
    }
}