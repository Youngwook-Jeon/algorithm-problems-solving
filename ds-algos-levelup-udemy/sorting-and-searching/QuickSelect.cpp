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

int quickselect(vector<int> &a, int s, int e, int k) {
    int p = partition(a, s, e);
    if (p == k) {
        return a[p];
    } else if (k < p) {
        return quickselect(a, s, p - 1, k);
    } else {
        return quickselect(a, p + 1, e, k);
    }
}

int main() {
    vector<int> arr {10, 5, 2, 0, 7, 6, 4};
    int s = 0;
    int e = arr.size() - 1;
    cout << quickselect(arr, s, e, 4) << endl;
    
    return 0;
}