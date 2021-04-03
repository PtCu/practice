// 输入一个长度为n（n≤100）的环状DNA串（只包含A、C、G、T这4种字符）的一种表示法，
// 你的任务是输出该环状串的最小表示。
// 例如，CTCC的最小表示是CCCT，CGAGTCAGCT的最小表示为AGCTCGAGTC。
// 【分析】本题出现了一个新概念：字典序。
// 所谓字典序，就是字符串在字典中的顺序。
// 一般地，对于两个字符串，从第一个字符开始比较，
// 当某一个位置的字符不同时，该位置字符较小的串，
// 字典序较小（例如，abc比bcd小）；如果其中一个字符串已经没有更多字符，
// 但另一个字符串还没结束，则较短的字符串的字典序较小（例如，hi比history小）。
// 字典序的概念可以推广到任意序列，例如，序列1, 2, 4, 7比1, 2, 5小。
#include <bits/stdc++.h>
using namespace std;
//环状s的表示法p是否比q的字典序小
int less_(string s, int p, int q)
{
    int length = s.length();
    for (int i = 0; i < length; i++)
    {
        if (s[(p + i) % length] != s[(q + i) % length])
            return s[(p + i) % length] < s[(q + i) % length];
    }
    return 0; //相等
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        int ans = 0;
        int length = s.length();
        for (int i = 0; i < length; i++)
        {
            if (less_(s, ans, i) > 0)
                ans = i;
        }
        cout << s;
    }
    return 0;
}