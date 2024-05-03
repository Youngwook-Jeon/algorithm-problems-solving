#include <iostream>
#include <algorithm>
using namespace std;

int partition(int arr[], int start, int end)
{
    int pivot = arr[start];
    int l = start - 1, h = end + 1;
    while (true)
    {
        do
        {
            l++;
        } while (arr[l] < pivot);

        do
        {
            h--;
        } while (arr[h] > pivot);
        if (l >= h)
            return h;
        swap(arr[l], arr[h]);
    }
}

void quickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int p = partition(arr, start, end);

        quickSort(arr, start, p);
        quickSort(arr, p + 1, end);
    }
}

int main()
{
    int arr[] = {5, 2, 7, 9, 0, 1};
    quickSort(arr, 0, 5);

    for (int num : arr)
    {
        cout << num << ' ';
    }
    return 0;
}