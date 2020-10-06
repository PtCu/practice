#
# @lc app=leetcode.cn id=4 lang=python3
#
# [4] 寻找两个有序数组的中位数
#
# https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
#
# algorithms
# Hard (37.05%)
# Likes:    2251
# Dislikes: 0
# Total Accepted:    153.5K
# Total Submissions: 414.5K
# Testcase Example:  '[1,3]\n[2]'
#
# 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
# 
# 请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
# 
# 你可以假设 nums1 和 nums2 不会同时为空。
# 
# 示例 1:
# 
# nums1 = [1, 3]
# nums2 = [2]
# 
# 则中位数是 2.0
# 
# 
# 示例 2:
# 
# nums1 = [1, 2]
# nums2 = [3, 4]
# 
# 则中位数是 (2 + 3)/2 = 2.5
# 
# 
#

# @lc code=startA
class Solution:
    def findMedianSortedArrays(self, A: List[int], B: List[int]) -> float:

    # 第K小的数
    #     l = len(A) + len(B)
    #     if l % 2 == 1:
    #         return self.kth(A, B, l // 2)
    #     else:
    #         return (self.kth(A, B, l // 2) + self.kth(A, B, l // 2 - 1)) / 2.   
    
    # def kth(self, a, b, k):
    #     if not a:
    #         return b[k]
    #     if not b:
    #         return a[k]
    #     ia, ib = len(a) // 2 , len(b) // 2
    #     ma, mb = a[ia], b[ib]
    
    # # when k is bigger than the sum of a and b's median indices 
    #     if ia + ib < k:
    #     # if a's median is bigger than b's, b's first half doesn't include k
    #         if ma > mb:
    #             return self.kth(a, b[ib + 1:], k - ib - 1)
    #         else:
    #             return self.kth(a[ia + 1:], b, k - ia - 1)
    # # when k is smaller than the sum of a and b's indices
    #     else:
    #     # if a's median is bigger than b's, a's second half doesn't include k
    #         if ma > mb:
    #             return self.kth(a[:ia], b, k)
    #         else:
    #             return self.kth(a, b[:ib], k)

        m=len(A)
        n=len(B)
        if m>n:
            return self.findMedianSortedArrays(B,A)
        iMin=0;iMax=m #iMin,iMax为中位数范围的上下界(夹逼)
        #寻找满足 1) i+j=m-i+n-j   即 j=(m+n)/2-i
        #        2)  max(A[i-1],B[j-1])<=min(A[i],B[j]) 
        #             即A[i-1]<=A[i],B[j-1]<=B[j] (已知)
        #               A[i-1]<=B[j],B[j-1]<=A[i]
        while iMin<=iMax:
            i=(iMax+iMin)/2
            j=(m+n+1)/2-i
            if j!=0 and i!=m and B[j-1]>A[i]:  #当B[j-1]>A[i]时，增大i，减小j,即增加下界iMin
                iMin=i+1
            elif i!=0 and j!=n and A[i-1]>B[j]:#当A[i-1]>B[j]时，减小i,增大j,即减小上界iMax
                iMax=i-1
            else:       #达到要求，需对边界条件进行单独考虑
                maxLeft=0
                if i==0:
                    maxLeft=B[j-1]
                elif j==0:
                    maxLeft=A[i-1]
                else:
                    maxLeft=max(A[i-1],B[j-1])
                
                if m+n%2==1:    #奇数的话不需要考虑右半部分
                    return maxLeft
                minRight=0
                if i==m:
                    minRight=B[j]
                elif j==n:
                    minRight=A[i]
                else:
                    minRight=max(B[j],A[i])
                
                return (maxLeft+minRight)/2
        
        return 0

    def findMedianSortedArrays2(self, A: List[int], B: List[int]) -> float:
        #第K大的数
        l = len(A) + len(B)
        if l % 2 == 1:  #如果总长度是奇数，则中位数为第l/2个大的数
            return self.kth(A, B, l // 2)
        else:           #如果是偶数，则中位数是第l/2个大和第l/2-1个大数的平均数
            return (self.kth(A, B, l // 2) + self.kth(A, B, l // 2 - 1)) / 2.   
    
    def kth(self, a, b, k):
        if not a:
            return b[k]
        if not b:
            return a[k]
        ia, ib = len(a) // 2 , len(b) // 2  #a,b数组的下标
        ma, mb = a[ia], b[ib]               #a,b数组的中位数

        # when k is bigger than the sum of a and b's median indices 
        if ia + ib < k:
        #k不在a或b前边的一部分，可排除
        # if a's median is bigger than b's, b's first half doesn't include k
            if ma > mb:
                return self.kth(a, b[ib + 1:], k - ib - 1)
            else:
                return self.kth(a[ia + 1:], b, k - ia - 1)
        # when k is smaller than the sum of a and b's indices
        else:
        #k不再a或b后边的一部分，可排除
        # if a's median is bigger than b's, a's second half doesn't include k
            if ma > mb:
                return self.kth(a[:ia], b, k)
            else:
                return self.kth(a, b[:ib], k)
    


# @lc code=end

