//在先序遍历中某一元素A的后继元素B，
//如果在后序遍历中A的前驱元素是B，
//那么A只有一个子树，问题即得解
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string pre, pos;
    cin >> pre >> pos;
    int ans = 0;
    for (size_t i = 0; i < pre.size()-1; ++i)
        for (size_t j = 0; j < pos.size(); ++j)
        {
            //先序AB,后序BA的情况
            if (pre[i] == pos[j] && pre[i + 1] == pos[j - 1])
                ans++;
        }
    cout << (1 << ans);
    return 0;
}