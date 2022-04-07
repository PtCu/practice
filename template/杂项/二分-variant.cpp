// P1419
#include <bits/stdc++.h>
// https://www.nowcoder.com/practice/70610bf967994b22bb1c26f9ae901fa2?tpId=13&tqId=23274&ru=%2Fpractice%2F762836f4d43d43ca9deb273b3de8e1f4&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&sourceUrl=
using namespace std;
class Solution
{
public:
    int GetNumberOfK(vector<int> data, int k)
    {
        int l = 0, r = data.size() - 1;
        //寻找上界
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (data[mid] > k)
            {
                r = mid - 1;
            }
            else
            {
                //将data[mid]==k的情况融入到这个分支中，以让下界不断上移
                l = mid + 1;
            }
        }
        int up_bound = l;
        l = 0, r = data.size() - 1;
        //寻找下界
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (data[mid] >= k)
            {
                //将data[mid]==k的情况融入到这个分支中，以让上界不断下移
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        int low_bound = l;
        return up_bound - low_bound;
    }
};