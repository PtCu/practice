#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
stack<int> sta;
int num[maxn];       //num[i]表示数字i在栈中的数量
int block[1000];     //block[i]表示第i块内的数字在栈中的数量
int sq = sqrt(maxn); //每块最多可以有多少个不同的数字

void Push(int k)
{
    sta.push(k);
    num[k]++;        //该数字在栈中的数量加一
    block[k / sq]++; //该数字所属块含有的数字加一
}
void Pop()
{
    int a = sta.top();
    sta.pop();
    num[a]--;
    block[a / sq]--;
    cout << a << endl;
}
void PeekMedian()
{
    int rank;
    if (sta.size() % 2 == 0)
        rank = sta.size() / 2;
    else
        rank = (sta.size() + 1) / 2;
    int t = 0, i = 0;
    while (t < rank)
    {
        if (t + block[i] >= rank) //要找的在第i块
            break;
        t += block[i++];
    }
    int j = i * sq;
    while (t < rank)
    {
        if (t + num[j] >= rank) //要找的就是j
            break;
        t += num[j++]; //增加每个数字在栈中的数量
    }
    cout << j << endl;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s == "Push")
        {
            int key;
            cin >> key;
            Push(key);
        }
        else if (s == "Pop")
        {
            if (sta.empty())
                cout << "Invalid" << endl;
            else
                Pop();
        }
        else
        {
            if (sta.empty())
                cout << "Invalid" << endl;
            else
                PeekMedian();
        }
    }
    return 0;
}