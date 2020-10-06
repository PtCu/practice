// 描述
// 数轴上有n个点，对于任一闭区间[a, b] ，试计算落在其内的点数。

//     输入
//         第一行包括两个整数：点的总数n，查询的次数m。

//     第二行包含n个数，为各个点的坐标。

//     以下m行，各包含两个整数：查询区间的左、右边界a和b。

//     输出
//         对每次查询，输出落在闭区间[a, b] 内点的个数。

#include<stdio.h>

const int MAX = 5e5 + 10;

int n;
int points[MAX]; //单个n表示大小

void quicksort(int left, int right)
{
    if (left < right)
    {
        int i = left;
        int j = right;
        int pivot = points[i];
        while (i < j)
        {
            while ((i < j) && (points[j] > pivot))
                j--;
            if (i < j)
                points[i] = points[j];

            while ((i < j) && (points[i] <= pivot))
                i++;
            if (i < j)
                points[j] = points[i];
        }
        points[i] = pivot;
        quicksort(left, i - 1);
        quicksort(i + 1, right);
    }
}

// 二分查找算法（版本C）：在有序向量的区间[lo, hi)内查找元素e，0 <= lo <= hi <= _size
//参考教材的算法
int binarySearch(int lo, int high, int e)
{
    while (lo < high)
    {
        int m = (lo + high) >> 1;
        (e < points[m]) ? high = m : lo = m + 1;
    }
    return --lo;
} //循环结束时，lo为大于e的元素的最小秩，故lo - 1即不大于e的元素的最大秩

int query(int left, int right)
{
    int i, j;
    i = binarySearch(0, n, left - 1);   //返回严格小于left的最大元素下标（最大为left-1）
    j = binarySearch(0, n, right);      //返回<=right的最大元素下标
    return j - i;
}
int main()
{
    int m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        scanf("%d",&points[i]);
        
    }
    quicksort(0, n - 1);
    while (0 < m--)
    {
        int l, r;
        scanf("%d %d", &l,&r);
        printf("%d\n", query(l, r));
    }
}