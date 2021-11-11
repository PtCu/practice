/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = nullptr, *tail = nullptr;
        int carry = 0;
        int n1 = 0, n2 = 0;
        while (l1 || l2)
        {

            if (l1)
            {
                n1 = l1->val;
                l1 = l1->next;
            }
            else
                n1 = 0;
            if (l2)
            {
                n2 = l2->val;
                l2 = l2->next;
            }
            else
                n2 = 0;
            int sum = n1 + n2 + carry;
            if (sum >= 10)
            {
                sum -= 10;
                carry = 1;
            }
            else
                carry = 0;
            auto p = new ListNode(sum);
            if (!head)
                head = tail = p;
            else
            {
                tail->next = p;
                tail = p;
            }
        }
        if (carry)
        {
            auto p = new ListNode(1);
            tail->next = p;
            tail = p;
        }
        return head;
    }
};
// @lc code=end
