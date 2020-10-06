#include <bits/stdc++.h>
using namespace std;
int binarySearch(int goal, vector<int> &source)
{
    int left = 0;
    int right = source.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (source[mid] > goal)
        {
            right = mid - 1;
        }
        else if (source[mid] < goal)
        {
            left = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}
int main(int argc, char const *argv[])
{
    int n, c;
    cin >> n >> c;
    vector<int> source;
    
    //刚开始vector为空时不能用下标赋值，必须push_back
    for (int i = 0; i < n; i++)
    {
        int j;
        cin >> j;
        source.push_back(j);
    }
    sort(source.begin(),source.end());
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        int index = binarySearch(c+source[i], source);
        if (index != -1)
        {
            num++;
            int lindex = index;
            int rindex = index;
            while (lindex > 0 && source[lindex] == source[lindex - 1])
            {
                lindex--;
                num++;
            }
            while (rindex < source.size() - 1 && source[rindex] == source[rindex + 1])
            {
                rindex++;
                num++;
            }
        }
    }
    cout << num << " ";
    return 0;
}