#include <bits/stdc++.h>
using namespace std;
int a[4];
void toArray(int num)
{
    for (int i = 0; i < 4; ++i)
    {
        a[i] = num % 10;
        num /= 10;
    }
}
int toNum()
{
    int ans = 0;
    for (int i = 0; i < 4; ++i)
    {
        ans = ans * 10 + a[i];
    }
    return ans;
}
int main()
{
    int num;
    cin >> num;
    do
    {
        toArray(num);
        sort(a, a + 4, greater<int>());
        int max_ = toNum();
        sort(a, a + 4);
        int min_ = toNum();
        num = max_ - min_;
        printf("%04d - %04d = %04d\n", max_, min_, num);
    } while (num != 6174 && num != 0);
}