int a[100000];
const int n = 100;

int partition(int low, int high)
{
    int pivot = a[low];
    while (low < high)
    {
        while (low < high && pivot < a[high])
        {
            --high;
        }
        a[high] = a[low];
        while (low < high && pivot > a[low])
        {
            ++low;
        }
        a[low] = a[high];
    }
    a[low] = pivot;
    return low;
}

void quicksort(int low, int high)
{
    if (low < high)
    {
        int pivot = partition(low, high);
        quicksort(low, pivot - 1);
        quicksort(pivot + 1, high);
    }
}

int main()
{
}