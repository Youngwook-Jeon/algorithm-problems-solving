// 배열과 어떤 수가 주어졌을 때 배열의 두 원소의 합이 그 수와 가장 가까울 경우 찾기
#include <iostream>
#include <vector>
using namespace std;

pair<int, int> closestSum(vector<int> arr, int x){
    // your code goes here
    int n = arr.size();
    int maxVal = INT_MAX;
    pair<int, int> ans;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (abs(arr[i] + arr[j] - x) < maxVal) {
                ans = make_pair(arr[i], arr[j]);
                maxVal = abs(arr[i] + arr[j] - x);
            }
        }
    }
    return ans;
}