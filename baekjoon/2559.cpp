// https://www.acmicpc.net/problem/2559
// 연속된 k일 동안의 최대가 되는 경우 그 최대값구하기
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

int n, k, mx;

int main() {
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < k; i++) {
        mx += arr[i];
    }
    int cur = mx;
    for (int i = 1; i < n - k + 1; i++) {
        cur = cur - arr[i - 1] + arr[i + k - 1];
        mx = max(mx, cur);
    }
    printf("%d", mx);
    return 0;
}