#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e2;
int n;
int mat[MAX][MAX] = {
    {-1, 3, 6, 7},
    {12, -1, 2, 8},
    {8, 6, -1, 2},
    {3, 7, 6, -1}};
int pers[MAX][MAX];
int p_nums = 0;

//stl next_permutation
void permutation(int nums[], int start, int end)
{
    if (start == end)
    {
        for (int i = 0; i <= end; i++)
        {
            pers[p_nums][i] = nums[i];
        }
        p_nums++;
    }
    else
    {
        for (int i = start; i <= end; i++)
        {
            //依次将i,i+1,...end各个数放在最开头
            swap(nums[i], nums[start]);
            //递归排列后面的数[start+1,end]
            permutation(nums, start + 1, end);
            //递归后还原
            swap(nums[i], nums[start]);
        }
    }
}
int brute()
{

    int ans = INT32_MAX;
    for (int i = 0; i < p_nums; i++)
    {
        int sum = 0;
        for (int j = 0; j < n - 1; j++)
        {
            int cur = pers[i][j];
            sum += mat[pers[i][j]][pers[i][j + 1]];
        }

        ans = min(sum, ans);
    }
    return ans;
}
int main()
{
    n = 4;
    int nums[MAX];
    for (int i = 0; i < n; i++)
    {
        nums[i] = i;
    }
    permutation(nums, 0, n - 1);

    cout << brute();
}
