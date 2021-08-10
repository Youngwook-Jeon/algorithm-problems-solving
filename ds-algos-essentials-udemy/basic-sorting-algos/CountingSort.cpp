#include <iostream>
#include <vector>
using namespace std;

// time-complexity: O(N + range)
void counting_sort(int a[], int n) {
    int largest = INT_MIN;
    for (int i = 0; i < n; i++) {
        largest = max(largest, a[i]);
    }

    vector<int> freq(largest + 1, 0);

    for (int i = 0; i < n; i++) {
        freq[a[i]]++;
    }

    // Put back the elements from freq into original array
    int j = 0;
    for (int i = 0; i <= largest; i++) {
        while (freq[i] > 0) {
            a[j] = i;
            freq[i]--;
            j++;
        }
    }
    return;
}

int main() {
    int arr[] = {2, 3, 4, 1, 5, 12, 6, 15, 9};
    int n = sizeof(arr) / sizeof(int);
    counting_sort(arr, n);

    for (auto x : arr) {
        cout << x << ",";
    }

    return 0;
}