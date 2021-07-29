// 크기가 2 이상인 배열이 주어졌을 때, 어떤 부분만 재정렬하면 순서대로 정렬이 되게 하는 가장 작은 서브어레이 구하기
// 만약 주어진 배열이 이미 정렬되어있다면 [-1, -1]을 리턴하게 하라
// sample input: [1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11]
// output: [5, 7]
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool out_of_order(vector<int> arr, int i) {
    int x = arr[i];
    if (i == 0) {
        return x > arr[1];
    }
    if (i == arr.size() - 1) {
        return x < arr[i - 1];
    }
    return x > arr[i + 1] or x < arr[i - 1];
}

pair<int, int> subarray_sort(vector<int> arr) {
    int smallest = INT_MAX;
    int largest = INT_MIN;

    for (int i = 0; i < arr.size(); i++) {
        int x = arr[i];
        if (out_of_order(arr, i)) {
            smallest = min(smallest, x);
            largest = max(largest, x);
        }
    }

    // next step: find the right index where smallest and largest lie
    if (smallest == INT_MAX) {
        return { -1, -1 };
    }

    int left = 0;
    while (smallest >= arr[left]) {
        left++;
    }
    int right = arr.size() - 1;
    while (largest <= arr[right]) {
        right--;
    }

    return { left, right };
}

int main() {
    vector<int> arr = { 1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11};
    auto p = subarray_sort(arr);
    cout << p.first << " and " << p.second << endl;
    return 0;
}