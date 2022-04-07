

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> vis;
    void dfs(vector<vector<int>> &res, vector<int> &nums, vector<int> &state, int start)
    {
        if (start == nums.size())
        {
            res.push_back(state);
            return;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1]))
            {
                continue;
            }
            state.push_back(nums[i]);
            vis[i] = 1;
            // swap(state[i], state[start]);
            dfs(res, nums, state, start + 1);
            // swap(state[i], state[start]);
            vis[i] = 0;
            state.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vis.resize(nums.size());
        vector<vector<int>> ans;
        vector<int> state;
        sort(nums.begin(), nums.end());
        dfs(ans, nums, state, 0);
        return ans;
    }
};

int main()
{
    // vector<int> a = {1, 2, 3, 4};
    // Solution solution;
    // auto b = solution.permute(a);

        // for (auto i : b)
    // {
    //     for (auto j : i)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << "\n";
    // }
    // return 0;
   
}