#
# @lc app=leetcode.cn id=16 lang=python3
#
# [16] 最接近的三数之和
#
# https://leetcode-cn.com/problems/3sum-closest/description/
#
# algorithms
# Medium (43.23%)
# Likes:    376
# Dislikes: 0
# Total Accepted:    81.4K
# Total Submissions: 188K
# Testcase Example:  '[-1,2,1,-4]\n1'
#
# 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target
# 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
# 
# 例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
# 
# 与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
# 
# 
#

# @lc code=start
from typing import List
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        length=len(nums)
        if length<3:
            return None
        nums.sort()
        dif=float('inf')
        for i in range(length-2):
            if nums[i]==nums[i-1] and i>0:
                continue
            L=i+1
            R=length-1
            while L<R:
                sum=nums[L]+nums[R]+nums[i]
                if abs(sum-target)<abs(dif):
                    ans=sum
                    dif=abs(sum-target)
                if sum<target:
                    L+=1
                elif sum>target:
                    R-=1
                else:
                    return sum
               
                
        return ans

if __name__ == "__main__":
    print(Solution().threeSumClosest([1,1,1,0],-100))
# @lc code=end

