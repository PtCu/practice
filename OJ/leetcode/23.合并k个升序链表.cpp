/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#include <bits/stdc++.h>
using namespace std;

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
    struct cmp
    {
        //小根堆，用greater
        bool operator()(ListNode *a, ListNode *b)
        {
            return a->val > b->val;
        }
    };
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        priority_queue<ListNode *, vector<ListNode *>, cmp> pq;
        for (auto &p : lists)
        {
            //去除空链
            if (p)
                pq.push(p);
        }
        ListNode *ans = new ListNode();
        ans->next = nullptr;
        ListNode *rear = ans;
        while (!pq.empty())
        {
            auto p = pq.top();
            pq.pop();
            if (!p)
                continue;
            rear->next = p;
            rear = p;
            if (p->next)
                pq.push(p->next);
        }

        return ans->next;
    }
};
// @lc code=end
