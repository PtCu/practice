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
void update(int i, int x)
{
    while (i <= maxn)
    {
        c[i] += x;
        i += lowbit(i);
    }
}

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