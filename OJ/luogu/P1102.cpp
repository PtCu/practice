#include <iostream>
#include <map>
using namespace std;
typedef long long LL;
LL a[200001];
map<LL, LL> m; //建立一个数字到出现次数的映射 map<num,times>
//A-B=C --> A-C=B
int main()
{
    int n;
    LL c;
    LL ans = 0;
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        m[a[i]]++;  //B 源数据 记录a[i]有几个
        a[i] -= c;  //A-C  
    }
    for (int i = 1; i <= n; i++)
        ans += m[a[i]]; //给定一个A-C，查有多少个B
    cout << ans << endl;
    return 0;
}