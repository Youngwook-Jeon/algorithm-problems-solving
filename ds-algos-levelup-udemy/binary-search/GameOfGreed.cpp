// 코인의 값어치의 배열, 친구 수(자신 포함)가 주어졌음
// 이때 배열을 친구 수만큼의 세그먼트로 나누어, 친구들은 각 파티션의 모든 코인들을 가진다고 하자
// 친구들은 그리디하기때문에 가질 수 있는 금액 중 가장 큰 금액을 가지려한다
// 이때 내가 얻을 수 있는 가장 큰 금액을 구하기
#include <iostream>
#include <vector>
using namespace std;

bool canDivideAtLeastMid(vector<int> &arr, int n, int k, int val) {
    int cnt = 0;
    int cur_sum = 0;
    for (int i = 0; i < n; i++) {
        cur_sum += arr[i];
        if (cur_sum >= val) {
            cnt++;
            cur_sum = 0;
        }
    }
    return cnt >= k;
}


int getCoins(vector<int> arr, int k){
    //return the max coins that you can win!
    int n = arr.size();
    int s = 0, e = 0;
    int ans = 0;
    for (int num : arr) {
        e += num;
    }
    
    int mid;
    while (s <= e) {
        mid = (s + e) / 2;
        
        bool isPossible = canDivideAtLeastMid(arr, n, k, mid);
        if (isPossible) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return ans;
    
}