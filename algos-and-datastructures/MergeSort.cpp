#include <climits>
#include <cstring>
#include <iostream>
using namespace std;

void Merge(int *arr, int p, int m, int q)
{
    int *left, *right;
    int n1, n2, i, j, k;
    n1 = m - p + 1;
    n2 = q - m;
    left = new int[n1 + 1];
    right = new int[n2 + 1];

    memcpy(left, arr + p, n1 * sizeof(int));
    memcpy(right, arr + m + 1, n2 * sizeof(int));
    left[n1] = INT_MAX;
    right[n2] = INT_MAX;

    for (int k = p, i = 0, j = 0; k <= q; k++)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i++];
        }
        else
        {
            arr[k] = right[j++];
        }
    }

    delete[] left;
    delete[] right;
}

void MergeSort(int *arr, int p, int q)
{
    if (p >= q)
        return;

    int m = (p + q) / 2;

    MergeSort(arr, p, m);
    MergeSort(arr, m + 1, q);
    Merge(arr, p, m, q);
}

int main()
{
    int arr[] = {5, 3, 4, 10, 6, 7, 8, 1, 9, 2};
    MergeSort(arr, 0, 9);
    for (auto i : arr)
    {
        cout << i << ',';
    }
    return 0;
}