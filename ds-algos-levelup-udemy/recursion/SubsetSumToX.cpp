// 배열의 원소들을 더해서 X를 만들 수 있는지 여부를 확인하기
#include <iostream>
#include <vector>
using namespace std;

int countSubsets(vector<int> arr, int n, int i, int X) {
    if (i == n) {
        if (X == 0) {
            return 1;
        }
        return 0;
    }

    int inc = countSubsets(arr, n, i + 1, X - arr[i]);
    int exc = countSubsets(arr, n, i + 1, X);
    return inc + exc;
}

int main() {
    vector<int> arr {1, 2, 3, 4, 5};
    int X = 6;
    cout << countSubsets(arr, arr.size() - 1, 0, X) << endl;
    return 0;
}