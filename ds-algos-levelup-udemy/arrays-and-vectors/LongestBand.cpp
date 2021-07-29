// N개의 정수들로 이루어진 배열이 주어졌을 때, 가장 긴 밴드의 길이 구하기
// 밴드란 그 배열의 서브시퀀스로, 순서대로 재정렬했을 때 연속된 수들로 이루어진 것
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// O(N) - time complexity
int longest_band(vector<int> arr) {
    int n = arr.size();
    unordered_set<int> s;

    for (int x : arr) {
        s.insert(x);
    }

    int largest_len = 1;

    for (auto elm : s) {
        int parent = elm - 1;
        if (s.find(parent) == s.end()) {
            int next_no = elm + 1;
            int cnt = 1;
            while (s.find(next_no) != s.end()) {
                next_no++;
                cnt++;
            }

            if (cnt > largest_len) {
                largest_len = cnt;
            }
        }
    }

    return largest_len;
}

int main() {
    vector<int> arr{1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6};
    cout << longest_band(arr) << endl; // 8
    return 0;
}