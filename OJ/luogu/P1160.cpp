#include <bits/stdc++.h>
using namespace std;
using Iter = list<int>::iterator;
const int maxn = 1e5 + 10;

//pos[i]表示编号为i的同学插入到哪个迭代器中
Iter pos[maxn];
//i同学是否被移除过
bool erased[maxn];
// prev  next
//
//insert(it, val)成员函数用于在链表中插入元素。
//it为该链表的一个迭代器，val为待插入的值，
//插入后val位于it所指位置的前一位。
//返回值为一个迭代器，表示val插入到了哪个位置。

//remove(it)成员函数用于删除某个迭代器所指的节点。
//注意在删除之后it就失效了，除非给it重新赋值，否则对它的任何操作都会导致错误！
int main()
{
    int n, k, p;
    cin >> n;
    list<int> L;
    L.push_back(1);
    pos[1] = L.begin();

    for (int i = 2; i <= n; ++i)
    {
        cin >> k >> p;
        //插入k的右边
        if (p)
        {
            pos[i] = L.insert(next(pos[k]), i);
           
        }
        //插入k的左边
        else
        {
            pos[i] = L.insert(pos[k], i);
            
        }
    }

    int m, x;
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> x;
        if (!erased[x])
        {
            L.erase(pos[x]);
            erased[x] = true;
        }
    }

    for (auto it = L.begin(); it != L.end(); ++it)
    {
        cout << *it << " ";
    }
}