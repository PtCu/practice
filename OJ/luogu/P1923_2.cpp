#include <bits/stdc++.h>
using namespace std;
vector<int> source;

//stl heap的练习
int getMin(int k)
{
    auto heap_begin = source.begin();
    auto heap_end = source.begin() + k;
    make_heap(heap_begin, heap_end, less<int>()); //建立大顶堆，保证堆顶元素为当前k个元素中最大的
    for (size_t i = k; i < source.size(); ++i)
    {
        //如果堆顶元素大于当前元素，说明当前堆顶元素必不是整个数组中第k小，一定比第k小的大
        if (*heap_begin > source[i])
        {
            //弹出堆顶
            pop_heap(heap_begin, heap_end);
            //替换末尾元素
            *prev(heap_end) = source[i];
            push_heap(heap_begin, heap_end);
        }
    }
    return *heap_begin;
}

//stl 优先队列的练习
int getMin2(int k)
{

    //此种建堆方法实际上为自上而下的上滤法建堆。建堆速度较慢。
    //每次插入操作为O(logn)，整体为O(nlogn)。
    //priority_queue<int, vector<int>, less<int>> heap;
    // for (size_t i = 0; i < k;++i){
    //     heap.push(source[i]);
    // }

    //此种方法实际上为Floyd的自下而上的下滤法建堆，建堆速度为O(n)
    priority_queue<int, vector<int>, less<int>> heap(source.begin(), source.begin() + k);
    for (size_t i = k; i < source.size(); ++i)
    {
        if (heap.top() > source[i])
        {
            heap.pop();
            heap.push(source[i]);
        }
    }
    return heap.top();
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    int x;
    for (size_t i = 0; i < n; ++i)
    {
        cin >> x;
        source.push_back(x);
    }
    cout << getMin2(k + 1);
}