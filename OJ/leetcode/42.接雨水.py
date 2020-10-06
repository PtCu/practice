#
# @lc app=leetcode.cn id=42 lang=python3
#
# [42] 接雨水
#
# https://leetcode-cn.com/problems/trapping-rain-water/description/
#
# algorithms
# Hard (49.02%)
# Likes:    948
# Dislikes: 0
# Total Accepted:    65.2K
# Total Submissions: 131.6K
# Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
#
# 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
#
#
#
# 上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢
# Marcos 贡献此图。
#
# 示例:
#
# 输入: [0,1,0,2,1,0,1,3,2,1,2,1]
# 输出: 6
#
#

# @lc code=start

from typing import List
class Solution:
    # 暴力
    # def trap(self, height: List[int]) -> int:
    #     total = 0
    #     size = len(height)
    #     for i in range(1, size):
    #         max_l = 0
    #         # 找左边最大值
    #         for j in range(i-1, -1, -1):
    #             max_l = max(max_l, height[j])
    #         max_r = 0
    #         for j in range(i+1, size):
    #             max_r = max(max_r, height[j])
    #         lower = min(max_l, max_r)
    #         if lower > height[i]:
    #             total += lower-height[i]
    #     return total

    # # 动态规划
    # def trap(self, height: List[int]) -> int:
    #     if not height:
    #         return 0
    #     total = 0
    #     size = len(height)
    #     # max_l[i]代表第i列左边最高的墙的高度（不包括自身）
    #     max_l = [0]*size
    #     max_r = [0]*size
    #     max_r[size-1]=height[size-1]
    #     # 与暴力法不同的是求max_l和max_r时不再从头开始遍历，而是将他们记录在数组中
    #     for i in range(1, size):
    #         max_l[i] = max(max_l[i-1], height[i-1])
    #     for i in range(size-2, -1, -1):
    #         max_r[i] = max(max_r[i+1], height[i+1])
    #     for i in range(1, size-1):
    #         lower = min(max_l[i], max_r[i])
    #         if lower>height[i]:
    #             total+=lower-height[i]
    #     return total

    #双指针
    def trap(self, height: List[int]) -> int:
        if not height:
            return 0
        total = 0
        size = len(height)
        left=0;right=size-1
        left_max,right_max=0,0
        while left<right:
            #如果左边高度的小于右边高度，则取决于左边的
            if height[left]<height[right]:
                if height[left]>left_max:
                    left_max=height[left]
                else:
                    total+=left_max-height[left]
                    left+=1
            #否则取决于右边的
            else:
                if height[right]>right_max:
                    right_max=height[right]
                else:
                    total+=right_max-height[right]
                    right-=1
        return total
# @lc code=end
if __name__ == "__main__":
    Solution().trap([0,1,0,2,1,0,1,3,2,1,2,1])
