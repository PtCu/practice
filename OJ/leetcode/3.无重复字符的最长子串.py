#
# @lc app=leetcode.cn id=3 lang=python3
#
# [3] 无重复字符的最长子串
#
# https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
#
# algorithms
# Medium (33.21%)
# Likes:    3258
# Dislikes: 0
# Total Accepted:    374.9K
# Total Submissions: 1.1M
# Testcase Example:  '"abcabcbb"'
#
# 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
# 
# 示例 1:
# 
# 输入: "abcabcbb"
# 输出: 3 
# 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
# 
# 
# 示例 2:
# 
# 输入: "bbbbb"
# 输出: 1
# 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
# 
# 
# 示例 3:
# 
# 输入: "pwwkew"
# 输出: 3
# 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
# 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
# 
# 
#

# @lc code=start
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if not s: return 0
        left = 0
        lookup = set()  #利用集合
        n = len(s)
        max_len = 0
        cur_len = 0
        for i in range(n):
            cur_len += 1
            while s[i] in lookup:   #有重复的就从左边开始删除直到将重复元素删除
                lookup.remove(s[left])
                left += 1
                cur_len -= 1
            if cur_len > max_len:
                max_len = cur_len
            lookup.add(s[i])
        return max_len

        #Google:
        # start = maxLength = 0
        # usedChar = {}
        
        # for i in range(len(s)):
        #     if s[i] in usedChar and start <= usedChar[s[i]]:
        #         start = usedChar[s[i]] + 1
        #     else:
        #         maxLength = max(maxLength, i - start + 1)

        #     usedChar[s[i]] = i

        # return maxLength


        #状态转移方程 ：li为当前字符串最大长度
        #lengthOfLongestSubString(Si+1)=max(Li,len(C结尾的无重复子串))
        #if s == '':
        #     return 0
        # if len(s) == 1:
        #     return 1

        # def find_left(s, i):
        #     tmp_str = s[i]
        #     j = i - 1
        #     while j >= 0 and s[j] not in tmp_str:
        #         tmp_str += s[j]
        #         j -= 1
        #     return len(tmp_str)
        # length = 0
        # for i in range(0, len(s)):
        #     length = max(length, find_left(s, i))
        # return length



if __name__ == "__main__":
    Solution().lengthOfLongestSubstring('abcabcbb')

# @lc code=end

