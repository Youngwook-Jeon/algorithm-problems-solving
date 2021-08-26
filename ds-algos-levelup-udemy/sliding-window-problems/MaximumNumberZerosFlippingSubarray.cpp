// 주어진 0과 1로 이루어진 배열에서 어떤 서브배열 부분을 플립(1 -> 0, 0 ->1)하여 0의 갯수를 최대로 만들 때 0의 갯수 리턴
#include <iostream>
using namespace std;

// Kadane 알고리즘 기반
int findMaxZeroCount(bool arr[], int n) {
    int original_zeros = 0;
    // 모든 서브어레이에서 0과 1의 차가 최대일 때의 값을 저장
    int max_diff = 0;
    // 현 단계에서 0과 1의 차가 최대일 때의 값 저장
    int cur_max = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) original_zeros++;
        int val = (arr[i] == 1) ? 1 : -1;
        cur_max = max(val, cur_max + val);
        max_diff = max(max_diff, cur_max);
    }

    max_diff = max(0, max_diff);
    return original_zeros + max_diff;
}

int main() {
    bool arr[] = {0, 1, 0, 0, 1, 1, 0};
    int n = sizeof(arr) / sizeof(bool);
    cout << findMaxZeroCount(arr, n) << endl;
    return 0;
}