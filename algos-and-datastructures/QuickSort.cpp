#include <iostream>
using namespace std;

int partition(int arr[], int start, int end)
{
    int pivot = arr[start];
    int cnt = 0;

    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
            cnt++;
    }

    int pivotInd = start + cnt;
    swap(arr[pivotInd], arr[start]);

    int i = start, j = end;
    while (i < pivotInd && j > pivotInd)
    {
        while (arr[i] <= pivot)
            i++;
        while (arr[j] > pivot)
            j--;

        if (i < pivotInd && j > pivotInd)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotInd;
}

void quickSort(int arr[], int start, int end)
{
    if (start >= end)
        return;

    int p = partition(arr, start, end);

    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
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