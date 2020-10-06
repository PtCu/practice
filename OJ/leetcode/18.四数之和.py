#
# @lc app=leetcode.cn id=18 lang=python3
#
# [18] 四数之和
#
# https://leetcode-cn.com/problems/4sum/description/
#
# algorithms
# Medium (37.30%)
# Likes:    405
# Dislikes: 0
# Total Accepted:    62.3K
# Total Submissions: 167K
# Testcase Example:  '[1,0,-1,0,-2,2]\n0'
#
# 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c
# + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
#
# 注意：
#
# 答案中不可以包含重复的四元组。
#
# 示例：
#
# 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
#
# 满足要求的四元组集合为：
# [
# ⁠ [-1,  0, 0, 1],
# ⁠ [-2, -1, 1, 2],
# ⁠ [-2,  0, 0, 2]
# ]
#
#
#

# @lc code=start
from typing import List


class Solution:
    # def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
    #     # if not nums:
    #     #     return []
    #     length=len(nums)
    #     if length<4:
    #         return []
    #     nums.sort()
    #     ans=[]
    #     for a in range(length-3):
    #         if a>0 and nums[a]==nums[a-1]:
    #             continue
    #         for b in range(a+1,length-2):
    #             if nums[b]==nums[b-1] and b-1!=a:
    #                 continue
    #             L=b+1;R=length-1
    #             while L<R:
    #                 sum=nums[a]+nums[b]+nums[L]+nums[R]
    #                 if sum>target:
    #                     while L<R and nums[R]==nums[R-1]:
    #                         R-=1
    #                     R-=1
    #                 elif sum<target:
    #                     while L<R and nums[L]==nums[L+1]:
    #                         L+=1
    #                     L+=1
    #                 else:
    #                     ans.append([nums[a],nums[b],nums[L],nums[R]])
    #                     while L<R and nums[L]==nums[L+1]:
    #                         L+=1
    #                     while L<R and nums[R]==nums[R-1]:
    #                         R-=1
    #                     L+=1
    #                     R-=1

    #     return ans

    # general solution:
    def fourSum(self, nums, target):
        nums.sort()
        results = []
        self.findNsum(nums, target, 4, [], results)
        return results

    def findNsum(self, nums, target, N, result, results):
        if len(nums) < N or N < 2:
            return

        # solve 2-sum 递归终止
        if N == 2:
            l, r = 0, len(nums)-1
            while l < r:
                if nums[l] + nums[r] == target:
                    results.append(result + [nums[l], nums[r]])
                    l += 1
                    r -= 1
                    while l < r and nums[l] == nums[l - 1]:
                        l += 1
                    while l < r and nums[r] == nums[r + 1]:
                        r -= 1
                elif nums[l] + nums[r] < target:
                    l += 1
                else:
                    r -= 1
        else:
            for i in range(0, len(nums)-N+1):   # careful about range
                # 如果最后一个元素（最大的）的N倍仍小于target or 当前元素（当前最小的）的N倍仍大于target 就直接进行下一轮
                # take advantages of sorted list
                if target < nums[i]*N or target > nums[-1]*N:
                    break
                # recursively reduce N
                if i == 0 or i > 0 and nums[i-1] != nums[i]:
                    # 下一轮递归以target-nums[i]为Target
                    self.findNsum(nums[i+1:], target-nums[i],
                                  N-1, result+[nums[i]], results)


if __name__ == "__main__":
    Solution().fourSum([0, 0, 0, 0], 1)

# @lc code=end
