/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        auto p1 = headA;
        auto p2 = headB;
        int n1 = 0, n2 = 0;
        while (p1)
        {
            p1 = p1->next;
            ++n1;
        }
        while (p2)
        {
            p2 = p2->next;
            ++n2;
        }
        p1 = headA;
        p2 = headB;
        while (n1 > n2)
        {
            --n1;
            p1 = p1->next;
        }
        while (n2 > n1)
        {
            --n2;
            p2 = p2->next;
        }
        while (p1 != p2)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};
// @lc code=end
