#include <bits/stdc++.h>
using namespace std;
//统计的是1的个数，而不是含1的数字的个数
// 从第一位（个位）到最高位，设now为当前位的数字，left为now左边的所有数字构成的数字，
// right是now右边的所有数字构成的数字。只需要一次次累加对于当前位now来说可能出现1的个数，
// 然后把它们累加即可。a表示当前的个位为1，十位为10，百位为100类推。
// 对于now，有三种情况：
// 1.now == 0 : 那么 ans += left * a; //因为now==0说明now位只有在left从0~left-1的时候会产生1，
// 所以会产生left次，但是又因为右边会重复从0~999…出现a次
// 2.now == 1 : ans += left * a + right + 1;//now = 1的时候就要比上一步多加一个当now为1的时候右边出现0~right个数导致的now为1的次数
// 3.now >= 2 : ans += (left + 1) * a;//now大于等于2就左边0~left的时候会在now位置产生1，所以会产生left次，但是又因为右边会重复从0~999…出现a次


int main()
{
    int n, mul = 1, ans = 0;
    cin >> n;
    //统计每一位出现1的次数。由于统计的是1的个数，所以各位相互独立
    while (n / mul != 0)
    {
        int cur = n / mul % 10;
        int left = n / mul / 10;
        int right = n % mul;
        if (cur == 0)
            ans += (left * mul);
        else if(cur==1)
            ans += (left * mul + (right + 1));
        else
            ans += ((left + 1) * mul);
        if(mul==1000000000)
            break;
        mul *= 10;
    }
    cout << ans;
}