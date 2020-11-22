#include <iostream>
const int MAX = 4e6 + 1;
int n;
int axis_x[MAX];
int axis_y[MAX];
typedef long long ll;
void quickSort(int lo, int hi) //[lo,hi]
{
    if (lo < hi)
    {
        int i = lo, j = hi;
        int pivot = axis_x[i];
        int y = axis_y[i];
        while (i < j)
        {
            while ((i < j) && axis_x[j] > pivot)
                j--;
            if (i < j)
            {
                axis_x[i] = axis_x[j]; //j的数据放在i上
                std::swap(axis_y[j], axis_y[i]);
            }
            while ((i < j) && axis_x[i] <= pivot)
                i++;
            if (i < j)
            {
                axis_x[j] = axis_x[i];
                std::swap(axis_y[j], axis_y[i]);
            }
        }
        axis_x[i] = pivot;
        axis_y[i] = y;
        quickSort(lo, i - 1);
        quickSort(i + 1, hi);
    }
}
ll invBetween(int lo, int mi, int hi) //归并[lo,hi)
{
    ll seq_num = 0;
    int *A = axis_y + lo;
    int lb = mi - lo;
    int *B = new int[lb];        //B[0,lb)=_elem[lo,mi)
    for (int i = 0; i < lb; i++) //复制B段
        B[i] = A[i];
    int *C = axis_y + mi;
    int lc = hi - mi;
    for (int i = 0, j = 0, k = 0; j < lb;)
    {                               //i,j,k分别为A,B,C的指针
        if (C[k] <= B[j] && k < lc) //如果后半部分的元素比前面的小，就插入到前面去。相等的话不交换（保证稳定性）
        {
            A[i++] = C[k++];
        }
        else
        {
            A[i++] = B[j++];
            seq_num += lc - k; //记录顺序对数量（后半部分大于B[j]的元素都和C[k]形成顺序对）
        }
    }
    delete[] B;
    return seq_num;
}
ll invInside(int lo, int hi) //左闭右开[lo,hi)
{
    if (hi - lo < 2)
        return 0;
    else
    {
        int mi = (lo + hi) >> 1;
        ll left = invInside(lo, mi);
        ll right = invInside(mi, hi);
        ll cross = invBetween(lo, mi, hi);
        return left + right + cross;
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &axis_x[i], &axis_y[i]);
    }
    quickSort(0, n - 1);
    ll ans = invInside(0, n);
    printf("%lld", ans);
}