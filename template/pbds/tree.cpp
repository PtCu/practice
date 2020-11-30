//P3368
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> bbt;
//第一个参数是数据类型
//第二个要填null_type，低版本编译器填null_mapped_type
//第三个填比较函数 std::greater<> or std::less<> or cmp
//第四个填树的类型，有rb_tree_tag红黑树和splay_tree_tag
//第五个是为了支持查询第k大和排名的一个参数
//tree_order_statistics_node_update
int n, opt;
ll k, ans;
int main()
{
    cin >> n;
    for (size_t i = 1; i <= n; ++i)
    {
        cin >> opt >> k;
        if (opt == 1)
            //插入
            bbt.insert((k << 20) + i); //防止重复，后面加上i以区分
        if (opt == 2)
            //删除
            bbt.erase(bbt.lower_bound(k << 20));
        if (opt == 3)
            //查询x数的排名
            cout << bbt.order_of_key((k << 20)) + 1 << endl;
        if (opt == 4)
        {
            //查询排名为x的数
            ans = *bbt.find_by_order(k - 1);
            cout << (ans >> 20) << endl;
        }
        if (opt == 5)
        {
            //求x的前驱
            ans = *--bbt.lower_bound(k << 20);
            cout << (ans >> 20) << endl;
        }
        if (opt == 6)
        {
            //求x的后继
            ans = *bbt.upper_bound((k << 20) + n);
            cout << (ans >> 20) << endl;
        }
    }
    return 0;
}