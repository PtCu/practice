#include <bits/stdc++.h>
using namespace std;
#include <memory.h>
int a[101], f[100010];
//f[i][j]为用前i道菜用了j元钱的办法总数
int main()
{
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
  {
    cin >> a[i];
  }
  f[0] = 1; //f[0]=1的时候就是剩余的钱刚好买完一个菜后用完，是可以用完的情况，所以要+1
            //F[i]就是当前方案数，维度中i是花费
  for (int i = 1; i <= n; ++i)
    for (int j = m; j >= a[i]; --j)
    {
      f[j] = f[j] + f[j - a[i]];
    }
  cout << f[m];
  return 0;
}
