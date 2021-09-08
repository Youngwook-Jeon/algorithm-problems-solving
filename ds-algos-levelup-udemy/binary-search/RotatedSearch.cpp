// 정렬된 배열을 로테이션 한 배열과 키가 주어졌을 때, 그 키값을 가지는 배열 원소의 인덱스 리턴
#include <iostream>
#include <vector>
using namespace std;

int rotated_search(vector<int> a, int key) {
    int n = a.size();
    int s = 0;
    int e = n - 1;

    while (s <= e) {
        int mid = (s + e) / 2;
        if (a[mid] == key) {
            return mid;
        } 

        if (a[s] <= a[mid]) {
            // left part
            if (key >= a[s] and key <= a[mid]) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        } else {
            // right part
            if (key >= a[mid] and key <= a[e]) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
    }
    return -1;
}

int main() {
    vector<int> a {4, 5, 6, 7, 0, 1, 2, 3};
    int key;
    cin >> key;
    cout << rotated_search(a, key) << endl;
    return 0;
}