#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &a, int s, int e) {
    int pivot = a[e];
    int i = s - 1; // 피봇보다 더 작은 원소 중 가장 마지막을 가리킴

    for (int j = s; j < e; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[e]);
    return i + 1;
}

void quicksort(vector<int> &a, int s, int e) {
    if (s >= e) return;

    int p = partition(a, s, e);
    quicksort(a, s, p - 1);
    quicksort(a, p + 1, e);
}

int main() {
    vector<int> arr {10, 5, 2, 0, 7, 6, 4};
    int s = 0;
    int e = arr.size() - 1;
    quicksort(arr, s, e);
    for (int x : arr) {
        cout << x << ",";
    }
    return 0;
}