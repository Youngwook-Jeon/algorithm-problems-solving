#include <iostream>
#include <vector>
using namespace std;

void bubble_sort(int a[], int n) {
    for (int times = 1; times <= n - 1; times++) {
        for (int j = 0; j <= n - times - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

vector<int> optimized_bubble_sort(vector<int> v){
    // your code  goes here
    int n = v.size();
    for (int times = 1; times <= n - 1; times++) {
        int swapped = 0;
        for (int i = 0; i <= n - times - 1; i++) {
            if (v[i] > v[i + 1]) {
                int temp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp;
                swapped++;
            }
        }
        
        if (swapped == 0) break;
    }
    return v;
}

int main() {
    int arr[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    int n = sizeof(arr) / sizeof(int);
    bubble_sort(arr, n);

    for (auto x : arr) {
        cout << x << ",";
    }

    return 0;
}