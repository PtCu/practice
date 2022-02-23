#include <bits/stdc++.h>
using namespace std;
// https : //www.nowcoder.com/practice/a861533d45854474ac791d90e447bafd?tpId=13&tags=&title=&difficulty=0&judgeStatus=0&rp=0

// 中序和后序确定一颗二叉树。
// 而二叉搜索树的中序序列是唯一的，所以不同后序序列对应了不同的二叉搜索树。
// 对于一颗二叉搜索树来说，若将其中序作为入栈序列，则后序一定是一种出栈序列。
// 所以只需要看后序序列是否是合法的出栈序列，就可以判断该序列是否可以构成一个合法的二叉搜索树了。
//  同理，前序和中序确定一颗二叉树。 前序作为入栈序列，则中序一定是一种出栈序列。

class Solution
{
public:
    bool VerifySquenceOfBST(vector<int> sequence)
    {
        if (sequence.empty())
            return false;
        vector<int> inorder(sequence.size());
        copy(sequence.begin(), sequence.end(), inorder.begin());
        sort(inorder.begin(), inorder.end());
        return isValid(inorder, sequence);
    }

    bool isValid(const vector<int> &A, const vector<int> &B)
    {
        stack<int> S;
        int i, j;
        while (i < A.size())
        {
            while (S.empty() || S.top() != B[j])
            {
                S.push(A[i++]);
            }
            S.pop();
            ++j;
        }
        while (!S.empty())
        {
            if (S.top() != B[j++])
                return false;
            S.pop();
        }
        return true;
    }
};